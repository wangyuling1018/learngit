//
//  15_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/14.
//

/*游标
 delimiter $$
 -- 创建存储过程
 create procedure update_score_proc(c_no int)
 begin
    -- 声明变量
    declare stu_no char(11); -- 接收学号
    declare grade int; -- 接收成绩
    declare state char(10); -- 存错误状态
    -- 声明游标
    declare score_cur cursor for select student_no,score from choose where course_no=c_no; -- 游标声明
    -- 声明错误处理程序
    declare continue handler for not found set state='error'; -- 错误处理声明
    -- 打开游标
    open score_cur; -- 打开游标
    -- 循环提取并处理数据
    update_score:loop -- 循环
        fetch score_cur into stu_no,grade; -- 提取当前行数据并保存在变量中
        if state='error' then -- 结束循环
            leave update_score;
        end if;
        -- 处理数据
        set grade=grade+5;
        if grade>100 then
            set grade=100;
        end if;
        if grade between 55 and 59 then
            set grade=60;
        end if;
        update choose set score=grade where student_no=stu_no and course_no=c_no;
    end loop update_score; -- loop结束
    -- 关闭游标
    close score_cur;
 end;
 $$
 delimiter ;
 
 -- 调用
 call update_score_proc(1);
 
 
 
 
 
 delimiter $$
 create procedure pc_update_score(c_no int)
 begin
    -- 声明局部变量
    declare no int;         -- 接收主键(选课编号)
    declare grade int;      -- 接收成绩
    declare state char(10); -- 保存状态，判断循环是否退出
    -- 声明游标
    declare cur_score cursor for select choose_no,score from choose where course_no=c_no;
    -- 声明错误处理程序
    declare continue handler for not found set state='error';
    -- 打开游标
    open cur_score;
    -- 循环提取并处理数据
    update_score:loop
       fetch cur_score into no,grade; -- 提取当前行数据并保存在变量中
       if state='error' then leave update_score; end if; -- 结束循环
       set grade = grade + 5;  -- 全部加5分
       if grade > 100 then  set grade=100; end if;  -- 100封顶
       if grade between 55 and 59 then  set grade=60; end if; -- 55~59的改为60
       update choose set score=grade where choose_no=no; -- 更新到数据库
    end loop update_score;
    -- 关闭游标
    close cur_score;
 end;
 $$
 delimiter ;
 
 -- 测试
 call pc_update_score(2);


 
 */
