# hbase-release-1.1.2.2.6.1.0

编译需要git clone整个项目  然后进入 hbase-release/hbase-spark 执行 mvn clean package -DskipTests

后在 target下面生存新的依赖包

编译依赖下载如果有问题 请在 maven setting中增加 repo 

	<mirror>
	<id>nexus-private.hortonworks</id>
	<mirrorOf>*</mirrorOf>
	<name>nexus-private.hortonworks</name>
	<url>http://nexus-private.hortonworks.com/nexus/content/groups/public/</url>
      </mirror>
 
 使用命令
 
 提交验证：

建议使用 hbase-spark-1.1.2.2.6.1.0-2.10.6.jar

Hbase操作验证

spark-submit --master yarn --principal zyc@HDE.H3C.COM --keytab /etc/security/keytabs/zyc.keytab --conf spark.hadoop.hbase.client.kerberos.principal=zyc@HDE.H3C.COM --jars /usr/hdp/2.3.4.0-3485/hbase/lib/hbase-hadoop-compat-1.1.2.2.6.2.0-SNAPSHOT.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/zookeeper-3.4.6.2.6.2.0-SNAPSHOT.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/guava-12.0.1.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/protobuf-java-2.5.0.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/hbase-protocol-1.1.2.2.6.2.0-SNAPSHOT.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/hbase-client-1.1.2.2.6.2.0-SNAPSHOT.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/hadoop-common-2.7.1.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/hbase-common-1.1.2.2.6.2.0-SNAPSHOT.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/hbase-server-1.1.2.2.6.2.0-SNAPSHOT.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/metrics-core-2.2.0.jar --class org.apache.hadoop.hbase.spark.example.hbasecontext.HBaseDistributedScanExample  --executor-memory 512M --num-executors 1 hbase-spark-1.1.2.2.6.1.0-2.10.6.jar table
 

spark-submit --master yarn  --principal zyc@HDE.H3C.COM --keytab /etc/security/keytabs/zyc.keytab  --conf spark.hadoop.hbase.client.kerberos.principal=zyc@HDE.H3C.COM --jars  /usr/hdp/2.3.4.0-3485/hbase/lib/hbase-hadoop-compat-1.1.2.2.6.2.0-SNAPSHOT.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/zookeeper-3.4.6.2.6.2.0-SNAPSHOT.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/guava-12.0.1.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/protobuf-java-2.5.0.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/hbase-protocol-1.1.2.2.6.2.0-SNAPSHOT.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/hbase-client-1.1.2.2.6.2.0-SNAPSHOT.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/hadoop-common-2.7.1.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/hbase-common-1.1.2.2.6.2.0-SNAPSHOT.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/hbase-server-1.1.2.2.6.2.0-SNAPSHOT.jar,/usr/hdp/2.3.4.0-3485/hbase/lib/metrics-core-2.2.0.jar,/usr/hdp/2.3.4.0-3485/spark/lib/spark-assembly-1.6.3-hadoop2.7.1.jar --class org.apache.hadoop.hbase.spark.example.hbasecontext.HBaseBulkGetExample --executor-memory 512M --num-executors 1 hbase-spark-1.1.2.2.6.1.0-2.10.6.jar table

 

storm：
 

Kafka ACL操作：
 

cd /usr/hdp/2.3.4.0-3485/kafka/bin

删除ACL

./kafka-acls.sh --topic test --remove --allow-host * --allow-principal User:zyc --authorizer-properties zookeeper.connect=node1:2181 --group test-consumer-group --consumer --producer

增加

./kafka-acls.sh --topic test --add  --allow-principal User:zyc --authorizer-properties zookeeper.connect=node1:2181 --group test-consumer-group --consumer –producer

消费

./kafka-console-consumer.sh --topic test --bootstrap-server node2:6667 --from-beginning  --new-consumer --security-protocol SASL_PLAINTEXT --consumer.config ../conf/consumer.properties

发消息

./kafka-console-producer.sh --topic gnb --broker-list node1:6667 --security-protocol SASL_PLAINTEXT

   
   
