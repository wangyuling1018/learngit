//
//  04_decltype3.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//

//平时写代码用不到，只为了后面讲lambda表达式能听得懂，lambda表达式的内部原理有这种书写形式
#if 0
#include <iostream>
#include <typeinfo>
using namespace std;

// 返回值类型 后置
//decltype(x+y)->foo( int x, double y ){  //error,decltype(x+y)不能写在函数的前面，x,y还没定义，不认识x,y,所以decltype(x+y)要写在函数的后面
auto foo( int x, double y )->decltype(x+y) { //计算x+y的类型，作为函数的返回值类型 //编译器从左往右编，所以decltype(x+y)写在函数的后面，形参已经定义了
    return x+y;
}

int main( void ) {
    auto f = foo(10, 3.14);
    cout << "f的类型: " << typeid(f).name() << endl; // d
    return 0;
}

#endif
