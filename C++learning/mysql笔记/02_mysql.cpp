//
//  01_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/9.
//
/*
 在MySQL命令行下如果输错了命令怎么办
 1.没办法的办法，ctrl+c，完全退出
 2.可以输入\c 废弃本次语句，若输入后没效果是因为未保持当前输入语句完整匹配
 */

/*
 1.主键
    create table student(
        stu_no int primary key,
        stu_name char(8)
    );

    -- 测试
     insert into 表名[(字段列表)] values(值列表);
     insert into student values(1, '张三');
     insert into student values(1, '李四'); #error，主键字段的值不允许重复
     insert into student values(null, '李四'); #error，主键字段的值不允许为空
     select * from student;
 
    #error,一个表中不允许有多个主键
    create table exam(
        exam_class char(10) primary key,
        exam_data date primary key,
        course_name char(15)
    );
    -- 复合键，多个字段绑定一起作为主键 //表示多个字段不能同时一样
    create table exam(
        exam_class char(10),
        exam_data date,
        course_name char(15),
        primary key(exam_class,exam_data)
    );
2.非空约束
    drop table student; -- 删除表
    create table student(
        stu_no int primary key,
        stu_name char(8) not null
    );
    desc student; -- 查看表结构
 
    -- 测试
    insert into student values(1, '张三');
    insert into student values(1, null); #error，stu_name是非空字段
 
3.默认约束
    drop table student; -- 删除表
    create table student(
        stu_no int primary key,
        stu_name char(8) not null,
        class_name char(20) default '2020电子信息01班'
    );
    desc student; -- 查看表结构
 
    -- 测试
    -- 使用默认值
    insert into student values(1, '张三',default);
    insert into student(stu_no,stu_name) values(2,'李四'); #class_name使用默认值
    -- 不使用默认值
    insert into student values(3,'王五','2020计算机01班');
    
4.唯一约束
    drop table student;
    create table student(
        stu_no int primary key,
        stu_name char(8) not null,
        stu_uid char(20) unique
    );
    desc student;
    
    -- 测试
    insert into student values(1, '张三','123456778888888888');
    insert into student values(2,'李四','123456778888888888');#error，唯一约束字段的值不允许重复
    -- 唯一约束字段允许为空，并且空值可以有多个(因为null表示的是未定义，2个都是空也不认为是相等的，空值可以是任意值，也什么值都不是，空值等于空值，本身就是一个错误)
    insert into student values(2, '李四',null);
    insert into student values(3, '李四',null);
         +--------+----------+--------------------+
         | stu_no | stu_name | stu_uid            |
         +--------+----------+--------------------+
         |      1 | 张三     | 123456778888888888 |
         |      2 | 李四     | NULL               |
         |      3 | 李四     | NULL               |
         +--------+----------+--------------------+
    
    stu_uid char(20) unique not null
    或
    stu_uid char(20) not null unique
 
 5 外键约束
   drop table student;
   1) 如果创建表时添加外键约束，必须先创建主表，然后再创建从表
   -- 创建班级表
   create table classes(
      class_no int primary key,
      class_name char(20) not null unique
   );
   -- 创建学生表
   create table student(
     stu_no char(11) primary key,
     stu_name char(10) not null,
     c_no int,
     constraint classes_student_fk foreign key(c_no) references classes(class_no)
   );

   2)外键约束必须在从表中添加，外键字段引用的主表中的字段必须是唯一性字段，通常使用主键。
   3)外键字段的值必须来自于主表的对应字段，或者为空
   # 错误 违反了外键约束 在主表classes中没有class_no=1的数据
   insert into student values('1001','张三',1);
  
   insert into classes values(1,'csdot2004');
   insert into student values('1001','张三',1);
   -- 外键字段的值允许为空
   insert into student values('1002','李四',null);
   4) 删除表时，应该先删除从表，然后删除主表
    drop table student;
    drop table classes;

 6. 自增长
   创建班级表，班号为自增长
   create table classes(
      class_no int auto_increment primary key,
      class_name char(20)
   );
   -- 测试
   insert into classes values(null,'csdot2004');
   insert into classes(class_name) values('csdot2005');
   insert into classes values(3,'csdot2006'); -- 不推荐
 
 7、 复制表结构
  create table exam1 like exam;-- 外键约束无法复制，其他约束都可以复制

  create table exam2 select * from exam; -- 用结果集创建新表，即复制表结构，又复制了表中的数据
 
 8.创建"选课系统"数据库
   -- 班级表
   create table classes(
      class_no int primary key auto_increment,
      class_name char(20) unique not null,
      department_name char(20) not null
   );
    
 
   -- 教师表
   create table teacher(
      teacher_no char(10) primary key,
      teacher_name char(10) not null,
      teacher_contact char(20) not null
   );

   -- 学生表
   create table student(
      student_no char(11) primary key,
      student_name char(10) not null,
      student_contact char(20) not null,
      class_no int,
      constraint classes_student_fk foreign key(class_no) references classes(class_no)
   );
 
   -- 课程表
   create table course(
     course_no int auto_increment primary key,
     course_name char(10) not null,
     up_limit int default 60,
     description varchar(100) not null,
     status char(6) default '未审核',
     teacher_no char(10) not null unique,
     constraint teacher_course_fk foreign key(teacher_no) references teacher(teacher_no)
   );

   -- 选课表
   create table choose(
      choose_no int auto_increment primary key,
      student_no char(11) not null,
      course_no int not null,
      score tinyint unsigned,
      choose_time datetime not null,
      constraint student_choose_fk foreign key(student_no) references student(student_no),
      constraint course_choose_fk foreign key(course_no) references course(course_no)
   );
   
 

*/


