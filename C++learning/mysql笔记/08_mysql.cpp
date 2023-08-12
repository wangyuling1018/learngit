//
//  08_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/10.
//

/*MySQL编程基础
 1. 用户变量
  1.1 用户会话变量
   会话变量属于弱类型  只在当前会话中可见 -- 退出mysql重新进入，之前的会话变量不是之前的了
 
    1）使用set
    set @username='张三'; -- 定义会话变量
    select @username; -- 查询会话变量
    set @username=100,@age=20;-- 定义多个会话变量
    set @age = @age+1; -- 可以进行运算
    select @username,@age;
    2）使用select
    select @username:='李四';  -- 产生结果集
    或
    select '王五',10 into @username,@age; -- 不会产生结果集
    select @username,@age; -- 查询结果集

    3） 用户会话变量和sql语句
    set @stu_no=(select student_no from student where student_name='张三');

    select @stu_no:=(select student_no from student where student_name='张三');
    可以简化成：
    select @stu_no:= student_no from student where student_name='张三';

    select student_no into @stu_no from student where student_name='张三';-- 常用

    select * from choose where student_no=@stu_no;
 
 begin-end语句块：类似c语言中的大括号
 重置命令结束标记:
    delimiter $$; -- 将语句的结束标记改为$$
    select * from student $$
 
 */
