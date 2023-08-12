//
//  01_auto1.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//

#if 0
#include <iostream>
using namespace std;

// 类型推导 绝对不是 类型照抄

int main( void ) {
    int a = 10;
    const int b = 20;

    auto c = a;
    // auto: int      c: int
    cout << "c的类型: " << typeid(c).name() << endl; // i
    cout << "&c: " << &c << ", &a: " << &a << endl; // 地址不同
    c++; // 允许更改

    auto d = b;
    // auto: int      d: int
    cout << "d的类型: " << typeid(d).name() << endl; // i
    cout << "&d: " << &d << ", &b: " << &b << endl; // 地址不同
    d++; // 允许更改

    const auto e = b;
    // auto: int      e: const int
    cout << "e的类型: " << typeid(e).name() << endl; // i
    cout << "&e: " << &e << ", &b: " << &b << endl; // 地址不同
//  e++; // 不允许更改

    auto f = &b; // 如果初始化的数据的类型为常指针 则可以自动推导出 const (这是第一种可以自动推断const的情况)
    // auto: const char*      f: const char* === char const*
    cout << "f的类型: " << typeid(f).name() << endl; // PKi
//  *f = 8888; // 不允许更改
    f = NULL;
    return 0;
    //char* const p;指针本身不让修改
    //const char* 和 char const* 写法是一个意思， 常指针，是指针指向的对象不让修改
    //const修饰谁，谁不让修改
}
#endif
