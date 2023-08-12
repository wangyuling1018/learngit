//
//  05_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/10.
//

/*where
 -- 查询成绩>=60的
     select * from choose where score >= 60;
     +-----------+------------+-----------+-------+---------------------+
     | choose_no | student_no | course_no | score | choose_time         |
     +-----------+------------+-----------+-------+---------------------+
     |        29 | 201802     |         3 |    60 | 2019-01-06 11:45:23 |
     |        30 | 201802     |         2 |    70 | 2020-01-05 09:40:23 |
     |        31 | 201803     |         1 |    80 | 2019-06-13 12:45:23 |
     |        32 | 201804     |         2 |    90 | 2018-12-10 12:45:23 |
     +-----------+------------+-----------+-------+---------------------+
 -- 查询姓名为张三的学号、姓名、成绩
     select s.student_no,s.student_name,c.score
        from student s join choose c
           on s.student_no = c.student_no
                where s.student_name = '张三';-- 先连合，再查询
     +------------+--------------+-------+
     | student_no | student_name | score |
     +------------+--------------+-------+
     | 201801     | 张三         |    40 |
     | 201801     | 张三         |    50 |
     +------------+--------------+-------+
     
 -- 用where子句实现内连接
     -- 以下2种方式查询的结果是一样的
         select s.student_no,s.student_name,c.class_name
            from student s join classes c
                on s.class_no = c.class_no; -- 内连接
         
         select s.student_no,s.student_name,c.class_name
            from student s join classes c
                where s.class_no = c.class_no; -- 用where子句实现内连接


 -- between and
     -- 查询成绩是70～90的
        select * from choose
            where score between 70 and 90;
     -- 日期可以比较，日期越晚越大，例如今天比昨天大，明天比今天大
        select * from choose
            where choose_time between '2018-01-01 00:00:00' and '2018-12-31 23:59:59';-- 一年以内
 -- is null
 -- 如果查询某个子表没有匹配的数据，通常情况下单表就可以完成，也就意味着，有外键的情况下，子表的外键字段是不可能出现在主表中不存在的数据的，另一种情况就是null。
 -- 如果查询用来检索在主表中匹配不上的数据，需要借助外连接，再通过where子句筛选
     -- 数据库中的null,是未定义，对于空值的判断是需要特殊的运算符is null
         mysql> select null=null ,null!=null;-- null只要参与运算就会造成表达式结果为null
         +-----------+------------+
         | null=null | null!=null |
         +-----------+------------+
         |      NULL |       NULL |
         +-----------+------------+
    -- 查询没有班级的学生
        select * from student where class_no is null;
    -- 查询所有班级的学生
        select c.*,s.student_no
            from classes c left join student s
                on s.class_no = c.class_no;-- 连接条件
    -- 查询没有学生的班级
         select c.* #,s.student_no
             from classes c left join student s
                 on s.class_no = c.class_no -- 连接条件
                    where s.student_no is null; -- 筛选条件
 
 -- in
 -- 判断一个表达式的值是否处于列表中，等效于多个用“或”连接的表达式
    -- 列出选修了'c语言‘或‘java语言‘的信息
        select ch.student_no,cs.course_name,ch.score
            from choose ch join course cs
                on ch.course_no = cs.course_no
                    where cs.course_name in('C语言','Java语言');
 
 --like 模糊查询
    -- 查询所有姓张的信息
        select * from student
            where student_name like '张%';
    -- 查询表名中含有'usr_'字样的表 ，‘_'是通配符，表示一个任意字符，‘%’通配符：表示任意长度任意字符
        select table_name from information_schema.tables
            where table_name like 'user_%';-- user后面至少有一位字符都可以，查询的结果不对，users这种也被查出来了
        -- 解决方法
        -- 使用\作为转义字符（仅仅mysql支持）
         select table_name from information_schema.tables
             where table_name like 'user\_%';
        -- 自定义转义字符（所有mysql、oracle，SQserver等都支持）
         select table_name from information_schema.tables
             where table_name like 'user#_%' escape '#'; -- escape character:转义字符,转义符,换码符,换码字符
         
 -- 与运算 and
 -- 通常将 连接条件 和 筛选条件 用and拼接起来
    -- 列出成绩在70～90之间的信息
        select * from choose
            where score>=70 and score<=90; -- 查询的结果与用between and的结果一样
    -- 列出‘张三'的成绩信息
        select s.student_no,s.student_name,ch.score
            from student s,choose ch
                where s.student_no = ch.student_no -- 连接条件
                    and s.student_name = '张三'; -- 筛选条件
    -- 使用where子句实现三表内连接
    -- 不需要考虑表的顺序了，筛选条件顺序也可以任意
    -- 查询学生的考试成绩信息，包括学号、姓名、选修课程名称和成绩
        select s.student_no,s.student_name,cs.course_name,ch.score
            from student s,course cs,choose ch
                where s.student_no=ch.student_no and cs.course_no=ch.course_no;
 
 -- 或运算 or
    -- 列出选修了‘C语言’和‘Java’的信息，包括学号、课程名称和成绩
        select ch.student_no,cs.course_name,ch.score
            from choose ch,course cs
                where ch.course_no=cs.course_no -- 表连接条件
                    and (cs.course_name='C语言' or cs.course_name='Java'); -- 筛选条件，连接条件和筛选条件之间一定是and的关系，注意要加括号
 
-- 非运算 not(!)
    -- 列出选修人数上限不是60的课程信息
        select * from course where !(up_limit=60);
        或
        select * from course where not(up_limit=60);
        或
        select * from course where up_limit!=60;
    -- 运算符取反
        not in -- 注意in小括号中不能有null值
        -- 查询哪些学生是有班级的
            select * from student
                where class_no is not null;
        -- 查询哪些班级有学生
            select c.* from classes c left join student s
                on c.class_no=s.class_no
                    where s.student_no is not null; -- 有重复项
 
            select distinct c.* from classes c left join student s
                 on c.class_no=s.class_no
                     where s.student_no is not null; -- distinct对结果集进行去重
        -- 从学生表中查询班号为1和2的学生信息
            select * from student where class_no in(1,2); -- （1）
            select * from student where class_no not in(1,2); --（2）取反
            select * from student where class_no in(1,2,null); --（3）与 （1）一样，无差别
            select * from student where class_no not in(1,2,null); //error，not in的()中不能有null
            #not in的()中不能有null的原理：
                class_no in(1,2,null) ===> class_no=1 or class_no=2 or class_no=null #class_no=null的结果为NULL
                                      ===>class_no=1 or class_no=2
                class_no not in(1,2,null) ===> not(class_no=1 or class_no=2 or class_no=null)
                                          ===>class_no!=1 and class_no!=2 and class_no!=null #class_no!=null的结果为NULL，任何与NULL 相与的结果还是NULL
                                          ===>NULL
            
 
 
 
 
 
 
 
 
 
 
 */
