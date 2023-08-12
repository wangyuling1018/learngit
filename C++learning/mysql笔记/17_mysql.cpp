//
//  17_mysql.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/15.
//

//连接MySQL

#if 0
#include <mysql.h>
#include <iostream>
using namespace std;
int main()
{
    MYSQL mysql;
    // 初始化MYSQL结构
    mysql_init(&mysql);
    // 连接数据库
    if(!(mysql_real_connect(&mysql, "localhost", "root", "!QAZ2wsx3edc", "choose", 0, NULL, 0))){
        cout << "连接失败" << endl;
        cout << "ERROR " << mysql_errno(&mysql) << ":" << mysql_error(&mysql);
        return -1;
    }
    cout << "连接成功" << endl;
    // 对数据库操作
    
    // 关闭数据库连接
    mysql_close(&mysql);
    
   
    
    return 0;
}

#endif

