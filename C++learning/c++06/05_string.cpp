//
//  05_string.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/18.
//

#if  0
//C++标准库类---string类
// C++标准库设计的string类-->类中有一个成员变量m_psz(char*)
#include <iostream>
#include <cstring>
using namespace std;

//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    string s1("hello");// 定义s1,利用s1.string("hello") --> s1维护的字符串为"hello"
    cout << "s1:" << s1.c_str() << endl;
    cout << "s1:" << s1 << endl;
    
    //如果是初始化，并且“=”两边的类型完全相同，那么写=xxx 和（xxx）无差别
    string s2 = s1;//=s1; 定义s2,利用s2.string(s1) --> s2维护的字符串 和 s1维护的字符串 内容相同
    cout << "s2:" << s2.c_str() << endl;
    cout << "s2:" << s2 << endl;
    
    string s3; // 定义s3,利用s3.string() --> s3维护的字符串为"\0"
    cout << "s3被赋值前:" << s3.c_str() << endl;
    cout << "s3被福之前:" << s3 << endl;

    // 如果是赋值,并且"="两边类型完全相同,那么触发operator=函数的调用
    s3 = s2; // s3.operator=(s2) ---> s3维护的字符串 和 s2维护的字符串 内容相同
    cout << "s3被赋值后:" << s3.c_str() << endl;
    cout << "s3被赋值后:" << s3 << endl;

    // 无论是初始化还是赋值，只要"="两边类型不同，编译器将"="右边的数据类型 转成和"="左边的类型一致
    string s4 = "hello";//"hello"的类型是const char*
    // 定义 匿名string类对象，利用 匿名string类对象.string("hello")-->匿名string类对象维护的"hello"
    // string s4 = 匿名string类对象; --> s4维护的字符串 和 匿名string类对象维护的字符串 内容相同
    // ---> s4维护的字符串为"hello"
    cout << "s4:" << s4.c_str() << endl;
    cout << "s4:" << s4 << endl;
    
    string s5;
    cout << "s5被赋值前:" << s5.c_str() << endl;
    cout << "s5被赋值前:" << s5 << endl;

    s5 = "hello";
    // 定义 匿名string类对象，利用 匿名string类对象.string("hello")-->匿名string类对象维护的"hello"
    // s5 = 匿名string类对象 --> s5维护的字符串 和 匿名string类对象维护的字符串 内容相同
    // ---> s5维护的字符串为 "hello"
    cout << "s5被赋值后:" << s5.c_str() << endl;
    cout << "s5被赋值后:" << s5 << endl;

    return 0;
}

#endif