/*
1. dml操作
1.1 insert
1) 全部字段
 insert into teacher(teacher_no,teacher_name,teacher_contact)
      values('001','李老师','11000000000');-- 字段列表可以只写部分字段，如果写入的是全部字段，字段列表可以省略
 insert into teacher(teacher_name,teacher_no,teacher_contact)
      values('王老师','002','12000000000');-- 字段列表顺序可以随意，值列表必须和字段列表匹配
 insert into teacher values('003','孙老师','13000000000');-- 给全部字段
2) 自增长
 insert into classes values(null,'2018自动化1班','机电工程');-- 常用方式
 insert into classes(class_name,department_name) values('2018自动化2班','机电工程');-- 不提供自增长字段的数据，只提供其他字段的数据，
 insert into classes values(3,'2018自动化3班','机电工程'); -- 不推荐使用的方式
3) 默认值
 -- 使用默认值
 insert into course values(null,'C语言',default,'暂无','已审核','001');
 或
 insert into course(course_name,description,status,teacher_no)
     values('C语言','暂无','已审核','001');-- 自增长、默认值的都可以不赋值
 -- 不使用默认值
 insert into course values(null,'MySQL',150,'暂无','已审核','002');
 # 错误  违反了 teacher_no字段的唯一约束
 insert into course values(null,'Java',230,'暂无','已审核','002');
 # 错误 违反了外键约束
 insert into course values(null,'Java',230,'暂无','已审核','004');
 -- course_no=5
 insert into course values(null,'Java',230,'暂无','已审核','003');-- 自增长字段，写数据不能保证是连续的，但是一定能保证是增长的，错误的插入会占用自增长的序号

4) 批量插入
 insert into student values
 ('2018001','张三','15000000000',1),
 ('2018002','李四','16000000000',1),
 ('2018003','王五','17000000000',3),
 ('2018004','马六','18000000000',2),
 ('2018005','田七','19000000000',2);
5) insert...select语句
 -- 对表中的数据进行备份
 create table stu like student; -- 创建一个不包含数据的表
 insert into stu select * from student; -- 将表的数据写入新表

1.2 update
 -- 把 course表中 course_no=5的数据更改为 course_no=3
 update course set course_no=3 where course_no=5;
 -- 创建score表
 create table score(
   stu_no int primary key auto_increment,
   exam_score tinyint unsigned,
   regular_score tinyint unsigned
 );
 -- 测试数据
 insert into score values
 (null,100,80),
 (null,50,90),
 (null,67,80),
 (null,80,85),
 (null,30,50);
 -- 更新
 -- 每人加5分（ 没有where子句）
 update score set exam_score=exam_score+5;
 -- 100分封顶（ 有where子句）
 update score set exam_score=100 where exam_score>100;
 -- 55~59之间的改为60（ 有where子句）
 update score set exam_score=60 where exam_score>=55 and exam_score<=59;
 
 -- 更新多个字段
 update student set student_name='张三丰',class_no=2 where student_no='2018001';
 # 错误 违反了外键约束 class_no=4在主表中不存在
 update student set student_name='张三丰',class_no=4 where student_no='2018001';
 # 错误 违反了外键约束 class_no=1的数据被子表引用
 update classes set class_no=4 where class_no=1;

1.3 delete语句
 delete from score where exam_score<60;
 delete from score;-- 清空表，删除表中所有数据，无where子句
 # 错误 违反了外键约束 主表数据被子表引用
 delete from classes;

 -- 总结：
 -- 向主表中更新、删除数据有可能违法外键约束，写入数据没有问题
 -- 向子表中添加、更新数据有可能违法外键约束，删除数据没有问题
 
 insert into score values(null,80,70);

 delete from student; // 成功  choose中没有数据

1.4 truncate语句
 // truncate不能应用与主表(即使从表中没有数据)
 truncate table student;
 
 // 使用truncate截断表，自增长字段的值恢复初始值
 insert into exam values(null,80,80);
 truncate table score;-- 清空表
 insert into exam values(null,80,80);
 
 

*/


