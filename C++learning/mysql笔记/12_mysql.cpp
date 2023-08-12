//
//  12_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/14.
//

/*
触发器
 new：新值， 使用方式：new.字段
 old：旧值， 使用方式：old.字段
 
 -- 创建 插入约束触发器
 delimiter $$
 create trigger tr_insert_course_before  before insert on course for each row
 begin
   if new.up_limit not in(60,150,230) then
     signal sqlstate 'ERROR' set message_text='选修课人数只能在(60,150,230)中取值';
   end if;
 end;
 $$
 delimiter ;
 
 -- 测试
 insert into course values(null,'Html',100,'暂无',default,'004'); -- 错误
 insert into course values(null,'Html',150,'暂无',default,'004'); -- 成功
  
 update course set up_limit=100 where course_no=8;  -- 正确
 -- 创建 更新约束触发器，保证执行update操作时，确保up_limit字段的值在(60,150,230)中取值
 delimiter $$
 create trigger tr_update_course_before  before update on course for each row
 begin
   if new.up_limit not in(60,150,230) then
     set new.up_limit=old.up_limit; -- 一旦发现新值不正确，就保留原值
   end if;
 end;
 $$
 delimiter ;
 
 -- 测试
 mysql> update course set up_limit=100 where course_no=8;
 Query OK, 0 rows affected (0.00 sec) -- 提示0行被修改
 Rows matched: 1  Changed: 0  Warnings: 0

 mysql> select * from course; --查看没有修改
 +-----------+-------------+----------+-------------+-----------+------------+
 | course_no | course_name | up_limit | description | status    | teacher_no |
 +-----------+-------------+----------+-------------+-----------+------------+
 |         1 | C语言       |       60 | 暂无        | 已审核    | 001        |
 |         2 | MySQL       |      150 | 暂无        | 已审核    | 002        |
 |         3 | Java        |      230 | 暂无        | 已审核    | 003        |
 |         8 | Html        |      150 | 暂无        | 未审核    | 004        |
 +-----------+-------------+----------+-------------+-----------+------------+
 
 
 mysql> update course set up_limit=100,status='已审核' where course_no=8;
 Query OK, 1 row affected (0.00 sec)
 Rows matched: 1  Changed: 1  Warnings: 0

 mysql> select * from course; -- 仍然没有修改
 +-----------+-------------+----------+-------------+-----------+------------+
 | course_no | course_name | up_limit | description | status    | teacher_no |
 +-----------+-------------+----------+-------------+-----------+------------+
 |         1 | C语言       |       60 | 暂无        | 已审核    | 001        |
 |         2 | MySQL       |      150 | 暂无        | 已审核    | 002        |
 |         3 | Java        |      230 | 暂无        | 已审核    | 003        |
 |         8 | Html        |      150 | 暂无        | 已审核    | 004        |
 +-----------+-------------+----------+-------------+-----------+------------+
 4 rows in set (0.00 sec

查看触发器
    \G:表示纵向显示
    show triggers\G
    show triggers like '%tr%'\G
    show create trigger tr_update_course_before\G
删除触发器
    drop trigger tr_update_course_before;
 
 */
