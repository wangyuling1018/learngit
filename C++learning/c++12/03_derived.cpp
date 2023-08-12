//
//  03_derived.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0
//继承是弱继承，不是拥有，只是可以使用
//继承与派生 是一个意思，继承是站在子类的角度，派生是站在基类的角度

/*
 3种继承最最基本的特点：
 1.子类对象 内部包含 基类（子）对象。（基类子对象就是基类对象，只是形容它小）
 2.子类内部 可以访问 基类的 非私有（公有/保护）成员（变量/函数）
 */

//继承的本质：基类的非私有成员在子类中仅仅为可见，而非拥有
//注意：对于继承切忌不要理解为基类的成员变为子类的成员，继承不会改变类成员的作用域，基类的成员永远都是基类的成员，并不会因为继承而变成子类成员。

//友元不可以继承。（是爸爸的朋友，不一定是儿子的朋友）


//继承最最基本的特点
#include <iostream>
using namespace std;
class Base{
public:
    int m_a;
    void foo() { cout << "Base::foo()" << endl;}
protected:
    int m_b;
    void bar() { cout << "Base::bar()" << endl; }
private:
    int m_c;
    void hum() { cout << "Base::hum()" << endl; }
};

class Derived : private Base{
//class Derived : protected Base{
//class Derived : public Base{
public:
    void fun(){
        m_a = 100;//ok
        foo();//ok,子类内部 可以访问 基类的公有成员
        m_b = 200;//ok
        bar();//ok,子类内部 可以访问 基类的保护成员
        //m_c = 300;//error
        //hum();//error,子类内部 不能访问 基类的私有成员
    }
private:
    int m_d;
};


//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    Base b; // |m_a m_b m_c|
    cout << "基类对象b的大小: " << sizeof(b) << endl; // 12
    Derived d; // |基类子对象 m_d| ==> |m_a m_b m_c|m_d| ==> 子类对象 内部包含 基类(子)对象
    cout << "子类对象d的大小: " << sizeof(d) << endl; // 16
    d.fun();
    return 0;
}
#endif


