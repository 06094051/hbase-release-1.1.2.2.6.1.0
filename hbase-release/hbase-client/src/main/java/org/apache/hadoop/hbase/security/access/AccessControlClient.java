/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package org.apache.hadoop.hbase.security.access;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.hbase.HConstants;
import org.apache.hadoop.hbase.HTableDescriptor;
import org.apache.hadoop.hbase.MasterNotRunningException;
import org.apache.hadoop.hbase.NamespaceDescriptor;
import org.apache.hadoop.hbase.TableName;
import org.apache.hadoop.hbase.ZooKeeperConnectionException;
import org.apache.hadoop.hbase.classification.InterfaceAudience;
import org.apache.hadoop.hbase.classification.InterfaceStability;
import org.apache.hadoop.hbase.client.Admin;
import org.apache.hadoop.hbase.client.ClusterConnection;
import org.apache.hadoop.hbase.client.Connection;
import org.apache.hadoop.hbase.client.ConnectionFactory;
import org.apache.hadoop.hbase.client.Table;
import org.apache.hadoop.hbase.ipc.CoprocessorRpcChannel;
import org.apache.hadoop.hbase.ipc.PayloadCarryingRpcController;
import org.apache.hadoop.hbase.protobuf.ProtobufUtil;
import org.apache.hadoop.hbase.protobuf.generated.AccessControlProtos;
import org.apache.hadoop.hbase.protobuf.generated.AccessControlProtos.AccessControlService.BlockingInterface;
import org.apache.hadoop.hbase.util.Bytes;

/**
 * Utility client for doing access control admin operations.
 */
@InterfaceAudience.Public
@InterfaceStability.Evolving
public class AccessControlClient {
  public static final TableName ACL_TABLE_NAME =
      TableName.valueOf(NamespaceDescriptor.SYSTEM_NAMESPACE_NAME_STR, "acl");

  private static BlockingInterface getAccessControlServiceStub(Table ht)
      throws IOException {
    CoprocessorRpcChannel service = ht.coprocessorService(HConstants.EMPTY_START_ROW);
    BlockingInterface protocol =
        AccessControlProtos.AccessControlService.newBlockingStub(service);
    return protocol;
  }

  /**
   * Grants permission on the specified table for the specified user
   * @param connection The Connection instance to use
   * @param tableName
   * @param userName
   * @param family
   * @param qual
   * @param actions
   * @throws Throwable
   */
  public static void grant(final Connection connection, final TableName tableName,
      final String userName, final byte[] family, final byte[] qual,
      final Permission.Action... actions) throws Throwable {
    PayloadCarryingRpcController controller
      = ((ClusterConnection) connection).getRpcControllerFactory().newController();
    controller.setPriority(tableName);
    try (Table table = connection.getTable(ACL_TABLE_NAME)) {
      ProtobufUtil.grant(controller, getAccessControlServiceStub(table), userName, tableName,
        family, qual, actions);
    }
  }

  /**
   * Grants permission on the specified namespace for the specified user.
   * @param connection The Connection instance to use
   * @param namespace
   * @param userName
   * @param actions
   * @throws Throwable
   */
  public static void grant(final Connection connection, final String namespace,
      final String userName, final Permission.Action... actions) throws Throwable {
    PayloadCarryingRpcController controller
      = ((ClusterConnection) connection).getRpcControllerFactory().newController();

    try (Table table = connection.getTable(ACL_TABLE_NAME)) {
      ProtobufUtil.grant(controller, getAccessControlServiceStub(table), userName, namespace,
        actions);
    }
  }

  /**
   * @param connection The Connection instance to use
   * Grant global permissions for the specified user.
   */
  public static void grant(final Connection connection, final String userName,
       final Permission.Action... actions) throws Throwable {
    PayloadCarryingRpcController controller
      = ((ClusterConnection) connection).getRpcControllerFactory().newController();
    try (Table table = connection.getTable(ACL_TABLE_NAME)) {
      ProtobufUtil.grant(controller, getAccessControlServiceStub(table), userName, actions);
    }
  }

