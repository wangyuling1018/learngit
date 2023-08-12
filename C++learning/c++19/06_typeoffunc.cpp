//
//  06_typeoffunc.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//

//C++语法中函数作用域不能再定义函数，因此没有所谓的局部函数的概念

#if 0
#include <iostream>
using namespace std;
// 函数内部 不能定义 函数
/*
void foo( ) {
    int a = 10; // ok,函数内部可以有变量
    cout << 2*a << endl; // ok,函数内部可以有 表达式 和 语句

    void bar( ) { // error,函数内部 不可以 有函数
        cout << "bar() is invoked" << endl;
    }
}
*/
// 函数内部 可以有 类型
// 编译器针对这种情况(函数内部有类型)如何工作:(1)先编译函数内部的类型 (2)再编译函数本身的代码
/*
int a;
void foo( int b ) {
    int c;
    class A {
    public:
        void bar( int d ) {
            a = 100;
//          b = 200; // error，编译器 编类型A的时候，foo函数还没编译，这时候是看不到foo函数的
//          c = 300; // error，编译器 编类型A的时候，foo函数还没编译，这时候是看不到foo函数的
            d = 400;
        }
    };
}
*/

// 成员函数内部 也可以有 类型
// 编译器针对这种情况(函数内部有类型)如何工作:(1)先编译函数内部的类型 (2)再编译函数本身的代码
int a;
class A {
public:
    void foo( /* A* this */ int b ) {
        class B {
        public:
            void bar( /* B* this */ int c ) {
                a = 100;//先找bar范围->B范围->A范围,跳过foo范围，foo看不到
//              b = 200; // error
                c = 300;
                d = 400;
//              e = 500; // error，普通成员变量  要么 对象调用，要么 this指针调用，foo函数中补的this看不到
            }
        };
    }
private:
    static int d;
    int e;
};
int A::d;

int main( void ) {
    
    return 0;
}

#endif
