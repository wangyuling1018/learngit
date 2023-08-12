//
//  11_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/14.
//

/*系统函数
求近似值函数
    round(x) -- 计算离x最近的整数 //四舍五入到个位
    round(x,d) -- 计算离x最近的小数(d可以取负值）//d为正数，四舍五入到小数点后d位，d位负数，四舍五入到小数点前的d的绝对值位
    truncate(x,d) -- 截取到小数点y位（d可以取负值）
 
    ceil(x) -- 返回大于等于x的最小整数 //向上取整
    floor(x) -- 返回小于等于x的最大整数 //向下取整
 
随机函数
    rand() -- 返回随机数 //0到1之间的随机小数
 
     mysql> select round(34.56),round(34.56,1),round(456.78,-2);
     +--------------+----------------+------------------+
     | round(34.56) | round(34.56,1) | round(456.78,-2) |
     +--------------+----------------+------------------+
     |           35 |           34.6 |              500 |
     +--------------+----------------+------------------+
     mysql> select truncate(34.56,1),truncate(456.78,-2);
     +-------------------+---------------------+
     | truncate(34.56,1) | truncate(456.78,-2) |
     +-------------------+---------------------+
     |              34.5 |                 400 |
     +-------------------+---------------------+
     mysql> select ceil(3.5),floor(3.5);
     +-----------+------------+
     | ceil(3.5) | floor(3.5) |
     +-----------+------------+
     |         4 |          3 |
     +-----------+------------+
     mysql> select rand();
     +--------------------+
     | rand()             |
     +--------------------+
     | 0.7286413234925282 |

字符串函数
    char_length(x)     获取字符串x的长度  //字符数
    length(x)           获取字符串x占用的字节数 //字节数
    concat(x1,x2,...)  用于将x1，x2等若干个字符串连接成一个字符串
    ltrim(x)            用于去掉字符串x开头的所有空格字符
    rtrim(x)            用于去掉字符串x结尾的所有空格字符
    trim(x)             用于去掉字符串x开头以及结尾的所有空格字符
    left(x,n)           返回字符串x的前n个字符
    right(x,n)          返回字符串x的后n个字符
    upper(x)            返回将字符串x中的所有字母变成大写字母的字符串
    lower(x)            返回将字符串x中的所有字母变成小写字母的字符串
    substring(x,start,length)  从字符串x的第start个位置开始获取length长度的字符串 //start位正，从左数；start位负，从右数；
 
     mysql> select char_length('张三'),length('张三');
     +-----------------------+------------------+
     | char_length('张三')   | length('张三')   |
     +-----------------------+------------------+
     |                     2 |                6 |
     +-----------------------+------------------+
     
     mysql> select ltrim('    hello');
     +--------------------+
     | ltrim('    hello') |
     +--------------------+
     | hello              |
     +--------------------+

     mysql> select char_length(rtrim('Hello      '));
     +-----------------------------------+
     | char_length(rtrim('Hello      ')) |
     +-----------------------------------+
     |                                 5 |
     +-----------------------------------+
     
     mysql> select left('hello world',5);
     +-----------------------+
     | left('hello world',5) |
     +-----------------------+
     | hello                 |
     +-----------------------+

     mysql> select right('hello world',5);
     +------------------------+
     | right('hello world',5) |
     +------------------------+
     | world                  |
     +------------------------+
     
     mysql> select substring('hello world',1,5);
     +------------------------------+
     | substring('hello world',1,5) |
     +------------------------------+
     | hello                        |
     +------------------------------+
     
     mysql> select substring('hello world',7,5);
     +------------------------------+
     | substring('hello world',7,5) |
     +------------------------------+
     | world                        |
     +------------------------------+

     mysql> select substring('hello world',-5,5);
     +-------------------------------+
     | substring('hello world',-5,5) |
     +-------------------------------+
     | world                         |
     +-------------------------------+

     mysql> select upper('Hello'),lower('Hello');
     +----------------+----------------+
     | upper('Hello') | lower('Hello') |
     +----------------+----------------+
     | HELLO          | hello          |
     +----------------+----------------+

 日期时间函数
    获取MySQL服务器当前日期或时间函数
        curdate() 获取服务器当前日期
        curtime() 获取服务器当前时间
        now() 获取服务器当前日期和时间，并且允许传递一个<=6的整数值作为参数，从而获取更为精确的时间信息
    获取MySQL服务器当前日期或时间函数
        year(x)，month(x),dayofmonth(x),hour(x),minute(x),second(x),microsecond(x)函数分别用于获取日期时间x的年、月、日、时、分、秒、微妙等信息。
 
     mysql> select curdate(),curtime(),now(6);
     +------------+-----------+----------------------------+
     | curdate()  | curtime() | now(6)                     |
     +------------+-----------+----------------------------+
     | 2023-03-14 | 15:02:01  | 2023-03-14 15:02:01.440349 |
     +------------+-----------+----------------------------+
     mysql> select year(curdate()) 年,month(curdate()) 月,dayofmonth(curdate()) 日,
         ->          hour(curtime()) 时,minute(curtime()) 分,second(curtime()) 秒,
         ->          microsecond(now(6)) 微秒, dayname(curdate()) 星期;
     +------+------+------+------+------+------+--------+---------+
     | 年   | 月   | 日   | 时   | 分   | 秒   | 微秒   | 星期    |
     +------+------+------+------+------+------+--------+---------+
     | 2023 |    3 |   14 |   15 |    3 |   41 | 987808 | Tuesday |
     +------+------+------+------+------+------+--------+---------+

  select year(curdate()) 年,month(curdate()) 月,dayofmonth(curdate()) 日,
         hour(curtime()) 时,minute(curtime()) 分,second(curtime()) 秒,
         microsecond(now(6)) 微秒, dayname(curdate()) 星期;

  select week(curdate()) 周, monthname(curdate()) 月份;
  select datediff(curdate(),'2020-01-01');
 
 条件控制函数
    if()函数  类似c语言中的三目运算符
     mysql> select student_no,course_no,score,if(score>=60,'是','否')  是否通过 from choose;
     +------------+-----------+-------+--------------+
     | student_no | course_no | score | 是否通过     |
     +------------+-----------+-------+--------------+
     | 201801     |         2 |    40 | 否           |
     | 201801     |         1 |    50 | 否           |
     | 201802     |         3 |    60 | 是           |
     | 201802     |         2 |    70 | 是           |
     | 201803     |         1 |    80 | 是           |
     | 201804     |         2 |    90 | 是           |
     | 201805     |         3 |  NULL | 否           |
     | 201805     |         1 |  NULL | 否           |
     +------------+-----------+-------+--------------+

    ifnull()函数
        -- 插入测试数据
        desc exam;
        select * from exam;
        insert into exam(regular_score) values(90);
        insert into exam(exam_score) values(80);
        
        -- 测试
        select stu_no,exam_score,regular_score,exam_score*0.8+regular_score*0.2 total_score from exam; -- NULL进行任何运算结果都是NULL
         +--------+------------+---------------+-------------+
         | stu_no | exam_score | regular_score | total_score |
         +--------+------------+---------------+-------------+
         |      1 |         80 |            80 |        80.0 |
         |      2 |         90 |            90 |        90.0 |
         |      3 |         90 |            85 |        89.0 |
         |      4 |       NULL |            90 |        NULL |
         |      5 |         80 |          NULL |        NULL |
         +--------+------------+---------------+-------------+
        
        -- 使用ifnull函数
        select stu_no,exam_score,regular_score,
            ifnull(exam_score,0)*0.8+ifnull(regular_score,0)*0.2 total_score from exam; -- 不空的时候按照原值计算，NULL的时候按0值计算
         +--------+------------+---------------+-------------+
         | stu_no | exam_score | regular_score | total_score |
         +--------+------------+---------------+-------------+
         |      1 |         80 |            80 |        80.0 |
         |      2 |         90 |            90 |        90.0 |
         |      3 |         90 |            85 |        89.0 |
         |      4 |       NULL |            90 |        18.0 |
         |      5 |         80 |          NULL |        64.0 |
         +--------+------------+---------------+-------------+

          create table emp(
             emp_no int primary key auto_increment,
             emp_name char(10),
             salary decimal(7,2) not null, -- 工资
             bonus decimal(7,2)            -- 提成、奖金
          );
          insert into emp values(null,'张三',12000,2000),(null,'李四',13000,null),(null,'王五',10000,5000);
           -- 列出每个员工的年收入
           select emp_no,emp_name,salary,bonus,
              12*(salary + ifnull(bonus,0)) + 20000 年收入 from emp;
 
 */