  public static boolean isAccessControllerRunning(final Connection connection)
      throws MasterNotRunningException, ZooKeeperConnectionException, IOException {
    try (Admin admin = connection.getAdmin()) {
      return admin.isTableAvailable(ACL_TABLE_NAME);
    }
  }

  /**
   * Revokes the permission on the table
   * @param connection The Connection instance to use
   * @param tableName
   * @param username
   * @param family
   * @param qualifier
   * @param actions
   * @throws Throwable
   */
  public static void revoke(final Connection connection, final TableName tableName,
      final String username, final byte[] family, final byte[] qualifier,
      final Permission.Action... actions) throws Throwable {
    PayloadCarryingRpcController controller
      = ((ClusterConnection) connection).getRpcControllerFactory().newController();
    controller.setPriority(tableName);
    try (Table table = connection.getTable(ACL_TABLE_NAME)) {
      ProtobufUtil.revoke(controller, getAccessControlServiceStub(table), username, tableName,
        family, qualifier, actions);
    }
  }

  /**
   * Revokes the permission on the table for the specified user.
   * @param connection The Connection instance to use
   * @param namespace
   * @param userName
   * @param actions
   * @throws Throwable
   */
  public static void revoke(final Connection connection, final String namespace,
      final String userName, final Permission.Action... actions) throws Throwable {
    PayloadCarryingRpcController controller
      = ((ClusterConnection) connection).getRpcControllerFactory().newController();
    try (Table table = connection.getTable(ACL_TABLE_NAME)) {
      ProtobufUtil.revoke(controller, getAccessControlServiceStub(table), userName, namespace,
        actions);
    }
  }

  /**
   * Revoke global permissions for the specified user.
   * @param connection The Connection instance to use
   */
  public static void revoke(final Connection connection, final String userName,
      final Permission.Action... actions) throws Throwable {
    PayloadCarryingRpcController controller
      = ((ClusterConnection) connection).getRpcControllerFactory().newController();
    try (Table table = connection.getTable(ACL_TABLE_NAME)) {
      ProtobufUtil.revoke(controller, getAccessControlServiceStub(table), userName, actions);
    }
  }

  /**
   * List all the userPermissions matching the given pattern.
   * @param connection The Connection instance to use
   * @param tableRegex The regular expression string to match against
   * @return - returns an array of UserPermissions
   * @throws Throwable
   */
  public static List<UserPermission> getUserPermissions(Connection connection, String tableRegex)
      throws Throwable {
    PayloadCarryingRpcController controller
      = ((ClusterConnection) connection).getRpcControllerFactory().newController();
    List<UserPermission> permList = new ArrayList<UserPermission>();
    try (Table table = connection.getTable(ACL_TABLE_NAME)) {
      try (Admin admin = connection.getAdmin()) {
        CoprocessorRpcChannel service = table.coprocessorService(HConstants.EMPTY_START_ROW);
        BlockingInterface protocol =
            AccessControlProtos.AccessControlService.newBlockingStub(service);
        HTableDescriptor[] htds = null;
        if (tableRegex == null || tableRegex.isEmpty()) {
          permList = ProtobufUtil.getUserPermissions(controller, protocol);
        } else if (tableRegex.charAt(0) == '@') {  // Namespaces
          String namespaceRegex = tableRegex.substring(1);
          for (NamespaceDescriptor nsds : admin.listNamespaceDescriptors()) {  // Read out all namespaces
            String namespace = nsds.getName();
            if (namespace.matches(namespaceRegex)) {  // Match the given namespace regex?
              permList.addAll(ProtobufUtil.getUserPermissions(controller, protocol,
                Bytes.toBytes(namespace)));
            }
          }
        } else {  // Tables
          htds = admin.listTables(Pattern.compile(tableRegex), true);
          for (HTableDescriptor hd : htds) {
            permList.addAll(ProtobufUtil.getUserPermissions(controller, protocol,
              hd.getTableName()));
          }
        }
      }
    }
    return permList;
  }

