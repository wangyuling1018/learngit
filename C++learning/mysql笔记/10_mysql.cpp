//
//  10_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/14.
//

/*流程控制语句
 1、条件控制语句
if语句
     1）简单的if
         if 条件表达式 then
             语句块;
         end if;
     2) if...else
         if  条件表达式 then
             语句块1;
         else
             语句块2；
         end if;
     3)多分支if
         if  条件表达式 then
             语句块1;
         elseif 条件表达式2 then
             语句块2；
          ....
         [else 语句块n;]
         end if;
             
    -- 重新创建函数get_name_fn(),实现根据学号或工号查询姓名
    drop function get_name_fn;
    delimiter $$
    create function get_name_fn(no char(11),role char(10)) returns char(10)
    begin
        declare name char(10);
        if role='teacher' then
            select teacher_name into name from teacher where teacher_no=no;
            return name;
        elseif role='student' then
            select student_name into name from student where student_no=no;
            return name;
        else
            return '输入错误';
        end if;
    end;
    $$
    delimiter ;
 
    -- 调用
    select get_name_fn('001','teacher');
    select get_name_fn('201801','student');
    select get_name_fn('001','tea');
    select get_name_fn('007','teacher');-- 不存在的，结果集为NULL
 
 
 
 
    drop function fn_getname$$
    create function fn_getname(no char(11),role char(10)) returns char(10)
    begin
       declare name char(10);
       if role='teacher' then
          select teacher_name into name from teacher where teacher_no=no;
       elseif role='student' then
          select student_name into name from student where student_no=no;
       else
          set name='输入错误';
       end if;
       return name;
    end;
    $$

    select fn_getname('001','teacher')$$
    select fn_getname('2018001','student')$$
    select fn_getname('2018110','student')$$
    select fn_getname('2018001','stu')$$

case语句
case..end case
    -- 创建函数，根据日期打印星期几
    delimiter $$
    create function fn_getweek(d date) returns char(10)
    begin
      declare week char(10);
      case weekday(d)
         when 0 then set week='星期一';
         when 1 then set week='星期二';
         when 2 then set week='星期三';
         when 3 then set week='星期四';
         when 4 then set week='星期五';
         when 5 then set week='星期六';
         else set week='星期日';
      end case;
      return week;
    end;
    $$
    delimiter ;
    
    -- 调用
    select fn_getweek('2019-01-01');
    select fn_getweek('2000-01-01');
 
    
循环语句
while循环
    -- 实现1到n的累加和
    delimiter $$
    create function fn_getsum1(n int) returns int  -- int getsum(int n)
    begin                                          -- {
        declare sum int default 0;                   --     int sum=0;
        declare i int default 0;                     --     int i=0;
        while i<n do                                 --     while(i<n){
            set i=i+1;                                 --        i++;
            set sum=sum+i;                             --        sum+=i;
        end while;                                   --     }
        return sum;                                  --     return sum;
    end;                                           --  }
    $$
    delimiter ;
 
  -- 调用
   select fn_getsum1(100);
    
leave语句 -- 相当于C语言中的break
 -- 实现1到n的累加和
   delimiter $$
   create function fn_getsum2(n int) returns int
   begin
     declare sum int default 0;
     declare i int default 0;
     add_sum:while true do
        set i=i+1;
        set sum=sum+i;
        if i=n then         -- if(i==n){
          leave add_sum;    --    break;
        end if;             -- }
     end while add_sum;
     return sum;
   end;
   $$
   delimiter ;
 
    -- 调用
   select fn_getsum2(100);
 
iterate语句   -- 相当于C语言中的continue
 -- 实现1到n的偶数和
   delimiter $$
   create function fn_getsum3(n int) returns int
   begin
     declare sum int default 0;
     declare i int default 0;
     add_sum:while i<n do
       set i=i+1;
       if i%2!=0 then        -- if(i%2){
           iterate add_sum;  --    continue;
       end if;               -- }
       set sum=sum+i;
     end while;
     return sum;
   end;
   $$
   delimiter ;
 
  -- 调用
  select fn_getsum3(100);

repeat循环
 -- 实现1到n的累加和
   delimiter $$
   create function fn_getsum4(n int) returns int
   begin
     declare sum int default 0;
     declare i int default 0;
     repeat
       set i=i+1;
       set sum=sum+i;
       until i=n
     end repeat;
     return sum;
   end;
   $$
   delimiter ;
 
   -- 调用
   select fn_getsum4(100);

loop循环
 -- 实现1到n的累加和
   delimiter $$
   create function fn_getsum5(n int) returns int
   begin
     declare sum int default 0;
     declare i int default 0;
     add_sum:loop
       set i=i+1;
       set sum=sum+i;
       if i=n then
         leave add_sum;
       end if;
     end loop add_sum;
     return sum;
   end;
   $$
   delimiter ;

 -- 调用
 select fn_getsum5(100);

 
 */
