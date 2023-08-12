//
//  06_except2.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//
/*
 1.异常说明可以没有，也可以为空
    没有异常说明，表示可能抛出任何类型的异常
        void foo(void) {...}
    异常说明为空，表示不会抛出任何类型的异常
        void foo(void) throw() {...}
 2.异常说明是虚函数覆盖的条件之一
    如果基类版本带有基类类型异常说明，那么覆盖版本必须一致，但如果基类版本带有类类型异常说明，那么覆盖版本可以带有子类类型异常说明
 3.异常说明在函数的声明和定义中必须保持严格一致，否则将导致编译错误
 */

#if 0
#include <iostream>
using namespace std;
// 没有异常说明  和  异常说明为空

void foo( )  { // 没有异常说明
    throw "hello world"; // 3.14; // -1;
}

void bar( ) throw() { // 异常说明为空
    throw -1;
}

void hum() throw(int,double); // 声明

void hum() throw(int,double) { // 定义
    // ...
}

// 以上的代码模拟库
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    try {
        foo( );
//        bar( );
    }
    catch( ... ) { // 捕获异常 但不处理 //3个点表示代表任何类型
        // ...
    }
    /*
    catch( int& e ) {
        cout << "1. 捕获异常信息: " << e << endl;
    }
    catch( double& e ) {
        cout << "2. 捕获异常信息: " << e << endl;
    }
    catch( const char* e ) {
        cout << "3. 捕获异常信息: " << e << endl;
    }
    */
    return 0;
}
#endif

