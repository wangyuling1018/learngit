//
//  22_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/16.
//



#if 0

#include <iostream>
#include <mysql.h>
#include <stdio.h>
using namespace std;
int main(void){
    MYSQL mysql;
    MYSQL_RES* res;//结果集
    unsigned int num_fields,num_rows; // 列数 、行数
    MYSQL_FIELD* fields; //列的信息
    MYSQL_ROW row;//接收一行数据
    
    mysql_init(&mysql);
    if(!(mysql_real_connect_nonblocking(&mysql, "localhost", "root", "!QAZ2wsx3edc", "choose", 0, NULL, 0))){
        cout << "连接失败：" << mysql_error(&mysql) << endl;
        return -1;
    }
    
    //mysql_query(&mysql, "select * from student");
    mysql_query(&mysql, "set character set utf8");
    //mysql_query(&mysql, "select s.student_no 学号,s.student_name 姓名,c.class_name 班级名称 from student s,calsses c where s.class_no = c.class_no");
    //mysql_query(&mysql, "show tables");
    //mysql_query(&mysql, "desc student");
    res = mysql_store_result(&mysql);//获取结果集
    if(res){
        //cout << "成功获取结果集" << endl;
        num_fields = mysql_num_fields(res);
        num_rows = (int)mysql_num_rows(res);
        cout << "列数：" << num_fields << "," << "行数：" << num_rows << endl;
        fields = mysql_fetch_fields(res);
        int i = 0,j=0;
        //输出列的信息
        for(;i < num_fields;i++){
            cout <<fields[i].name << ", " << fields[i].org_name <<", " << fields[i].table << ", " << fields[i].org_table << ", " << fields[i].db << endl;
            //fields[i].org_name是原字段名，ields[i].name是原字段的别名，fields[i].org_table是原表名，fields[i].table是原表的别名，db是数据库名
        }
        //输出行的信息
        cout << "行的信息：" << endl;
        for(int i=0;i<num_rows;i++){
            row = mysql_fetch_row(res);
            for(j=0;j<num_fields;j++){
                cout << row[j];
            }
            cout << endl;
        }
        
        mysql_free_result(res);//释放结果集
    }

    mysql_close(&mysql);//关闭数据库连接
    
    //getchar();
    
    return 0;
}
#endif
