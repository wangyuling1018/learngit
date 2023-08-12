//
//  Human.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/18.
//
#if 0
#include "Human.hpp"
#include <iostream>
using namespace std;
Human::Human(/* Human* this */ int age,const char* name){//定义
    //在this所指向的内存空中定义m_age（给m_age分配内存空间）初值为随机数
    //在this所指向占的内存空中定义m_name（给m_name分配内存空间）初值为随机数
    cout << "Human类的构造函数被调用" << endl;
    this->m_age = age;
    strcpy(this->m_name,name);
}
void Human::getinfo(/* Human* this */ ){//定义
    cout << "姓名：" << this->m_name << "，年龄：" << this->m_age << endl;
}
#endif

