//
//  07_lambda.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//

//lambda表达式，既不是表达式，也不是函数，本质是一个类。
//lambda表达式一般写在一行

/*
 lambda表达式 语法规则：
 [捕获表]（参数表）选项 -> 返回类型 { 函数体; };  //选项 一般不用
 
 lambda表达式的名称是一个表达式（外观类似函数），但本质绝非如此
 本质：lambda表达式本质是一个类，并且最终返回值为这个类的对象，因此对lambda表达式的调用就是对该对象的 函数操作符（小括号操作符） 的调用。
 */


#if 0
#include <iostream>
#include <typeinfo>
using namespace std;

// lambda表达式

int Max( int x, int y ) {
    return x > y ? x : y;
}

int main( void ) {
    int a=10, b=20;
    cout << Max( a, b ) << endl;//03、98标准解决比较大小问题

    auto f = [](int x, int y)->int { return x > y ? x : y; };
    // 编译器根据lambda表达式  (1)生成一个类  (2)类内定义小括号操作符函数  (3)返回这个类的匿名对象
    /*
    class Z4mainEUliiE_ {//main函数中有类类型
    public:
        int operator()(int x, int y) {
            return x > y ? x : y;
        }
    };
    auto f = Z4mainEUliiE_{};  // f是类对象
    */
    cout << f(a,b) << endl; // f.operator()(a,b)
    cout << "f的类型: " << typeid(f).name() << endl;
    return 0;
}



#endif
