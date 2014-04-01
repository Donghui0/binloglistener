binloglistener
==============

This is a branch of MySQL replication listener. A few bugs of the orignal version has been fixed.

Install
----
1. download the project
2. download mysql and gtest
3. complie
<pre>
cd build
cmake ../src/ -DCMAKE_BUILD_TYPE=Release -DMYSQL_DIR=/home/mysql/mysql-5.6.15/ -DGTEST_DIR=/home/gtest; make
</pre>
