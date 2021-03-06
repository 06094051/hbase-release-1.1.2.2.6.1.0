/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to you under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package org.apache.hadoop.hbase.quotas;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;

import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicLong;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.hbase.HBaseTestingUtility;
import org.apache.hadoop.hbase.HRegionInfo;
import org.apache.hadoop.hbase.NamespaceDescriptor;
import org.apache.hadoop.hbase.NamespaceNotFoundException;
import org.apache.hadoop.hbase.TableName;
import org.apache.hadoop.hbase.client.Admin;
import org.apache.hadoop.hbase.client.Connection;
import org.apache.hadoop.hbase.master.HMaster;
import org.apache.hadoop.hbase.quotas.QuotaObserverChore.TablesWithQuotas;
import org.apache.hadoop.hbase.protobuf.generated.QuotaProtos.SpaceQuota;
import org.apache.hadoop.hbase.testclassification.LargeTests;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Rule;
import org.junit.Test;
import org.junit.experimental.categories.Category;
import org.junit.rules.TestName;

import com.google.common.collect.Iterables;
import com.google.common.collect.Multimap;

/**
 * Test class for {@link QuotaObserverChore} that uses a live HBase cluster.
 */
@Category(LargeTests.class)
public class TestQuotaObserverChoreWithMiniCluster {
  private static final Log LOG = LogFactory.getLog(TestQuotaObserverChoreWithMiniCluster.class);
  private static final HBaseTestingUtility TEST_UTIL = new HBaseTestingUtility();
  private static final AtomicLong COUNTER = new AtomicLong(0);

  @Rule
  public TestName testName = new TestName();

  private HMaster master;
  private QuotaObserverChore chore;
  private SpaceQuotaSnapshotNotifierForTest snapshotNotifier;
  private SpaceQuotaHelperForTests helper;

  @BeforeClass
  public static void setUp() throws Exception {
    Configuration conf = TEST_UTIL.getConfiguration();
    conf.setInt(FileSystemUtilizationChore.FS_UTILIZATION_CHORE_DELAY_KEY, 1000);
    conf.setInt(FileSystemUtilizationChore.FS_UTILIZATION_CHORE_PERIOD_KEY, 1000);
    conf.setInt(QuotaObserverChore.VIOLATION_OBSERVER_CHORE_DELAY_KEY, 1000);
    conf.setInt(QuotaObserverChore.VIOLATION_OBSERVER_CHORE_PERIOD_KEY, 1000);
    conf.setBoolean(QuotaUtil.QUOTA_CONF_KEY, true);
    conf.setClass(SpaceQuotaSnapshotNotifierFactory.SNAPSHOT_NOTIFIER_KEY,
        SpaceQuotaSnapshotNotifierForTest.class, SpaceQuotaSnapshotNotifier.class);
    TEST_UTIL.startMiniCluster(1);
  }

  @AfterClass
  public static void tearDown() throws Exception {
    TEST_UTIL.shutdownMiniCluster();
  }

  @Before
  public void removeAllQuotas() throws Exception {
    final Connection conn = TEST_UTIL.getConnection();
    // Wait for the quota table to be created
    if (!conn.getAdmin().tableExists(QuotaUtil.QUOTA_TABLE_NAME)) {
      do {
        LOG.debug("Quota table does not yet exist");
        Thread.sleep(1000);
      } while (!conn.getAdmin().tableExists(QuotaUtil.QUOTA_TABLE_NAME));
    } else {
      // Or, clean up any quotas from previous test runs.
      QuotaRetriever scanner = QuotaRetriever.open(TEST_UTIL.getConfiguration());
      for (QuotaSettings quotaSettings : scanner) {
        final String namespace = quotaSettings.getNamespace();
        final TableName tableName = quotaSettings.getTableName();
        if (null != namespace) {
          LOG.debug("Deleting quota for namespace: " + namespace);
          QuotaUtil.deleteNamespaceQuota(conn, namespace);
        } else {
          assert null != tableName;
          LOG.debug("Deleting quota for table: "+ tableName);
          QuotaUtil.deleteTableQuota(conn, tableName);
        }
      }
    }

    master = TEST_UTIL.getMiniHBaseCluster().getMaster();
    snapshotNotifier =
        (SpaceQuotaSnapshotNotifierForTest) master.getSpaceQuotaViolationNotifier();
    snapshotNotifier.clearSnapshots();
    chore = master.getQuotaObserverChore();
    helper = new SpaceQuotaHelperForTests(TEST_UTIL, testName, COUNTER);
  }

