//
//  16_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/14.
//

/*事务机制
 2.1 事务机制的必要性
 -- 创建账号表
 create table account(
    account_no int auto_increment primary key, -- 账户编号
    account_name char(10) not null, -- 账户名
    balance decimal(12,2) unsigned -- 余额
 );
 -- 插入测试数据
 insert into account values(null,'甲',1000);
 insert into account values(null,'乙',1000);
 -- 创建存储过程（转账功能）
    -- 传入from_account转出账号、to_account转入账户、money钱数
 delimiter $$
 create procedure pc_tranfer(from_account int, to_account int,money decimal(12,2) )
 begin
    update account set balance=balance + money where account_no=to_account;
    update account set balance=balance - money where account_no=from_account;
 end;
 $$
 delimiter ;
 -- 测试存储过程
 call pc_tranfer(1,2,800);
 select * from account;
 +------------+--------------+---------+
 | account_no | account_name | balance |
 +------------+--------------+---------+
 |          1 | 甲           |  200.00 |
 |          2 | 乙           | 1800.00 |
 +------------+--------------+---------+
 -- 在次调用存储过程
 call pc_tranfer(1,2,800);
ERROR 1264 (22003): Out of range value for column 'balance' at row 1  -- 余额不足
 select * from account; -- 2号账户多了800，实际不应该这样
 +------------+--------------+---------+
 | account_no | account_name | balance |
 +------------+--------------+---------+
 |          1 | 甲           |  200.00 |
 |          2 | 乙           | 2600.00 |
 +------------+--------------+---------+


2.2  关闭MySQL自动提交
2.3 rollback
 show variables like 'autocommit';
 +---------------+-------+
 | Variable_name | Value |
 +---------------+-------+
 | autocommit    | OFF   |
 +---------------+-------+
 set autocommit=0; --关闭自动提交
 show variables like 'autocommit';
 +---------------+-------+
 | Variable_name | Value |
 +---------------+-------+
 | autocommit    | OFF   |
 +---------------+-------+
 update account set balance=balance + 800 where account_no=2; -- 2600+800=3400
 select * from account; -- 看似修改成功，写入了数据库
 +------------+--------------+---------+
 | account_no | account_name | balance |
 +------------+--------------+---------+
 |          1 | 甲           |  200.00 |
 |          2 | 乙           | 3400.00 |
 +------------+--------------+---------+
 
 重新打开一个终端，登录mysql
 mysql -u root -p
 use choose;
 select * from account; -- 实际是没有修改成功，写入数据库的
 +------------+--------------+---------+
 | account_no | account_name | balance |
 +------------+--------------+---------+
 |          1 | 甲           |  200.00 |
 |          2 | 乙           | 2600.00 |
 +------------+--------------+---------+
 
 rollback; -- 回滚（撤销），把当前事物中还没有提交的增删改操作撤销
 select * from account;
+------------+--------------+---------+
| account_no | account_name | balance |
+------------+--------------+---------+
|          1 | 甲           |  200.00 |
|          2 | 乙           | 2600.00 |
+------------+--------------+---------+
 
2.4 提交
 select * from account;
 +------------+--------------+---------+
 | account_no | account_name | balance |
 +------------+--------------+---------+
 |          1 | 甲           |  200.00 |
 |          2 | 乙           | 3400.00 |
 +------------+--------------+---------+
 update account set balance=balance + 800 where account_no=2; -- 3400+800=4200
 select * from account;
 +------------+--------------+---------+
 | account_no | account_name | balance |
 +------------+--------------+---------+
 |          1 | 甲           |  200.00 |
 |          2 | 乙           | 4200.00 |
 +------------+--------------+---------+
 commit; -- 显示提交
 select * from account;
 +------------+--------------+---------+
 | account_no | account_name | balance |
 +------------+--------------+---------+
 |          1 | 甲           |  200.00 |
 |          2 | 乙           | 4200.00 |
 +------------+--------------+---------+
  
 在另一个终端中测试
 select * from account;
 +------------+--------------+---------+
 | account_no | account_name | balance |
 +------------+--------------+---------+
 |          1 | 甲           |  200.00 |
 |          2 | 乙           | 3400.00 |
 +------------+--------------+---------+

 
2.5 使用事务完成转账功能
 drop procedure pc_tranfer;
 delimiter $$
 create procedure pc_tranfer(from_account int, to_account int,money decimal(12,2) )
 begin
   declare continue handler for 1264 -- 声明错误处理
   begin
       rollback; -- 一旦出错就回滚
   end;
    start transaction; -- 隐式提交，提交前面的操作
       update account set balance=balance + money where account_no=to_account;
       update account set balance=balance - money where account_no=from_account;
   commit; -- 如果2条update没有问题，再提交，有问题就回滚，撤销2条update
 end;
 $$
 delimiter ;
 select * from account;
 +------------+--------------+---------+
 | account_no | account_name | balance |
 +------------+--------------+---------+
 |          1 | 甲           |  200.00 |
 |          2 | 乙           | 4200.00 |
 +------------+--------------+---------+

 -- 测试
 call pc_tranfer(1,2,800);    -- 转账失败 (1账号没有少，2账号没有多)
 call pc_tranfer(2,1,800);   -- 转账成功


 2.6 保存点 savepoint
 创建存储过程，该存储过程撤销所有的insert语句
  delimiter $$
  create procedure pc_savepoint1()
  begin
    declare continue handler for  1062
    begin
        rollback to A; -- 撤销到记号A
        rollback; -- 记号A后面的也撤销
    end;
    insert into account values(null, '丙',1000);-- 成功
    savepoint A; -- 记号A
    insert into account values(last_insert_id(),'丁',1000); -- last_insert_id(）获取上一个自增长字段的值，构造违反唯一约束，出错的插入
   commit;
  end;
  $$
  delimiter ;

 -- 调用
 call pc_savepoint1();
 select * from account;
 +------------+--------------+---------+
 | account_no | account_name | balance |
 +------------+--------------+---------+
 |          1 | 甲           | 1000.00 |
 |          2 | 乙           | 3400.00 |
 +------------+--------------+---------+

 实现部分提交、部分撤销
 delimiter $$
  create procedure pc_savepoint2()
  begin
    declare continue handler for  1062
    begin
        rollback to A;-- 撤销到记号A
        commit;-- 提交
    end;
    insert into account values(null, '丙',1000);
    savepoint A;
    insert into account values(last_insert_id(),'丁',1000);
   commit;
  end;
  $$
  delimiter ;
 
 -- 调用
 call pc_savepoint2();
 select * from account;
 +------------+--------------+---------+
 | account_no | account_name | balance |
 +------------+--------------+---------+
 |          1 | 甲           | 1000.00 |
 |          2 | 乙           | 3400.00 |
 |          4 | 丙           | 1000.00 |
 +------------+--------------+---------+

 2.7 事务的4大特性
    1.原子性（Atomicity）
        事务的多条增删改语句是一个不可分割的整体。一旦一条语句出错，就会回滚所有语句。
    2.一致性（Consistency）
        事务执行前后，事务由一种一致性状态转换成另一种一致性状态，如果出错，就回滚到事务执行前的一致性状态。例如：转账不管成功与否，确保2个账户余额的和是不变的。
    3.隔离性（Isolation）
        一个事务在执行以后，如果没有提交，它对事务所做的改变，其他事务是看不到的。例如：去银行取钱，2个人到不同窗口，不能从同一个账户取钱。
        -- 测试，开2个终端窗口，模拟2个银行窗口
        第一个终端窗口：
        set autocommit=0;--关闭自动提交
        show variables like 'autocommit';
        select * from account;
         +------------+--------------+---------+
         | account_no | account_name | balance |
         +------------+--------------+---------+
         |          1 | 甲           | 1000.00 |
         |          2 | 乙           | 3400.00 |
         |          4 | 丙           | 1000.00 |
         +------------+--------------+---------+
        update account set balance=balance - 2000 where account_no=2; -- 取钱
         select * from account;
         +------------+--------------+---------+
         | account_no | account_name | balance |
         +------------+--------------+---------+
         |          1 | 甲           | 1000.00 |
         |          2 | 乙           | 1400.00 |
         |          4 | 丙           | 1000.00 |
         +------------+--------------+---------+
         commit; -- 提交后，第二个窗口才允许对这行数据进行增删改操作

 
        第二个终端窗口：
        set autocommit=0;
        show variables like 'autocommit';
         select * from account;
         +------------+--------------+---------+
         | account_no | account_name | balance |
         +------------+--------------+---------+
         |          1 | 甲           | 1000.00 |
         |          2 | 乙           | 3400.00 |
         |          4 | 丙           | 1000.00 |
         +------------+--------------+---------+
        第一个窗口取钱后，查看是否能看到取钱了？
        select * from account;-- 不能看到已经取钱了
         +------------+--------------+---------+
         | account_no | account_name | balance |
         +------------+--------------+---------+
         |          1 | 甲           | 1000.00 |
         |          2 | 乙           | 3400.00 |
         |          4 | 丙           | 1000.00 |
         +------------+--------------+---------+
        update account set balance=balance - 1000 where account_no=2; -- 也取钱，无法取钱，一直在等待，因为第一个窗口还没提交，对数据的更改还没有结束，这个操作是不开见的，为了确保这行数据不会出错，会对这行数据进行加锁，不让进行操作。等第一个窗口提交后，才允许操作。
         
    4.持久性（Durability）
        事务一旦执行提交成功后，对数据的改变是永久的，保存在了数据库相应的文件中。
 
 */
