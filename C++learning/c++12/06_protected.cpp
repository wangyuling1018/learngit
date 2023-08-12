//
//  06_protected.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/23.
//
/*
 3种继承方式的差别：
 1.基类中的公有、保护和私有成员，在子类中将对这些基类成员的访问控制限定进行重新标记。
 2.当“通过”子类访问其所继承的基类的成员时，需要考虑因继承方式对访问控制限定的影响。---意思是：利用子类对象，在类的外部 能否访问基类的某个成员，编译器查看这个成员在子类中的 重新标记
 */

#if 0
//验证 protected继承
#include <iostream>
using namespace std;
class Base{
public://原始标记
    int m_a;
    void foo() { cout << "Base::foo()" << endl;}
protected://原始标记
    int m_b;
    void bar() { cout << "Base::bar()" << endl; }
private://原始标记
    int m_c;
    void hum() { cout << "Base::hum()" << endl; }
};


class Derived : protected Base{//子类将对基类的成员 重新标记访控限定 m_a/foo是protected  m_b/bar是protected m_c/hum是private
public:
    void fun(){//子类内部 能否访问基类的某个成员，编译器查看这个成员的在基类的 原始标记
        m_a = 100;
        foo();
        m_b = 200;
        bar();
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
    Derived d;//利用子类对象，在类的外部 能否访问基类的某个成员，编译器查看这个成员在子类中的 重新标记
    //d.m_a = 1000;//error
   // d.foo();//error
   // d.m_b = 2000;//error
   // d.bar();//error
  //  d.m_c = 3000;//error
  //  d.hum();//error
    
    return 0;
}

#endif