  @Test
  public void testTableViolatesQuota() throws Exception {
    TableName tn = helper.createTableWithRegions(10);

    final long sizeLimit = 2L * SpaceQuotaHelperForTests.ONE_MEGABYTE;
    final SpaceViolationPolicy violationPolicy = SpaceViolationPolicy.NO_INSERTS;
    QuotaSettings settings = QuotaSettingsFactory.limitTableSpace(tn, sizeLimit, violationPolicy);
    TEST_UTIL.getHBaseAdmin().setQuota(settings);

    // Write more data than should be allowed
    helper.writeData(tn, 3L * SpaceQuotaHelperForTests.ONE_MEGABYTE);

    Map<TableName,SpaceQuotaSnapshot> quotaSnapshots = snapshotNotifier.copySnapshots();
    boolean foundSnapshot = false;
    while (!foundSnapshot) {
      if (quotaSnapshots.isEmpty()) {
        LOG.info("Found no violated quotas, sleeping and retrying. Current reports: "
            + master.getMasterQuotaManager().snapshotRegionSizes());
        sleepWithInterrupt(1000);
        quotaSnapshots = snapshotNotifier.copySnapshots();
      } else {
        Entry<TableName,SpaceQuotaSnapshot> entry = Iterables.getOnlyElement(quotaSnapshots.entrySet());
        assertEquals(tn, entry.getKey());
        final SpaceQuotaSnapshot snapshot = entry.getValue();
        if (!snapshot.getQuotaStatus().isInViolation()) {
          LOG.info("Found a snapshot, but it was not yet in violation. " + snapshot);
          sleepWithInterrupt(1000);
          quotaSnapshots = snapshotNotifier.copySnapshots();
        } else {
          foundSnapshot = true;
        }
      }
    }

    Entry<TableName,SpaceQuotaSnapshot> entry = Iterables.getOnlyElement(quotaSnapshots.entrySet());
    assertEquals(tn, entry.getKey());
    final SpaceQuotaSnapshot snapshot = entry.getValue();
    assertEquals("Snapshot was " + snapshot, violationPolicy, snapshot.getQuotaStatus().getPolicy());
    assertEquals(sizeLimit, snapshot.getLimit());
    assertTrue(
        "The usage should be greater than the limit, but were " + snapshot.getUsage() + " and "
        + snapshot.getLimit() + ", respectively", snapshot.getUsage() > snapshot.getLimit());
  }

