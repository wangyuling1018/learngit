//
//  21_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/15.
//

//DML操作-delete操作
#if 0
#include <iostream>
#include <mysql.h>
#include <stdio.h>
using namespace std;
int main(void){
    MYSQL* mysql;
    char stuno[15];   //学号
    char sqlstr[200]; //sql语句
    int num_rows;     //影响的行数
    mysql = mysql_init(NULL);
    mysql = mysql_real_connect(mysql, "localhost", "root", "!QAZ2wsx3edc", "choose", 0, NULL, 0);
    if(!mysql){
        cout << "连接失败，" << mysql_error(mysql) << endl;
        return -1;
    }
    cout << "请输入要删除的学生的学号：";
    cin >> stuno;
    sprintf(sqlstr, "delete from student where student_no='%s'",stuno);
    cout << sqlstr << endl;
    
    //设置字符集
    mysql_query(mysql,"set character set utf8");
    //删除学生信息
    if(!mysql_query(mysql, sqlstr)){//0:成功，非0:失败
        num_rows = mysql_affected_rows(mysql);
        if(num_rows)
            cout << "删除成功" << endl;
        else
            cout << "该学生不存在" << endl;
    }else{
        cout << "删除失败" << endl;
    }
    
    mysql_close(mysql);
    

    return 0;
}
#endif
