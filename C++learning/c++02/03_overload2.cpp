//
//  03_overload2.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/17.
//

#if 0
//详谈重载函数同一个作用域
#include <iostream>
using namespace std;

namespace ns1{
    void foo( char* c,short s){
        cout << "1.foo(char*,short)"<< endl;
    }
    void foo(int i,double d){
        cout << "2.foo(int,double)"<< endl;
    }
}
namespace ns2{
    void foo(const char*, short s){
        cout << "3.foo(const char*,short)"<< endl;
    }
    void foo(double d, int i){
        cout << "4.foo(double,int)" << endl;
    }
}



int main( void ){
    using namespace ns1; //名字空间指令（ns1中的foo在当前作用域可见，出现在可见表中）
    using ns2::foo;//名字空间声明（ns2中的foo引入当前作用域-相当于定义，出现在定义表中），ns1中的foo和ns2中的foo互为隐藏关系
    //using namespace ns2; ////名字空间指令（ns2中的foo在当前作用域可见，出现在可见表中），ns1中的foo和ns2中的foo互为重载关系
    
    char* c; short s;
    foo(c,s);//调用第3个,因为第3个foo把第1个foo隐藏了
    //如果都出现在定义表，或者都出现在可见表，就是重载关系。
    //如果一部分出现在定义表，一部分出现在可见表，就是隐藏关系。
    
    return 0;
}

#endif