  @Test
  public void testNamespaceViolatesQuota() throws Exception {
    final String namespace = testName.getMethodName();
    final Admin admin = TEST_UTIL.getHBaseAdmin();
    // Ensure the namespace exists
    try {
      admin.getNamespaceDescriptor(namespace);
    } catch (NamespaceNotFoundException e) {
      NamespaceDescriptor desc = NamespaceDescriptor.create(namespace).build();
      admin.createNamespace(desc);
    }

    TableName tn1 = helper.createTableWithRegions(namespace, 5);
    TableName tn2 = helper.createTableWithRegions(namespace, 5);
    TableName tn3 = helper.createTableWithRegions(namespace, 5);

    final long sizeLimit = 5L * SpaceQuotaHelperForTests.ONE_MEGABYTE;
    final SpaceViolationPolicy violationPolicy = SpaceViolationPolicy.DISABLE;
    QuotaSettings settings = QuotaSettingsFactory.limitNamespaceSpace(namespace, sizeLimit, violationPolicy);
    admin.setQuota(settings);

    helper.writeData(tn1, 2L * SpaceQuotaHelperForTests.ONE_MEGABYTE);
    admin.flush(tn1);
    Map<TableName,SpaceQuotaSnapshot> snapshots = snapshotNotifier.copySnapshots();
    for (int i = 0; i < 5; i++) {
      // Check a few times to make sure we don't prematurely move to violation
      assertEquals(
          "Should not see any quota violations after writing 2MB of data: " + snapshots, 0,
          numQuotaSnapshotsInViolation(snapshots));
      try {
        Thread.sleep(1000);
      } catch (InterruptedException e) {
        LOG.debug("Interrupted while sleeping." , e);
      }
      snapshots = snapshotNotifier.copySnapshots();
    }

    helper.writeData(tn2, 2L * SpaceQuotaHelperForTests.ONE_MEGABYTE);
    admin.flush(tn2);
    snapshots = snapshotNotifier.copySnapshots();
    for (int i = 0; i < 5; i++) {
      // Check a few times to make sure we don't prematurely move to violation
      assertEquals("Should not see any quota violations after writing 4MB of data", 0,
          numQuotaSnapshotsInViolation(snapshots));
      try {
        Thread.sleep(1000);
      } catch (InterruptedException e) {
        LOG.debug("Interrupted while sleeping." , e);
      }
      snapshots = snapshotNotifier.copySnapshots();
    }

    // Writing the final 2MB of data will push the namespace over the 5MB limit (6MB in total)
    // and should push all three tables in the namespace into violation.
    helper.writeData(tn3, 2L * SpaceQuotaHelperForTests.ONE_MEGABYTE);
    admin.flush(tn3);
    snapshots = snapshotNotifier.copySnapshots();
    while (numQuotaSnapshotsInViolation(snapshots) < 3) {
      LOG.debug("Saw fewer violations than desired (expected 3): " + snapshots
          + ". Current reports: " + master.getMasterQuotaManager().snapshotRegionSizes());
      try {
        Thread.sleep(1000);
      } catch (InterruptedException e) {
        LOG.debug("Interrupted while sleeping.", e);
        Thread.currentThread().interrupt();
      }
      snapshots = snapshotNotifier.copySnapshots();
    }

    SpaceQuotaSnapshot snapshot1 = snapshots.remove(tn1);
    assertNotNull("tn1 should be in violation", snapshot1);
    assertEquals(violationPolicy, snapshot1.getQuotaStatus().getPolicy());
    SpaceQuotaSnapshot snapshot2 = snapshots.remove(tn2);
    assertNotNull("tn2 should be in violation", snapshot2);
    assertEquals(violationPolicy, snapshot2.getQuotaStatus().getPolicy());
    SpaceQuotaSnapshot snapshot3 = snapshots.remove(tn3);
    assertNotNull("tn3 should be in violation", snapshot3);
    assertEquals(violationPolicy, snapshot3.getQuotaStatus().getPolicy());
    assertTrue("Unexpected additional quota violations: " + snapshots, snapshots.isEmpty());
  }

