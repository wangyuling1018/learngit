//
//  02_this.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/18.
//
#if 0

//成员函数的形参----this
/*
 哪个对象 调用 成员函数，成员函数的this形参就指向哪个对象
 成员函数内部 都是通过 this指针 访问成员变量的
 
 */

#include <iostream>
using namespace std;
//在这个程序中有两个对象（h/h2），每个对象中各有一份成员变量（共有两份成员变量）。而成员函数只有一份，在代码段
/*成员函数只有一份，那么setinfo函数内部的m_age、m_name是h的？还是h2的？
  除了静态成员函数外，类的每一个成员函数都有一个隐藏的this指针，this指向调用对象。
  哪个对象 调用 成员函数，成员函数的this形参就指向哪个对象
 */
class Human{
public:
    void setinfo(/* Human* this */ int age = 0, const char* name = "无名"){
        this->m_age = age;//编译器只要发现成员函数里面有成员变量，就会在成员变量前自动补this
        strcpy(this->m_name,name);//编译器只要发现成员函数里面有成员变量，就会在成员变量前自动补this
    }
    
    void getinfo(/* Human* this */ ){
        cout << "姓名：" << this->m_name << "，年龄：" << this->m_age << endl;
    }
    
private:
    int m_age;
    char m_name[256];
};



//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    Human h;//定义h（给h分配内存空间）
            //在h中所占内存空中定义m_age（给m_age分配内存空间）初值为随机数
            //在h中所占内存空中定义m_name（给m_name分配内存空间）初值为随机数
    cout << "h的大小：" << sizeof(h) << endl; //260个字节
    h.setinfo(22,"张飞");
    h.getinfo();
    
    Human h2;//定义h2（给h2分配内存空间）
            //在h2中所占内存空中定义m_age（给m_age分配内存空间）初值为随机数
            //在h2中所占内存空中定义m_name（给m_name分配内存空间）初值为随机数
    cout << "h2的大小：" << sizeof(h2) << endl; //260个字节
    h2.setinfo(22,"张飞");
    h2.getinfo();
    
    
    return 0;
}

#endif
 
