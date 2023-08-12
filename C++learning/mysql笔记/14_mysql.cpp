//
//  14_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/14.
//

/*错误处理
 
 错误处理类型：
 continue：当sql语句出现错误时，会立即去执行自定义错误处理程序，并且执行错误处理程序后，忽略这个错误，继续执行后面的mysql语句
 exit：当sql语句出现错误时，会立即去执行自定义错误处理程序，并且停止程序，后面mysql语句不再执行了。
 
 错误触发条件：在什么情况下，才去执行错误处理程序。即错误处理程序被执行的时机，包括预定义、MySQL错误代码、ANSI标准错误代码、自定义错误触发条件

 错误处理程序：要写变量和游标之后，并且在mysql语句执行之前，
 
1、自定义错误处理程序
 1）使用预定义错误触发条件
    delimiter $$
    create procedure get_name_proc(stu_no char(11),out stu_name char(10))
    begin
        declare exit handler for not found
        begin
            select concat('没有学号为',stu_no,'的学生') error;
        end;
        select student_name into stu_name from student where student_no=stu_no; #出错，则退出程序
        #.... 后面的sql语句不再执行
    end;
    $$
    delimiter ;
 -- 测试
    set @name='';
    call get_name_proc('201801',@name);
    select @name;
     +--------+
     | @name  |
     +--------+
     | 张三   |
     +--------+
    call get_name_proc('201810',@name);
     +--------------------------------+
     | error                          |
     +--------------------------------+
     | 没有学号为201810的学生         |
     +--------------------------------+
 
 2）使用MySQL错误代码
 -- 向课程表course中插入一行数据 如果违反唯一约束，提示错误
 delimiter $$
 create procedure pc_insert_course(
       c_name char(10),cnt int,infor varchar(100),t_no char(10))
  begin
    declare continue handler for 1062
    begin
       select '每名教师只能开设一门选修课' error;
    end;
    insert into course(course_name,up_limit,description,teacher_no)
        values(c_name,cnt,infor,t_no);#出错，则执行错误处理程序，然后接着执行下面的sql语句
    #.... 后面的sql语句接着执行
  end;
  $$
  delimiter ;
  -- 调用
  call pc_insert_course('css',150,'暂无','001');  -- 插入失败 '001'已经存在
     +-----------------------------------------+
     | error                                   |
     +-----------------------------------------+
     | 每名教师只能开设一门选修课              |
     +-----------------------------------------+
  call pc_insert_course('css',150,'暂无','005');  -- 正确 原来的course表中没有'005'
 
 3)使用ANSI标准错误代码
 delimiter $$
 create procedure pc_insert_course1(
       c_name char(10),cnt int,infor varchar(100),t_no char(10))
  begin
    declare continue handler for sqlstate '23000'
    begin
       select '每名教师只能开设一门选修课' error;
    end;
    insert into course(course_name,up_limit,description,teacher_no)
        values(c_name,cnt,infor,t_no);
  end;
  $$
  delimiter ;
 
 -- 调用
 call pc_insert_course1('css',150,'暂无','001');  -- 插入失败 '001'已经存在
 
 4）自定义错误触发条件
     delimiter $$
     create procedure pc_insert_course2(
           c_name char(10),cnt int,infor varchar(100),t_no char(10))
      begin
        declare unique_error condition for 1062;
        declare continue handler for unique_error
        begin
           select '每名教师只能开设一门选修课' error;
        end;
        insert into course(course_name,up_limit,description,teacher_no)
            values(c_name,cnt,infor,t_no);
      end;
      $$
      delimiter ;
 
     -- 调用
     call pc_insert_course2('css',150,'暂无','001');  -- 插入失败 '001'已经存在
 
 
 -- 如果出现多种错误
     delimiter $$
     create procedure pc_insert_course3(
           c_name char(10),cnt int,infor varchar(100),t_no char(10))
      begin
        declare continue handler for 1452 select '该教师不存在' error;
        declare continue handler for 1062
        begin
           select '每名教师只能开设一门选修课' error;
        end;
        insert into course(course_name,up_limit,description,teacher_no)
            values(c_name,cnt,infor,t_no);
      end;
      $$
      delimiter ;

     -- 调用
     call pc_insert_course3('css',150,'暂无','001');  -- '001' 违反唯一约束，1062
     call pc_insert_course3('css',150,'暂无','008');  -- '008' 违反外键约束

 */
