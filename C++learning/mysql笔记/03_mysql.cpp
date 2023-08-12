//
//  03_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/9.
//

/*select语句
 
 mysql> select version(),now();
 +-----------+---------------------+
 | version() | now()               |
 +-----------+---------------------+
 | 8.0.32    | 2023-03-09 16:18:10 |
 +-----------+---------------------+
 
 mysql> select version() as 版本号, now() as 当前服务器时间;  //增强可读性，as起别名
 +-----------+-----------------------+
 | 版本号    | 当前服务器时间        |
 +-----------+-----------------------+
 | 8.0.32    | 2023-03-09 16:20:31   |
 +-----------+-----------------------+
 
 
 1.基本查询语句
    -- 查询全部字段
    select * from student;
    select student_no,student_name,student_contact,class_no from student;
    -- 查询部分字段
    select student_no,student_name,class_no from student;
    -- 为字段命名别名
    select student_no 学号,student_name 姓名,class_no 班号 from student;
    -- 使用表达式
    select stu_no 学号,exam_score 卷面成绩,regular_score 平时成绩,exam_score*0.8+regular_score*0.2 综合成绩 from exam;
    -- 使用distinct
    use information_schema;
    show tables; -- 显示当前数据库下的全部列表
    desc tables; -- 注意：这里的tables是information_schema中的表格，显示tables的表结构
    select table_schema 数据库名,table_name 表名,table_type 类型 from information_schema.tables;
    select distinct table_schema 数据库名 from information_schema.tables;
    select distinct table_type 类型 from information_schema.tables;
    select distinct table_schema 数据库名,table_type 类型 from information_schema.tables;
    -- 使用limit限定返回数据行   //查询的结果，按照分页显示
    select table_schema 数据库名,table_name 表名 from information_schema.tables
        limit 10;-- 检索第1行到第10行
    select table_schema 数据库名,table_name 表名 from information_schema.tables
        limit 60,10;-- 每页10行，检索第7页，就是第61行到第70行
    select table_schema 数据库名,table_name 表名 from information_schema.tables
        limit (n-1)*m,m; -- 每页m行，列出n页
 
 */
