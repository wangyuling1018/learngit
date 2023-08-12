//
//  01_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/9.
//
/*
停止mysql服务器：service mysql stop
启动mysql服务器：service mysql start
退出mysql：exit 或 quit
清屏幕快捷键：ctrl + l
  

mysql服务器默认的端口是3306
登陆mysql：
    mysql -h localhost -u root -p mysql -p 3306
    或
    mysql -u root -p  //然后输入mysql密码进入 //常用
    或
    mysql -u root -ptarena //-p直接加密码，tarena是密码，这种写法会有警告，不安全
 
远程连接mysql：
    mysql -h 192.168.18.128 -u root -p  //可以写自己电脑的IP地址
 

 
        

 
 
 */
/*
 １．数据库的特点
 　　１> 采用复杂的结构化的数据模型
 　　　 2> 最低的冗余、有较高的数据独立性
 　　　　3> 数据库系统为用户提供方便的接口
 　　　　4> 几个方面的数据库控制功能
 　　　　并发控制
 　　　　数据库的恢复
 　　　　数据的完整性：数据的准确(实体完整性、域完整性、引用完整性、用户自定义完整性)
 　　　　安全性
 　　  5> 系统更为灵活
 　   6> 信息处理方式不再为程序为中心，而是以数据为中心
 
 2. MySQL数据库管理
  2.1 创建数据库
   create database choose;
  2.2 查看数据库
   1> 查看所有数据库名
     show databases;
   2> 显示数据库结构
     show create database choose;
  2.3 选择当前数据库
     use choose;
  2.4 删除数据库
   drop database choose;
 
 查看某个数据库的所有表
    show tables;
 
 3. MySQL表管理
  3.1 创建
   create table test(
      id int,
      name char(10)
   );
  3.2 查看
   desc test;
   +-------+----------+------+-----+---------+-------+
   | Field | Type     | Null | Key | Default | Extra |
   +-------+----------+------+-----+---------+-------+
   | id    | int(11)  | YES  |     | NULL    |       |
   | name  | char(10) | YES  |     | NULL    |       |
   +-------+----------+------+-----+---------+-------+
    字段名    数据类型   是否允许  键    默认值     额外信息
                        为空                   比如：自增长

    上面结果集中的行数是表中的字段数

    show create table test\G      \G -- 纵向显示查看结果
*/

// MySQL中的注释：
// 单行注释   --  (后面必须有一个空格)
//           #
// 多行注释: /* 注释内容 */


