//
//  20_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/15.
//

//DML操作-update操作
#if 0
#include <iostream>
#include <mysql.h>
#include <stdio.h>
using namespace std;
int main(void){
    MYSQL* mysql;
    char stuno[15];   //学号
    char stuname[15]; //姓名
    char phone[20];   //联系方式
    int cno;          // 班号
    char sqlstr[200]; //sql语句
    int num_rows;     //影响的行数
    mysql = mysql_init(NULL);
    mysql = mysql_real_connect(mysql, "localhost", "root", "!QAZ2wsx3edc", "choose", 0, NULL, 0);
    if(!mysql){
        cout << "连接失败，" << mysql_error(mysql) << endl;
        return -1;
    }
    cout << "请输入要修改的学生的学号：";
    cin >> stuno;
    cout << "请输入姓名：";
    cin >> stuname;
    cout << "请输入手机号码：";
    cin >> phone;
    cout << "请输入班号：";
    cin >> cno;
    sprintf(sqlstr, "update student set student_name='%s',student_contact='%s',class_no=%d where student_no='%s'",stuname,phone,cno,stuno);
    cout << sqlstr << endl;
    
    //设置字符集
    mysql_query(mysql,"set character set utf8");
    //更新数据
    if(!mysql_query(mysql, sqlstr)){//0:成功，非0:失败
        num_rows = mysql_affected_rows(mysql);
        if(num_rows)
            cout << "更新成功" << endl;
        else
            cout << "该学生不存在" << endl;
    }else{
        cout << "更新失败" << endl;
    }
    
    mysql_close(mysql);
    

    return 0;
}
#endif

