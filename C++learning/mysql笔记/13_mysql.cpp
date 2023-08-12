//
//  13_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/14.
//

/*存储过程
 1.创建存储过程
    delimiter $$
    create procedure get_course_num_proc(in stu_no char(11),out course_num int)
    begin
        select count(*) into course_num from choose where student_no=stu_no;
    end;
    $$
    delimiter ;
 2.调用
    call 存储过程名（参数列表）；
 
    set @stu_no='201801';
    set @c_cnt=0;
    call get_course_num_proc(@stu_no,@c_cnt);
    select @c_cnt;
    或
    call get_course_num_proc('201803',@c_cnt);
    select @c_cnt;
 
 -- 使用inout参数
     delimiter $$
     create procedure get_course_num1_proc(inout no int)
     begin
         select count(*) into no from choose where student_no=no;
     end;
     $$
     delimiter ;
 
 -- 调用
    set @no = '201801';
    call get_course_num1_proc(@no);
    select @no;
 
查看存储过程
    show procedure status\G
    show * from mysql.proc where db='choose' and type='procedure'\G
    show create procedure get_course_num1_proc\G
删除存储过程
    drop procedureb get_course_num1_proc;
 
 -- 函数和存储过程的区别
  1) 函数必须有返回类型和返回值，存储过程使用out或inout参数作为返回值
  2) 函数内部可以使用select..into语句为变量赋值，但是不能有返回结果集的语句，存储过程没有这个限制
   # 错误
   create function getname(stu_no int) returns char(10)
   begin
      declare name char(10);
      select student_name into name from student where student_no=stu_no;
      # desc student;  错误
      # select * from student; 错误
   end;
   $$
   -- 正确
   create procedure getname(stu_no int,out name char(10))
   begin
      select student_name into name from student where student_no=stu_no;
      desc student;
      select * from student;
   end;
   $$
  3) 函数可以直接在sql语句或mysql命令中使用，但是存储过程需要单独调用
  4) 函数中的函数体内不能使用事务控制语句
       
 
 
 */
