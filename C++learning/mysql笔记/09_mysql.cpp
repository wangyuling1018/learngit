//
//  09_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/14.
//

/*
 mysql> delimiter $$
 mysql>   create function fn_rowno() returns int
     ->   begin
     ->      set @row_no = @row_no + 1;
     ->      return @row_no;
     ->   end;
     ->   $$
 ERROR 1418 (HY000): This function has none of DETERMINISTIC, NO SQL, or READS SQL DATA in its declaration and binary logging is enabled (you *might* want to use the less safe log_bin_trust_function_creators variable)
 mysql>   delimiter ;

 解决方法
 在 MySQL 中创建函数时出现这种错误的解决方法：
 1、在 MySQL 数据库中执行以下语句，临时生效，重启后失效
 set global log_bin_trust_function_creators=TRUE;
 2、在配置文件 my.ini 的 [mysqld] 配置，永久生效
 log_bin_trust_function_creators=1
 */

/*自定义函数
   1）创建无参函数
      delimiter $$
      create function fn_rowno() returns int
      begin
         set @row_no = @row_no + 1;
         return @row_no;
      end;
      $$
      delimiter ;
      -- 调用
      set @row_no = 0;
      select fn_rowno() 行号,student_no 学号,student_name 姓名 from student;

  2）创建带参函数
    -- 根据给定的学号查询学生的姓名
        delimiter $$
        create function get_name_fn(stu_no char(11)) returns char(10)
        begin
            declare stu_name char(10);
            select student_name into stu_name from student where student_no=stu_no;-- 需要保证结果集是单行，即where查询出来的结果只有一行，如果是多行就需要多个变量去接收
            return stu_name;
        end;
        $$
        delimiter ;
    
        -- 调用
        set @stu_no='201801';
        select get_name_fn(@stu_no),get_name_fn('201802');
 
 
 
      delimiter $$
      create function fn_getname(stu_no char(11)) returns char(10)
      begin
         declare stu_name char(10);
         # 错误
         #select stu_name:=student_name from student where student_no=stu_no;
         -- set stu_name=(select student_name from student where student_no=stu_no);
         select student_name into stu_name from student where student_no=stu_no;
         return stu_name;
      end;
      $$
 
       -- 调用
       select fn_getname('2018002')$$
       -- 查看
       select * from mysql.proc where db='choose' and type='function'\G
 
查看函数
    1）查看当前数据库中的所有自定义的函数信息
        show function status\G
        show function status like '模式'\G  -- 类似模糊查询，查看符合指定模式的函数
 
        show function status like '%\_fn' \G
 
    2）查看指定数据库中的所有自定义函数名，例如查看mysql.proc数据库中的
        use mysql;  -- 切换数据库
        show tables; -- 查看当前数据库中的所有表
        desc proc; -- 查看其中proc表的结构
        select * from mysql.proc where db='choose' and type='function'\G
 
 select * from information_schema.ROUTINES where db='choose' and type='function'\G
 
    3）查看指定函数名的详细信息
        show create function 函数名\G
 
 删除函数
    drop function 函数名;
 
        

 */