  @Test
  public void testTableQuotaOverridesNamespaceQuota() throws Exception {
    final String namespace = testName.getMethodName();
    final Admin admin = TEST_UTIL.getHBaseAdmin();
    // Ensure the namespace exists
    try {
      admin.getNamespaceDescriptor(namespace);
    } catch (NamespaceNotFoundException e) {
      NamespaceDescriptor desc = NamespaceDescriptor.create(namespace).build();
      admin.createNamespace(desc);
    }

    TableName tn1 = helper.createTableWithRegions(namespace, 5);
    TableName tn2 = helper.createTableWithRegions(namespace, 5);

    final long namespaceSizeLimit = 3L * SpaceQuotaHelperForTests.ONE_MEGABYTE;
    final SpaceViolationPolicy namespaceViolationPolicy = SpaceViolationPolicy.DISABLE;
    QuotaSettings namespaceSettings = QuotaSettingsFactory.limitNamespaceSpace(namespace,
        namespaceSizeLimit, namespaceViolationPolicy);
    admin.setQuota(namespaceSettings);

    helper.writeData(tn1, 2L * SpaceQuotaHelperForTests.ONE_MEGABYTE);
    admin.flush(tn1);
    Map<TableName,SpaceQuotaSnapshot> violatedQuotas = snapshotNotifier.copySnapshots();
    for (int i = 0; i < 5; i++) {
      // Check a few times to make sure we don't prematurely move to violation
      assertEquals("Should not see any quota violations after writing 2MB of data: " + violatedQuotas, 0,
          numQuotaSnapshotsInViolation(violatedQuotas));
      try {
        Thread.sleep(1000);
      } catch (InterruptedException e) {
        LOG.debug("Interrupted while sleeping." , e);
      }
      violatedQuotas = snapshotNotifier.copySnapshots();
    }

    helper.writeData(tn2, 2L * SpaceQuotaHelperForTests.ONE_MEGABYTE);
    admin.flush(tn2);
    violatedQuotas = snapshotNotifier.copySnapshots();
    while (numQuotaSnapshotsInViolation(violatedQuotas) < 2) {
      LOG.debug("Saw fewer violations than desired (expected 2): " + violatedQuotas
          + ". Current reports: " + master.getMasterQuotaManager().snapshotRegionSizes());
      try {
        Thread.sleep(1000);
      } catch (InterruptedException e) {
        LOG.debug("Interrupted while sleeping.", e);
        Thread.currentThread().interrupt();
      }
      violatedQuotas = snapshotNotifier.copySnapshots();
    }

    SpaceQuotaSnapshot actualPolicyTN1 = violatedQuotas.get(tn1);
    assertNotNull("Expected to see violation policy for tn1", actualPolicyTN1);
    assertEquals(namespaceViolationPolicy, actualPolicyTN1.getQuotaStatus().getPolicy());
    SpaceQuotaSnapshot actualPolicyTN2 = violatedQuotas.get(tn2);
    assertNotNull("Expected to see violation policy for tn2", actualPolicyTN2);
    assertEquals(namespaceViolationPolicy, actualPolicyTN2.getQuotaStatus().getPolicy());

    // Override the namespace quota with a table quota
    final long tableSizeLimit = SpaceQuotaHelperForTests.ONE_MEGABYTE;
    final SpaceViolationPolicy tableViolationPolicy = SpaceViolationPolicy.NO_INSERTS;
    QuotaSettings tableSettings = QuotaSettingsFactory.limitTableSpace(tn1, tableSizeLimit,
        tableViolationPolicy);
    admin.setQuota(tableSettings);

    // Keep checking for the table quota policy to override the namespace quota
    while (true) {
      violatedQuotas = snapshotNotifier.copySnapshots();
      SpaceQuotaSnapshot actualTableSnapshot = violatedQuotas.get(tn1);
      assertNotNull("Violation policy should never be null", actualTableSnapshot);
      if (tableViolationPolicy != actualTableSnapshot.getQuotaStatus().getPolicy()) {
        LOG.debug("Saw unexpected table violation policy, waiting and re-checking.");
        try {
          Thread.sleep(1000);
        } catch (InterruptedException e) {
          LOG.debug("Interrupted while sleeping");
          Thread.currentThread().interrupt();
        }
        continue;
      }
      assertEquals(tableViolationPolicy, actualTableSnapshot.getQuotaStatus().getPolicy());
      break;
    }

    // This should not change with the introduction of the table quota for tn1
    actualPolicyTN2 = violatedQuotas.get(tn2);
    assertNotNull("Expected to see violation policy for tn2", actualPolicyTN2);
    assertEquals(namespaceViolationPolicy, actualPolicyTN2.getQuotaStatus().getPolicy());
  }

  @Test
  public void testGetAllTablesWithQuotas() throws Exception {
    final Multimap<TableName, QuotaSettings> quotas = helper.createTablesWithSpaceQuotas();
    Set<TableName> tablesWithQuotas = new HashSet<>();
    Set<TableName> namespaceTablesWithQuotas = new HashSet<>();
    // Partition the tables with quotas by table and ns quota
    helper.partitionTablesByQuotaTarget(quotas, tablesWithQuotas, namespaceTablesWithQuotas);

    TablesWithQuotas tables = chore.fetchAllTablesWithQuotasDefined();
    assertEquals("Found tables: " + tables, tablesWithQuotas, tables.getTableQuotaTables());
    assertEquals("Found tables: " + tables, namespaceTablesWithQuotas, tables.getNamespaceQuotaTables());
  }

