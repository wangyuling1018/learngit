//
//  02_overload.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/17.
//

#if 0
//函数之间的关系 - 重载（1.同一作用域内。 2.函数名相同。 3.参数表不同）
//形参表是否相同 与 形参名无关，与 形参个数 和 每个对应形参的类型（形参类型的顺序） 有关
#include <iostream>
using namespace std;

//c语言不允许出现同名函数
void foo( char* c,short s){
    cout << "1.foo(char*,short)"<< endl;
}
void foo(int i,double d){
    cout << "2.foo(int,double)"<< endl;
}
void foo(const char*, short s){
    cout << "3.foo(const char*,short)"<< endl;
}
void foo(double d, int i){
    cout << "4.foo(double,int)" << endl;
}

//int foo(double d,int i){} // 不互为重载关系，是否为重载关系，和返回值类型毫无关系
//void foo(int d, double i){}// 不互为重载关系，是否为重载关系，和形参名无关


int main( void ){
    char* c; short s;//实参
    foo(c,s);//调用第1个,根据实参类型进行匹配，调用最匹配的函数
    const char* cc;
    foo(cc,s);//调用第3个
    int i; double d;
    foo(i,d);//调用第2个
    foo(d,i);//调用第4个
    return 0;
}
#endif