  /**
   * Grants permission on the specified table for the specified user
   * @param conf
   * @param tableName
   * @param userName
   * @param family
   * @param qual
   * @param actions
   * @throws Throwable
   * @deprecated Use {@link #grant(Connection, TableName, String, byte[], byte[],
   * Permission.Action...)} instead.
   */
  @Deprecated
  public static void grant(Configuration conf, final TableName tableName,
      final String userName, final byte[] family, final byte[] qual,
      final Permission.Action... actions) throws Throwable {
    try (Connection connection = ConnectionFactory.createConnection(conf)) {
      grant(connection, tableName, userName, family, qual, actions);
    }
  }

  /**
   * Grants permission on the specified namespace for the specified user.
   * @param conf
   * @param namespace
   * @param userName
   * @param actions
   * @throws Throwable
   * @deprecated Use {@link #grant(Connection, String, String, Permission.Action...)}
   * instead.
   */
  @Deprecated
  public static void grant(Configuration conf, final String namespace,
      final String userName, final Permission.Action... actions) throws Throwable {
    try (Connection connection = ConnectionFactory.createConnection(conf)) {
      grant(connection, namespace, userName, actions);
    }
  }

  /**
   * Grant global permissions for the specified user.
   * @deprecated Use {@link #grant(Connection, String, Permission.Action...)} instead.
   */
  @Deprecated
  public static void grant(Configuration conf, final String userName,
      final Permission.Action... actions) throws Throwable {
    try (Connection connection = ConnectionFactory.createConnection(conf)) {
      grant(connection, userName, actions);
    }
  }

  /**
   * @deprecated Use {@link #isAccessControllerRunning(Connection)} instead.
   */
  @Deprecated
  public static boolean isAccessControllerRunning(Configuration conf)
      throws MasterNotRunningException, ZooKeeperConnectionException, IOException {
    try (Connection connection = ConnectionFactory.createConnection(conf)) {
      return isAccessControllerRunning(connection);
    }
  }

  /**
   * Revokes the permission on the table
   * @param conf
   * @param tableName
   * @param username
   * @param family
   * @param qualifier
   * @param actions
   * @throws Throwable
   * @deprecated Use {@link #revoke(Connection, TableName, String, byte[], byte[],
   * Permission.Action...)} instead.
   */
  @Deprecated
  public static void revoke(Configuration conf, final TableName tableName,
      final String username, final byte[] family, final byte[] qualifier,
      final Permission.Action... actions) throws Throwable {
    try (Connection connection = ConnectionFactory.createConnection(conf)) {
      revoke(connection, tableName, username, family, qualifier, actions);
    }
  }

  /**
   * Revokes the permission on the table for the specified user.
   * @param conf
   * @param namespace
   * @param userName
   * @param actions
   * @throws Throwable
   * @deprecated Use {@link #revoke(Connection, String, String, Permission.Action...)} instead.
   */
  @Deprecated
  public static void revoke(Configuration conf, final String namespace,
      final String userName, final Permission.Action... actions) throws Throwable {
    try (Connection connection = ConnectionFactory.createConnection(conf)) {
      revoke(connection, namespace, userName, actions);
    }
  }

  /**
   * Revoke global permissions for the specified user.
   * @deprecated Use {@link #revoke(Connection, String, Permission.Action...)} instead.
   */
  @Deprecated
  public static void revoke(Configuration conf, final String userName,
      final Permission.Action... actions) throws Throwable {
    try (Connection connection = ConnectionFactory.createConnection(conf)) {
      revoke(connection, userName, actions);
    }
  }

  /**
   * List all the userPermissions matching the given pattern.
   * @param conf
   * @param tableRegex The regular expression string to match against
   * @return - returns an array of UserPermissions
   * @throws Throwable
   * @deprecated Use {@link #getUserPermissions(Connection, String)} instead.
   */
  @Deprecated
  public static List<UserPermission> getUserPermissions(Configuration conf, String tableRegex)
  throws Throwable {
    try (Connection connection = ConnectionFactory.createConnection(conf)) {
      return getUserPermissions(connection, tableRegex);
    }
  }
}
