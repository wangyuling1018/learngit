-- 删除数据库
DROP DATABASE IF EXISTS emp;
-- 创建数据库
CREATE DATABASE IF NOT EXISTS emp;
-- 设置当前数据库
USE emp;
-- 创建表
-- 部门表 dept
CREATE TABLE IF NOT EXISTS dept(
     id  INT PRIMARY KEY AUTO_INCREMENT,   -- 部门编号
     name CHAR(20) NOT NULL                        -- 部门名称
);
-- 员工表
CREATE TABLE IF NOT EXISTS emp(
    emp_no INT PRIMARY KEY,               -- 工号  主键
    emp_name CHAR(10) NOT NULL,      -- 姓名 非空
    dept_id  INT,                                     -- 部门编号 外键
    title CHAR(20),                                 -- 岗位
    manager_id INT,                              -- 主管id
    salary DECIMAL(7,2),                        -- 工资 
    CONSTRAINT dept_emp_id FOREIGN KEY(dept_id) REFERENCES dept(id) 
);
