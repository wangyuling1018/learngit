//
//  01_lambda.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//
/*
 lambda表达式：
 1.可以没有返回值类型，将根据return来推断
 2.如果连return也没有，则返回值为void
 3.参数为void可以省略不写的
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
    cout << Max( a, b ) << endl;

    auto f = [](int x, int y)->int { return x > y ? x : y; };
    // 编译器根据lambda表达式  (1)生成一个类  (2)类内定义小括号操作符函数  (3)返回这个类的匿名对象
    /*
    class Z4mainEUliiE_ {
    public:
        int operator()(int x, int y) {
            return x > y ? x : y;
        }
    };
    auto f = Z4mainEUliiE_{}; //auto f = 匿名对象，f是类对象
    */
    cout << f(a,b) << endl; // f.operator()(a,b)
    cout << "f的类型: " << typeid(f).name() << endl;

    // 可以没有返回值类型，将根据return来推断
    cout << [](int x, int y) { return x+y; }(a,b) << endl;
    /*
    class X {
    public:
        auto operator()(int x, int y)->decltype(x+y) {
            return x+y;
        }
    };
    cout << X{}(a,b) << endl; // cout << X{}.operator()(a,b) << endl;
    */

    // 如果没有返回值类型，也没有return，返回值类型为void
    [](int x, int y) {  cout << x << ' ' << y << endl; }(a,b);
    /*
    class XX {
    public:
        void operator()(int x, int y) {
            cout << x << ' ' << y << endl;
        }
    };
    XX{}(a,b); // XX{}.operator()(a,b)
    */

    // 如果没有形参，也可以不写
    []{ cout << "hello world" << endl; }();
    /*
    class XXXX {
    public:
        void operator()(void) {
            cout << "hello world" << endl;
        }
    };
    XXXX{}(); // XXXX{}.operator()()
    */
    return 0;
}

#endif
