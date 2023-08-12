//
//  09_virtual.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/3.
//
/*类模板中的成员虚函数
 1.类模板中的 普通成员函数 可以是虚函数
    即可以为类定义成员虚函数，和普通类的成员虚函数一样，类模板的成员虚函数也可以表现出多态型。
 2.类模板中的 成员函数模板 不可以是虚函数
    根据成员虚函数的多态机制，需要一个虚函数表（表中保存成员虚函数的入口地址），而这个表是编译器在实例化类模板时就产生，类的成员函数模板的实例化（即产生真正的函数实体）需要编译器处理完调用后才会完成，这时才出现成员虚函数的地址。
 
 总结：成员函数模板的延迟编译 阻碍类虚函数表的静态构建
 
 */

#if 0
#include <iostream>
using namespace std;
//类模板中的成员虚函数

template<typename T>class Base{
public:
    virtual void foo(){ //普通成员函数可以是虚函数
        cout << "Base<T>::foo()" << endl;
    }
    
    //成员函数模板不可以是虚函数
    //virtual template<typename M>void Func(){}
};

template<typename T,typename D>class Derived : public Base<T>{
public:
    void foo(){
        cout << "Derived<T,D>::foo()" << endl;
    }
};
int main(){
    Derived<int, double> d;//实例化类时 就有虚函数表，表中有foo()地址 ，表中无Func()地址。
    Base<int>* pBase = &d;
    pBase->foo(); //可以表现出多态性
    
    //d.Func<int>(); //调用的时候，类中才有这个函数，才会被实例化，此时已经无法将Func()地址加入虚函数表了
}
#endif
