 1. 安装SQL Server2014采用**SQL Server身份验证方式**而不是windows身份验证方式。
 2. [SQL Server2014开启协议](https://github.com/poluner/blog/blob/master/java/SQL%20Server2014%E5%A6%82%E4%BD%95%E6%89%93%E5%BC%80%E5%8D%8F%E8%AE%AE.md)。
 3. [在telnet服务打开的前提下](https://github.com/poluner/blog/blob/master/java/Windows%E5%A6%82%E4%BD%95%E5%BC%80%E5%90%AFtelnet%E6%9C%8D%E5%8A%A1.md)，使用telnet命令测试1433端口是否打开：在【命令提示符】下输入 telnet 127.0.0.1 1433，若提示“不能打开到主机的连接，在端口 1433: 连接失败”，则说明1433端口没打开，**返回第2步重新操作**。
 4. 在微软官网下载JDBC驱动程序，对于**jdk1.7**以上的要下载**jdbc4**以上的才能用。
 5. 打开下载的压缩包**sqljdbc_4.0.2206.100_chs.tar.gz**，将**sqljdbc4.jar**复制出来，因为它是扩展的.jar嘛，所以建议复制到java文件夹下的lib\ext文件夹中，我的是在**C:\Program Files\Java\jre1.8.0_73\lib\ext**。
 6. 打开SQL Server2014，新建数据库Test，然后退出。
 7. 打开Eclipse，新建项目Test，然后右键单击src，依次选择【构建路径】->【配置构建路径】->【库】->【添加外部JAR】选中sqljdbc4.jar，然后【确定】。
![](http://img.blog.csdn.net/20160514113026851)
 8. 自己新建包和类，运行如下代码即可连接。
 

```
Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
String dbURL = "jdbc:sqlserver://127.0.0.1:1433;DatabaseName=Test";
String userName = "sa";
String userPw = "123";
Connection ct = DriverManager.getConnection(dbURL, userName, userPw);
System.out.println("连接成功");
```
