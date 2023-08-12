//
//  04_hide.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//
#if 0
/*
 继承的基本特点：
 1.尽管基类的公有和保护成员在子类中直接可见，但仍然可以在子类中重新定义这些名字，子类中的名字会隐藏所有基类中的同名定义
 2.如果需要在子类内部访问一个基类中定义却被子类标识符所隐藏的名字，可以借助作用域限定操作符“：：”实现
 */
//只要是隐藏 就涉及 可见表 和 定义表 的关系


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
        m_a = 100;
        Base::foo();//子类的foo函数将基类的foo函数隐藏,但利用作用域限定符 可以直接 调用基类的foo
        m_b = 200;
        bar();//子类的bar函数将基类的bar函数隐藏
        //m_c = 300;//error
        //hum();//error,子类内部 不能访问 基类的私有成员
    }
private:
    int m_d;
    void foo() { cout << "Derived::foo()" << endl;}
    void bar() { cout << "Derived::bar()" << endl; }
};


//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    Derived d;
    d.fun();
    return 0;
}
#endif

