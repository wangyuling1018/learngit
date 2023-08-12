//
//  impname.cpp
//  C++11
//
//  Created by 王育玲 on 2023/2/17.
//

#if 0
 
//名字空间声明
#include <iostream>
using namespace std;
namespace ns{//定义在这里是进程级的生命周期
    int g_value = 0;
}

//int g_value = 0;//在main中可见表中
//using ns::g_value;//在main中可见表中
int main(void){
    //int g_value = 0;//在main中的定义表中，编译器报错，15行与16行重声明，重定义了
    using ns::g_value;//名字空间声明，从这行代码，ns中的g_value引入当前作用域（相当于定义），在main中的定义表中
    g_value = 8888;//在main中的定义表中
    /*相当于定义 与 真正定义 的区别：
    相同点：都出现在定义表中。
    不同点：生命周期不一样，真正定义（15行）是main函数的生命周期，相当定义（16行）的生命周期是进程级生命周期。
    */
    /*
     不允许在定义表中出现同名的标识符，定义表中只要出现同名的，编译器直接报错。
     可见表可以出现同名的标识符，编译器不报错，只是访问的时候编译器不知道该选谁。
     */
    cout << "ns::g_value = " << g_value << endl;
    return 0;
}

#endif
