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

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.TimeUnit;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.hbase.HRegionInfo;
import org.apache.hadoop.hbase.ScheduledChore;
import org.apache.hadoop.hbase.classification.InterfaceAudience;
import org.apache.hadoop.hbase.regionserver.HRegion;
import org.apache.hadoop.hbase.regionserver.HRegionServer;
import org.apache.hadoop.hbase.regionserver.Region;
import org.apache.hadoop.hbase.regionserver.Store;
import org.apache.hadoop.hbase.util.EnvironmentEdgeManager;

/**
 * A chore which computes the size of each {@link HRegion} on the FileSystem hosted by the given {@link HRegionServer}.
 */
@InterfaceAudience.Private
public class FileSystemUtilizationChore extends ScheduledChore {
  private static final Log LOG = LogFactory.getLog(FileSystemUtilizationChore.class);
  static final String FS_UTILIZATION_CHORE_PERIOD_KEY = "hbase.regionserver.quotas.fs.utilization.chore.period";
  static final int FS_UTILIZATION_CHORE_PERIOD_DEFAULT = 1000 * 60 * 5; // 5 minutes in millis

  static final String FS_UTILIZATION_CHORE_DELAY_KEY = "hbase.regionserver.quotas.fs.utilization.chore.delay";
  static final long FS_UTILIZATION_CHORE_DELAY_DEFAULT = 1000L * 60L; // 1 minute

  static final String FS_UTILIZATION_CHORE_TIMEUNIT_KEY = "hbase.regionserver.quotas.fs.utilization.chore.timeunit";
  static final String FS_UTILIZATION_CHORE_TIMEUNIT_DEFAULT = TimeUnit.MILLISECONDS.name();

  static final String FS_UTILIZATION_MAX_ITERATION_DURATION_KEY = "hbase.regionserver.quotas.fs.utilization.chore.max.iteration.millis";
  static final long FS_UTILIZATION_MAX_ITERATION_DURATION_DEFAULT = 5000L;

  private final HRegionServer rs;
  private final long maxIterationMillis;
  private Iterator<Region> leftoverRegions;

  public FileSystemUtilizationChore(HRegionServer rs) {
    super(FileSystemUtilizationChore.class.getSimpleName(), rs, getPeriod(rs.getConfiguration()),
        getInitialDelay(rs.getConfiguration()), getTimeUnit(rs.getConfiguration()));
    this.rs = rs;
    this.maxIterationMillis = rs.getConfiguration().getLong(
        FS_UTILIZATION_MAX_ITERATION_DURATION_KEY, FS_UTILIZATION_MAX_ITERATION_DURATION_DEFAULT);
  }

