//
//  05_twicecompile.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/2.
//
/*
 二次编译
 1.编译器对函数模板都会进行两次编译。
 2.第一次编译发生在实例化函数模板之前（产生真正函数实体之前）只检查函数模板本身内部代码，查看疾病语法是否正确。
    1）函数模板内部出现的所有标识符是否均有声明
    2）对于已知类型的调用要查看调用是否有效
    3）对于未知类型调用认为都合理
 3.第二次编译发生在实例化函数模板之后（产生真正函数实体之后）结合所使用的类型实参，再次检查模板代码，查看所有调用是否真的均有效。
 */

#if 0
#include <iostream>
using namespace std;
class A{
public:
    void func(){
        cout << "A::func()" << endl;
    }
};
template<typename T>void foo(){
    //abc = 10; //error ，标识符没有声明                  1)
    A a;
    a.func();   // ok  已知类型的调用 合理                 2)
    //a.abc();    // error 已知类型的调用 不合理
    T t;
    t.abc();    // 第一次编译 未知类型的调用假定合理  Ok      3)
                // 第二次编译时，再次检查调用是否合理 error
    t.func();
//    t.ab<int>();// error 但是不能出现<>
}

int main(){
    //foo<A>();  //实例化，产生真正函数实体
    return 0;
}
#endif
