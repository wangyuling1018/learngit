//
//  06_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/10.
//

/*
 
oder by子句
 1.单列排序
    -- 选课表的分数按照降序排
     select * from choose order by score desc;
    -- 查询学生的考试成绩、平时成绩的综合成绩
     select stu_no,exam_score,regular_score,exam_score
  *0.8+regular_score*0.2 total_score from exam order by total_score desc;
     select stu_no,exam_score,regular_score,exam_score
 *0.8+regular_score*0.2 total_score from exam order by 4 desc; -- 4表示字段列的第4个字段
  
  2.多列排序
     select table_schema,table_name from information_schema.tables order by table_schema,table_name desc;
     -- 先按照table_schema进行升序排序，当table_schema相同的时候，那些相同项再按照table_name降序排序
  
     -- null值默认按照最小值处理

 组函数
  1.基本用法
    select count(*) from choose;
    select max(choose_time),min(choose_time) from choose;
    select sum(score),avg(score) from choose where student_no='201801';
 2.组函数对NULL值的处理是忽略
    select count(*),count(score) from choose;
 3.组函数的参数可以用distinct修饰（可以进行排重之后的汇总）
    select count(*),count(class_no),count(distinct class_no) from student;
    -- count(*):有多少行，包括null值
    -- count(class_no)：class_no不包含null值的，有多少行
    -- count(distinct class_no)：class_no不包含null值，且不重复的，有多少行
 
分组
 1.单列分组
 -- 列出每一个同学的总分和平均分
    select student_no,sum(score) 总分,avg(score) 平均分 from choose
        group by student_no;
 2.多列分组
    select student_no,course_no,sum(score) 总分,avg(score) 平均分 from choose
      group by student_no;-- error,select后的字段：1、必须是分组字段（在group by后必须有的字段）
    
    select s.student_no,student_name,sum(score) 总分,avg(score) 平均分
        from student s,choose c
            where s.student_no = c.student_no
                group by s.student_no;
    -- select后的字段：1、必须是分组字段（在group by后必须有的字段）例如：student_no 2、依赖于分组字段的字段（与分组字段必须是一对一的关系）例如：student_name。3、属于组函数，例如:sum(score) 总分,avg(score) 平均分
 
    或
    select s.student_no,student_name,sum(score) 总分,avg(score) 平均分
        from student s,choose c
            where s.student_no = c.student_no
                group by s.student_no,s.student_name;-- 保险起见，group by后加上s.student_name，这样mysql、oracel等数据库都可以用
 
    -- 统计每个数据库中表的数量
    select table_schema,count(*) cnt from information_schema.tables
       group by table_schema;
    -- 根据类型汇总
    select table_type,count(*) cnt from information_schema.tables
       group by table_type;
    -- 多列分组
    select table_schema,table_type,count(*) cnt from information_schema.tables
      group by table_schema,table_type;
 
3.having子句
  -- having：对分组统计的结果集，再次进行筛选
     问题：根据数据库(table_schema)进行分组统计，列出表的数量超过50的数据库
    select table_schema,count(*) cnt from information_schema.tables
          # where cnt>50  -- where子句中不能使用字段或表达式的别名
          # where count(*) > 50 -- where子句中不能使用组函数
           group by table_schema;

    select table_schema,count(*) cnt from information_schema.tables
       group by table_schema
          -- having count(*) > 50; 正确
          having cnt>50;


    select table_schema db,count(*) cnt
      from information_schema.tables
        where table_name like '%u%'
         group by db
           having cnt>50
             order by cnt;

     select语句，语法顺序：
      select -- 后面是字段列表，我们要显示的列
        from -- 后面是数据源，可以是表或视图
           where -- 从数据源中去筛选数据行
             group by -- 根据字段或字段列表对数据进行分组
               having -- 对分组的结果进行筛选
                 order by -- 对结果集进行排序

     select语句，执行顺序：
     from
       where
         select
           group by
             having
               order by
 
 
 */
