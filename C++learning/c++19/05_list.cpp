//
//  05_list.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//
/*
 1. 列表初始化 -- 定义对象

   Human{}  === Human()
   Human{25,"关羽"}  === Human(25,"关羽")
   Human h{20,"赵云"};  === Human h (20, "赵云");

 */

#if 0
#include <iostream>
using namespace std;

// 初始化的大一统写法 -- 列表初始化
struct BD {
    int m_year;
    int m_month;
    int m_day;
};
struct Student {
    string m_name;
    int m_age;
    BD m_bday;
};
class Human {
public:
    Human( int age=0, const char* name="无名" ) : m_age{age}, m_name{name} {
        //【string m_name{name};】
        //【int m_age{age};】
    }
    string m_name;
    int m_age;
};
int main( void ) {
    int a{123}; // = 123;
    cout << "a=" << a << endl;
    
    int b[]{123,456,789}; // = {123,456,789};
    for( int i=0; i<sizeof(b)/sizeof(b[0]); i++ ) {
        cout << b[i] << ' ';
    }
    cout << endl;
    
    Student s{"张飞",22,{1997,5,2}}; // = {"张飞", 22, {1997,5,2} };
    cout << s.m_name << ' ' << s.m_age << ' ' << s.m_bday.m_year << '-' << s.m_bday.m_month << '-' << s.m_bday.m_day << endl;
    
    Human h{20,"赵云"}; // (20, "赵云"); 定义h,利用h.Human(20,"赵云")
    cout << "姓名: " << h.m_name << ", 年龄: " << h.m_age << endl;
    
    //Human* ph = new Human(25,"关羽");//原来的写法
    Human* ph{ new Human{25,"关羽"} };// (25,"关羽"); // 定义 Human类堆对象,利用 Human类堆对象.Human(25,"关羽")
    cout << "姓名: " << ph->m_name << ", 年龄: " << ph->m_age << endl;
    delete ph;
    
    return 0;
}

#endif
