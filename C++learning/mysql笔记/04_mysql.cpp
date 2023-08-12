//
//  04_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/10.
//


//匹配不上的记录：数据只在其中一张表中出现，在另外一张表中没有对应数据
//三表内连接：关联条件1要 表1和表2有关系，关联条件2要 表3和表1 或 表3和表2有关系。表是有顺序的,并不是完全无序的。

/*
 需求：列出学生的信息，包括学号、姓名和班级名称
    student: student_no,student_name
    classes: class_name
 将2张表拼成一个数据表，再检索
 
 mysql> select * from student;
 +------------+--------------+-----------------+----------+
 | student_no | student_name | student_contact | class_no |
 +------------+--------------+-----------------+----------+
 | 201801     | 张三         | 1500000000      |        1 |
 | 201802     | 马虎         | 1600000000      |        1 |
 | 201803     | 李四         | 1700000000      |        2 |
 | 201804     | 王五         | 1800000000      |        3 |
 | 201805     | 马六         | 1900000000      |        3 |
 | 201806     | 田七         | 2000000000      |        2 |
 +------------+--------------+-----------------+----------+
 mysql> select * from classes;
 +----------+-------------------+-----------------+
 | class_no | class_name        | department_name |
 +----------+-------------------+-----------------+
 |        1 | 2018自动化1班     | 机电工程        |
 |        2 | 2018自动化2班     | 机电工程        |
 |        3 | 2018自动化3班     | 机电工程        |
 |        4 | 2018自动化4班     | 机电工程        |
 +----------+-------------------+-----------------+

 -- 内连接
 -- 匹配不上的记录：数据只在其中一张表中出现，在另外一张表中没有对应数据
 select student.student_no,student.student_name,classes.class_name
    from student inner join classes
        on student.class_no = classes.class_no;
 +------------+--------------+-------------------+
 | student_no | student_name | class_name        |
 +------------+--------------+-------------------+
 | 201801     | 张三         | 2018自动化1班     |
 | 201802     | 马虎         | 2018自动化1班     |
 | 201803     | 李四         | 2018自动化2班     |
 | 201806     | 田七         | 2018自动化2班     |
 | 201804     | 王五         | 2018自动化3班     |
 | 201805     | 马六         | 2018自动化3班     |
 +------------+--------------+-------------------+
 
 -- 向学生表student中插入测试数据
 insert into student values('2018006','张三丰','2100000000',null);
 -- 向班级表classes中插入测试数据
 insert into classes values(null,'2018电子信息1班','信息学院');
 -- 测试
 select student.student_no,student.student_name,classes.class_name
    from student inner join classes
        on student.class_no = classes.class_no;-- 与上面的结果一样
 +------------+--------------+-------------------+
 | student_no | student_name | class_name        |
 +------------+--------------+-------------------+
 | 201801     | 张三         | 2018自动化1班     |
 | 201802     | 马虎         | 2018自动化1班     |
 | 201803     | 李四         | 2018自动化2班     |
 | 201806     | 田七         | 2018自动化2班     |
 | 201804     | 王五         | 2018自动化3班     |
 | 201805     | 马六         | 2018自动化3班     |
 +------------+--------------+-------------------+
 
 -- 表的别名
 select s.student_no,s.student_name,c.class_name
    from student s join classes c --两张表的顺序不影响结果
        on s.class_no = c.class_no;-- 与上面的结果一样
 #错误：表一旦命名别名，在当前语句中只能使用别名，不能使用原表名
 select student.student_no,s.student_name,c.class_name
    from student s join classes c
        on s.class_no = c.class_no;
 -- 如果连接的两张表，没有重名的字段，可以省略字段前的表名或别名
 select student_no,student_name,class_name
    from student s join classes c
        on s.class_no = c.class_no;-- 与上面的结果一样
 
 
 -- 三表内连接：关联条件1要 表1和表2有关系，关联条件2要 表3和表1 或 表3和表2有关系。表是有顺序的,并不是完全无序的。

 -- 向选课表choose中插入测试数据
 insert into choose values
   (null,'201801',2,40,'2019-01-03 12:45:23'),
   (null,'201801',1,50,'2018-12-23 10:35:20'),
   (null,'201802',3,60,'2019-01-06 11:45:23'),
   (null,'201802',2,70,'2020-01-05 09:40:23'),
   (null,'201803',1,80,'2019-06-13 12:45:23'),
   (null,'201804',2,90,'2018-12-10 12:45:23'),
   (null,'201805',3,null,'2019-01-23 12:45:23'),
   (null,'201805',1,null,'2019-01-03 12:45:23');
 
 -- 列出学生及其选课的信息，包括学号、姓名、选修课名和成绩
 student:student_no,student_name
 choose:score
 course:course_name
 关联条件：sudent.student_no = choose.sudent_no
         course.course_no = choose.course_no
 
 select s.student_no 学号,s.student_name 姓名,cs.course_name 课程名称,ch.score 成绩
    from student s join choose ch on s.student_no=ch.student_no
        join course cs on cs.course_no = ch.course_no;
 +--------+--------+--------------+--------+
 | 学号   | 姓名   | 课程名称     | 成绩   |
 +--------+--------+--------------+--------+
 | 201801 | 张三   | C语言        |     50 |
 | 201803 | 李四   | C语言        |     80 |
 | 201805 | 马六   | C语言        |   NULL |
 | 201801 | 张三   | MySQL        |     40 |
 | 201802 | 马虎   | MySQL        |     70 |
 | 201804 | 王五   | MySQL        |     90 |
 | 201802 | 马虎   | Java         |     60 |
 | 201805 | 马六   | Java         |   NULL |
 +--------+--------+--------------+--------+

 --外连接
 --列出全部学生的学号、姓名和所在班级名称
 select s.student_no,s.student_name,c.class_name
    from student s left join classes c
        on s.class_no = c.class_no;-- 左外，左表student和右表classes都有的数据 + 左表student中匹配不上的数据用null填充
 +------------+--------------+-------------------+
 | student_no | student_name | class_name        |
 +------------+--------------+-------------------+
 | 201800     | 张三丰       | NULL              |
 | 201801     | 张三         | 2018自动化1班     |
 | 201802     | 马虎         | 2018自动化1班     |
 | 201803     | 李四         | 2018自动化2班     |
 | 201804     | 王五         | 2018自动化3班     |
 | 201805     | 马六         | 2018自动化3班     |
 | 201806     | 田七         | 2018自动化2班     |
 +------------+--------------+-------------------+

 select s.student_no,s.student_name,c.class_name
    from student s right join classes c
        on s.class_no = c.class_no;-- 右外，左表student和右表classes都有的数据 + 右表classes中匹配不上的数据用null填充
 +------------+--------------+----------------------+
 | student_no | student_name | class_name           |
 +------------+--------------+----------------------+
 | NULL       | NULL         | 2018电子信息1班      |
 | 201801     | 张三         | 2018自动化1班        |
 | 201802     | 马虎         | 2018自动化1班        |
 | 201803     | 李四         | 2018自动化2班        |
 | 201806     | 田七         | 2018自动化2班        |
 | 201804     | 王五         | 2018自动化3班        |
 | 201805     | 马六         | 2018自动化3班        |
 | NULL       | NULL         | 2018自动化4班        |
 +------------+--------------+----------------------+

 */
