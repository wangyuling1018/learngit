//
//  02_decltype1.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//

#if 0
#include <iostream>
using namespace std;
//类型推导 和 类型计算 的差别(类型计算确定类型更加精准，初始值更加灵活)
int main( void ) {
    const int a = 10;
    
    auto b = a;
    // b:int
    cout << "b的类型：" << typeid(b).name() << endl; //i，int类型
    cout <<"&b:" << &b << " ,&a:" << &a << endl;// 地址不同，表示不是引用
    b++;//允许更改，表示不是const
    
    decltype(a) c = 100;//a;
    // c: const int
    cout << "c的类型：" << typeid(c).name() << endl;//i，int类型
    cout <<"&c:" << &c << " ,&a:" << &a << endl;// 地址不同，表示不是引用
   // c++;//不允许更改，表示是const
    return 0;
}

#endif
