//
//  01_auto3.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//

/*
 auto关键字的使用限制：
 1.函数形参类型无法推导（C++14标准支持）
 2.类的成员变量无法推导。-----因为仅仅是声明
 */

#if 0
#include <iostream>
using namespace std;
// 类型推导 的 局限性

void foo( auto v ) { // 11标准中不支持,但14标准支持
    // ...
}

class A {
public:
    auto a; // 声明
    auto b; // 声明
};

int main( void ) {
    foo( 10 );
    return 0;
}


#endif