  @Test
  public void testRpcQuotaTablesAreFiltered() throws Exception {
    final Multimap<TableName, QuotaSettings> quotas = helper.createTablesWithSpaceQuotas();
    Set<TableName> tablesWithQuotas = new HashSet<>();
    Set<TableName> namespaceTablesWithQuotas = new HashSet<>();
    // Partition the tables with quotas by table and ns quota
    helper.partitionTablesByQuotaTarget(quotas, tablesWithQuotas, namespaceTablesWithQuotas);

    TableName rpcQuotaTable = helper.createTable();
    TEST_UTIL.getHBaseAdmin().setQuota(QuotaSettingsFactory
      .throttleTable(rpcQuotaTable, ThrottleType.READ_NUMBER, 6, TimeUnit.MINUTES));

    // The `rpcQuotaTable` should not be included in this Set
    TablesWithQuotas tables = chore.fetchAllTablesWithQuotasDefined();
    assertEquals("Found tables: " + tables, tablesWithQuotas, tables.getTableQuotaTables());
    assertEquals("Found tables: " + tables, namespaceTablesWithQuotas, tables.getNamespaceQuotaTables());
  }

  @Test
  public void testFilterRegions() throws Exception {
    final Map<TableName,Integer> mockReportedRegions = new HashMap<>();
    // Can't mock because of primitive int as a return type -- Mockito
    // can only handle an Integer.
    TablesWithQuotas tables = new TablesWithQuotas(TEST_UTIL.getConnection(),
        TEST_UTIL.getConfiguration()) {
      @Override
      int getNumReportedRegions(TableName table, QuotaSnapshotStore<TableName> tableStore) {
        Integer i = mockReportedRegions.get(table);
        if (null == i) {
          return 0;
        }
        return i;
      }
    };

    // Create the tables
    TableName tn1 = helper.createTableWithRegions(20);
    TableName tn2 = helper.createTableWithRegions(20);
    TableName tn3 = helper.createTableWithRegions(20);

    // Add them to the Tables with Quotas object
    tables.addTableQuotaTable(tn1);
    tables.addTableQuotaTable(tn2);
    tables.addTableQuotaTable(tn3);

    // Mock the number of regions reported
    mockReportedRegions.put(tn1, 10); // 50%
    mockReportedRegions.put(tn2, 19); // 95%
    mockReportedRegions.put(tn3, 20); // 100%

    // Argument is un-used
    tables.filterInsufficientlyReportedTables(null);
    // The default of 95% reported should prevent tn1 from appearing
    assertEquals(new HashSet<>(Arrays.asList(tn2, tn3)), tables.getTableQuotaTables());
  }

  @Test
  public void testFetchSpaceQuota() throws Exception {
    Multimap<TableName,QuotaSettings> tables = helper.createTablesWithSpaceQuotas();
    // Can pass in an empty map, we're not consulting it.
    chore.initializeViolationStores(Collections.<HRegionInfo,Long> emptyMap());
    // All tables that were created should have a quota defined.
    for (Entry<TableName,QuotaSettings> entry : tables.entries()) {
      final TableName table = entry.getKey();
      final QuotaSettings qs = entry.getValue();

      assertTrue("QuotaSettings was an instance of " + qs.getClass(),
          qs instanceof SpaceLimitSettings);

      SpaceQuota spaceQuota = null;
      if (null != qs.getTableName()) {
        spaceQuota = chore.getTableViolationStore().getSpaceQuota(table);
        assertNotNull("Could not find table space quota for " + table, spaceQuota);
      } else if (null != qs.getNamespace()) {
        spaceQuota = chore.getNamespaceViolationStore().getSpaceQuota(table.getNamespaceAsString());
        assertNotNull("Could not find namespace space quota for " + table.getNamespaceAsString(), spaceQuota);
      } else {
        fail("Expected table or namespace space quota");
      }

      final SpaceLimitSettings sls = (SpaceLimitSettings) qs;
      assertEquals(sls.getProto().getQuota(), spaceQuota);
    }

    TableName tableWithoutQuota = helper.createTable();
    assertNull(chore.getTableViolationStore().getSpaceQuota(tableWithoutQuota));
  }

  private int numQuotaSnapshotsInViolation(Map<TableName,SpaceQuotaSnapshot> snapshots) {
    int sum = 0;
    for (SpaceQuotaSnapshot snapshot : snapshots.values()) {
      if (snapshot.getQuotaStatus().isInViolation()) {
        sum++;
      }
    }
    return sum;
  }

  private void sleepWithInterrupt(long millis) {
    try {
      Thread.sleep(millis);
    } catch (InterruptedException e) {
      LOG.debug("Interrupted while sleeping");
      Thread.currentThread().interrupt();
    }
  }
}
