在微软官网搜索jdbc4，并下载sqljdbc_6.0.7728.100_enu.tar.gz这样的压缩包，然后将里面的sqljdbc4.jar复制到tomcat的lib文件夹下  
测试代码：  
```
<%@page language="java" import="java.util.*" import="java.sql.*" pageEncoding="gb2312" %>
<!DOCTYPE html>
<html>
    
    <body>
        <%
        Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
		String dbURL = "jdbc:sqlserver://127.0.0.1:1433;DatabaseName=Test";
		String userName = "sa";
		String userPw = "123";
		Connection ct = DriverManager.getConnection(dbURL, userName, userPw);
		System.out.println("connect success");
         %>
    </body>
</html>
```
