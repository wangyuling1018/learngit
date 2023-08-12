//
//  03_decltype2.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//
//标识符：就是名字

#if 0
#include <iostream>
using namespace std;

//类型计算的4种规则
double foo( int x, int y );//仅仅声明也可以计算出

int main( void ) {
    //如果传递的为标识符表达式，编译器将根据标识符本身的类型，作为最终计算出的类型
    int a;
    decltype(a) c = a;
    //  c: int
    cout << "c的类型: " << typeid(c).name() << endl; // i
    cout << "&c:" << &c << ", &a:" << &a << endl;    // 地址不同，不是引用
    c++; // 允许更改
    
    // 如果传递的为函数表达式,编译器将根据函数返回值的类型，作为最终计算出的类型
    decltype( foo(10,20) ) d = a;//编译器在编译的时候，计算类型，并不会生成跳转指令去调用函数，函数内部没有执行。
    //  d: double
    cout << "d的类型: " << typeid(d).name() << endl; // d，double类型
    cout << "&d:" << &d << ", &a:" << &a << endl;    // 地址不同，不是引用
    d++; // 允许更改

    // 如果传递的为其他表达式 并且表达式的结果为左值，编译器将该左值引用类型，作为最终计算出的类型
    decltype(++a) e = a;
    //  e: int&  //e是a的别名
    cout << "e的类型: " << typeid(e).name() << endl; // i
    cout << "&e:" << &e << ", &a:" << &a << endl;    // 地址相同，是引用
    e++; // 允许更改

    // 如果传递的为其他表达式 并且表达式的结果为右值，编译器将该右值本身的类型 最为最终计算出的类型
    decltype(a++) f = a;
    //  f: int   //f是独立变量，不是a的别名
    cout << "f的类型: " << typeid(f).name() << endl; // i
    cout << "&f:" << &f << ", &a:" << &a << endl;    // 地址不同
    f++; // 允许更改

    return 0;
}

#endif
