//
//  07_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/10.
//
/*
1. 子查询
1.1  where
 1> 单值
    列出成绩低于平均分的信息
    1.查看平均分
        select avg(score) from choose; -- 65
    2.列出成绩低于65的
        select student_no,course_no,score from choose
            where score <65;
    3.合并
        select student_no,course_no,score from choose
            where score <(select avg(score) from choose);
 
     -- 列出'张三'的成绩信息，包括学号、课程号和成绩
     -- 使用表连接
      select c.student_no 学号,c.course_no 课程, c.score 成绩
        from student s join  choose c on s.student_no = c.student_no
          where s.student_name='张三';
     -- 使用子查询
      select student_no 学号, course_no 课程, score 成绩 from choose
        where student_no=(
         select student_no from student where student_name='张三'
      );

      -- 列出考试成绩低于平均分的信息，包括学号、课程号和成绩
     select student_no,course_no,score
       from choose
         where score < (select avg(score) from choose);

  2> 多值
   -- 插入测试数据
   insert into teacher values('006','林老师','12345678');
   insert into teacher values('004','蒋老师','14000000000');
   insert into teacher values('005','高老师','21000000000');
 
    -- 列出没有开设选修课的教师的信息
     ① 外连接
     select t.*
        from teacher t left join course c on t.teacher_no = c.teacher_no
           where c.course_no is null;
     ② 子查询
     select * from teacher
       where teacher_no not in( select teacher_no from course );
     -- 所有外连接都可以用子查询

       
   -- 列出没有学生的班级的信息
   select c.* from classes c left join student s on c.class_no=s.class_no
      where s.student_no is null;
   # 结果错
   select * from classes
      where class_no not in( select distinct class_no from student );
      
     class_no in(null,1,2,3)==> class_no=null or class_no=1 or class_no=2 or class_no=3
                                     ==> class_no=1 or class_no=2 or class_no=3
                                     ==> class_no in(1,2,3)

     class_no not in(null,1,2,3)
                                    ==>not(class_no=null or class_no=1 or class_no=2 or class_no=3)
                                    ==>class_no!=null and class_no!=1 and class_no!=2 and class_no!=3
                                    ==> null
    --  not in(不能出现null)
    select * from classes
      where class_no not in(
         select distinct class_no from student where class_no is not null);
  
 1.2 from
     -- from子句中的子查询必须有别名(内存标表的表名)
     -- 如果子查询中为字段命名了别名，则主查询中只能使用别名(内存表的字段名)
     select 学号,姓名,班级
      from  (select s.student_no 学号,s.student_name 姓名,
        s.student_contact 联系方式,c.class_name  班级,c.department_name 院系
          from student s, classes c where s.class_no=c.class_no) stu
            where 班级='2018自动化1班';

     select table_schema, count(table_name) from information_schema.tables
        group by table_schema
           having count(table_name)>50;
 
    -- from子句中的子查询的select 子句中的表达式必须有别名
    select * from
     (select table_schema, count(table_name) cnt from information_schema.tables
        group by table_schema) db
           where cnt>50;

    -- 列出比自己的平均分低的信息，包括学号、课程号、成绩和平均分
    select c.student_no,c.course_no,c.score,a.avg_score
      from choose c,
      (select student_no,avg(score) avg_score from choose group by student_no) a
         where c.student_no = a.student_no  and c.score>a.avg_score;

  2. 索引
    -- 一个数据库可以创建多个索引
    -- 索引可以是对个字段的组合，多个字段必须来自同一个表
    -- 不可以跨表索引
    -- 索引需要额外的存储空间，索引关键字经常是排序的
    
    -- 创建测试表
    create table t_index(
       id int primary key,
       name char(10) not null,
       index ix_name (name)
    );
    
    -- 创建存储过程
    delimiter $$
    create pocedure insert_index_proc(n int)
    begin
        declare i int default 1;
        while i<=n do
            insert into t_index values(null,i,concat('test',i));
            set i+1;
        end while;
    end;
    $$
    delimiter ;
 
    --  调用存储过程
    call insert_index_proc(1000000);
 

    -- 创建索引
    create table stu2 select * from student; -- 创建一个表
    create unique index ix_stuno on stu2(student_no); -- 添加索引
 
    -- 查看创建的索引
    show index from stu2\G
     mysql>  show index from stu2\G
     *************************** 1. row ***************************
             Table: stu2
        Non_unique: 0        -- 1:普通索引1，0:唯一索引为（索引不能包含重复值）
          Key_name: ix_stuno  -- 索引的名称
      Seq_in_index: 1          -- 索引的序列号，从1开始
       Column_name: student_n  -- 索引字段的名称
         Collation: A           -- 列以什么方式存储在索引中，A：升序，none：没有分类的
       Cardinality: 7          -- 索引中唯一值的数目的估计值，越大使用索引的几率越大
          Sub_part: NULL        -- 编入索引的字符数，如果整列作为索引为NULL
            Packed: NULL        -- 如何被压缩
              Null:
        Index_type: BTREE       -- 使用树的方式创建索引
           Comment:
     Index_comment:
           Visible: YES
        Expression: NULL
     1 row in set (0.01 sec)
 
    -- 删除索引
        drop index ix_stuno on stu2;


  3. 视图
    -- 对视图增删改，就是对原表进行增删改，一般情况下不允许在视图上进行增删改，
    -- 有时候对视图增删改，不一定成功
   -- 创建视图
   create view vw_stu(学号,姓名,联系方式)
   as
      select student_no,student_name,student_contact from stu2;

   insert into vw_stu values('2018110','小警','110');
   select * from vw_stu;
   select * from vw_stu where 姓名 like '张%';

   -- 当创建视图的select语句包含表连接、表达式等时，不能执行dml操作
   create view vw_score
   as
      select c.student_no,c.course_no,c.score,a.avg_score
      from choose c,
        (select student_no,avg(score) avg_score from choose group by student_no) a
         where c.student_no = a.student_no  and c.score>a.avg_score;


  -- 查看
     select * from information_schema.views where table_schema='choose'\G
  -- 删除
   drop view vw_score;

 
 
 */