  @Override
  protected void chore() {
    final Map<HRegionInfo,Long> onlineRegionSizes = new HashMap<>();
    final Set<Region> onlineRegions = new HashSet<>(rs.getOnlineRegions());
    // Process the regions from the last run if we have any. If we are somehow having difficulty
    // processing the Regions, we want to avoid creating a backlog in memory of Region objs.
    Iterator<Region> oldRegionsToProcess = getLeftoverRegions();
    final Iterator<Region> iterator;
    final boolean processingLeftovers;
    if (null == oldRegionsToProcess) {
      iterator = onlineRegions.iterator();
      processingLeftovers = false;
    } else {
      iterator = oldRegionsToProcess;
      processingLeftovers = true;
    }
    // Reset the leftoverRegions and let the loop re-assign if necessary.
    setLeftoverRegions(null);
    long regionSizesCalculated = 0L;
    long offlineRegionsSkipped = 0L;
    long skippedSplitParents = 0L;
    long skippedRegionReplicas = 0L;
    final long start = EnvironmentEdgeManager.currentTime();
    while (iterator.hasNext()) {
      // Make sure this chore doesn't hog the thread.
      long timeRunning = EnvironmentEdgeManager.currentTime() - start;
      if (timeRunning > maxIterationMillis) {
        LOG.debug("Preempting execution of FileSystemUtilizationChore because it exceeds the"
            + " maximum iteration configuration value. Will process remaining iterators"
            + " on a subsequent invocation.");
        setLeftoverRegions(iterator);
        break;
      }

      final Region region = iterator.next();
      // If we're processing leftover regions, the region may no-longer be online.
      // If so, we can can skip it.
      if (processingLeftovers && !onlineRegions.contains(region)) {
        offlineRegionsSkipped++;
        continue;
      }
      // Avoid computing the size of regions which are the parent of split.
      if (region.getRegionInfo().isSplitParent()) {
        skippedSplitParents++;
        continue;
      }
      // Avoid computing the size of region replicas.
      if (HRegionInfo.DEFAULT_REPLICA_ID != region.getRegionInfo().getReplicaId()) {
        skippedRegionReplicas++;
        continue;
      }
      final long sizeInBytes = computeSize(region);
      onlineRegionSizes.put(region.getRegionInfo(), sizeInBytes);
      regionSizesCalculated++;
    }
    if (LOG.isTraceEnabled()) {
      LOG.trace("Computed the size of " + regionSizesCalculated + " Regions. Skipped computation"
          + " of " + offlineRegionsSkipped + " regions due to not being online on this RS, "
          + skippedSplitParents + " regions due to being the parent of a split, and"
          + skippedRegionReplicas + " regions due to being region replicas.");
    }
    reportRegionSizesToMaster(onlineRegionSizes);
  }

  /**
   * Returns an {@link Iterator} over the Regions which were skipped last invocation of the chore.
   *
   * @return Regions from the previous invocation to process, or null.
   */
  Iterator<Region> getLeftoverRegions() {
    return leftoverRegions;
  }

  /**
   * Sets a new collection of Regions as leftovers.
   */
  void setLeftoverRegions(Iterator<Region> newLeftovers) {
    this.leftoverRegions = newLeftovers;
  }

  /**
   * Computes total FileSystem size for the given {@link Region}.
   *
   * @param r The region
   * @return The size, in bytes, of the Region.
   */
  long computeSize(Region r) {
    long regionSize = 0L;
    for (Store store : r.getStores()) {
      // StoreFile/StoreFileReaders are already instantiated with the file length cached.
      // Can avoid extra NN ops.
      regionSize += store.getStorefilesSize();
    }
    return regionSize;
  }

  /**
   * Reports the computed region sizes to the currently active Master.
   *
   * @param onlineRegionSizes The computed region sizes to report.
   */
  void reportRegionSizesToMaster(Map<HRegionInfo,Long> onlineRegionSizes) {
    this.rs.reportRegionSizesForQuotas(onlineRegionSizes);
  }

  /**
   * Extracts the period for the chore from the configuration.
   *
   * @param conf The configuration object.
   * @return The configured chore period or the default value.
   */
  static int getPeriod(Configuration conf) {
    return conf.getInt(FS_UTILIZATION_CHORE_PERIOD_KEY, FS_UTILIZATION_CHORE_PERIOD_DEFAULT);
  }

  /**
   * Extracts the initial delay for the chore from the configuration.
   *
   * @param conf The configuration object.
   * @return The configured chore initial delay or the default value.
   */
  static long getInitialDelay(Configuration conf) {
    return conf.getLong(FS_UTILIZATION_CHORE_DELAY_KEY, FS_UTILIZATION_CHORE_DELAY_DEFAULT);
  }

  /**
   * Extracts the time unit for the chore period and initial delay from the configuration. The
   * configuration value for {@link #FS_UTILIZATION_CHORE_TIMEUNIT_KEY} must correspond to a
   * {@link TimeUnit} value.
   *
   * @param conf The configuration object.
   * @return The configured time unit for the chore period and initial delay or the default value.
   */
  static TimeUnit getTimeUnit(Configuration conf) {
    return TimeUnit.valueOf(conf.get(FS_UTILIZATION_CHORE_TIMEUNIT_KEY,
        FS_UTILIZATION_CHORE_TIMEUNIT_DEFAULT));
  }
}
