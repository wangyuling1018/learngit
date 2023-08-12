//
//  05_except.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//

//在C语言中函数原型 包括：函数名、返回值、形参表
//在C++语言中函数原型 包括：函数名、返回值、形参表、异常说明
/*异常说明
 1.异常说明是函数原型的一部分，旨在说明函数可能抛出的异常类型。----意思是：函数的声明和定义的书写形式要保持一致，因为异常说明是函数原型的一部分，同时，用户要根据throw的参数表写catch，有几个异常类型，就要写几个捕获类型。
 2.异常说明是一种承诺，承诺函数捕获抛出异常说明以外的异常类型
   如果函数抛出了异常说明以外的异常类型，那么该异常将无法被捕获，并导致进程终止
 3.隐式抛出异常的函数也可以列出它的异常说明。---意思是也可以不列出
 
 */

#if 0

//异常说明：

#include <iostream>
using namespace std;
// 异常说明:承诺 调用者 绝对不抛出 异常说明 以外 异常类型

void foo( ) throw(int,double,const char*);//声明

void foo( ) throw(int,double,const char*) { // 显示抛出异常 //定义
    throw "hello world"; // 3.14; // -1;  //如果抛出的异常，throw形参表中没有对应的异常类型，不管有没有对应的catch，那么系统就会捕获到，进程则终止
}

void bar( ) throw(int,double,const char*) { // 隐式抛出异常
    foo( );
    // 调用几十个不同函数,而且每个函数都可能抛出异常，并且抛出的异常类型都不相同 //bar函数的异常说明可能要写几百个throw的参数
}


// 以上的代码模拟库
// --------------------------------------
// 以下的代码模拟库的使用者
int main( void ) {
    try {
//        foo( );
        bar( );
    }
    catch( int& e ) {
        cout << "1. 捕获异常信息: " << e << endl;
    }
    catch( double& e ) {
        cout << "2. 捕获异常信息: " << e << endl;
    }
    catch( const char* e ) {
        cout << "3. 捕获异常信息: " << e << endl;
    }
    return 0;
}

#endif
