//
//  02_convcmp.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0

#include <iostream>
using namespace std;
// 多重继承 - 类型转换的问题
class A {
public:
    int m_a;
};
class B {
public:
    int m_b;
};
class C {
public:
    int m_c;
};
class D : public A, public B, public C { // 汇聚子类
public:
    int m_d;
};
// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    D d; // |A基类子对象|B基类子对象|C基类子对象|m_d| ==> |m_a|m_b|m_c|m_d|
    cout << "汇聚子类对象d的大小: " << sizeof(d) << endl; // 16

    D* pd = &d;
    cout << "整个汇聚子类对象的首地址 D* pd:" << pd << endl;
    cout << "A基类子对象的首地址: " << &d.m_a << endl;
    cout << "B基类子对象的首地址: " << &d.m_b << endl;
    cout << "C基类子对象的首地址: " << &d.m_c << endl;
    cout << "D类自己的成员 &m_d : " << &d.m_d << endl;
    
    //子类型指针--->各个基类型指针
    //多重继承，转出来的各个基类指针就是指向各个基类子对象，保证指针的类型和对象的类型一致，不但把指针的类型改了，还把指针指向的位置也改了。
    cout << "-------------隐式转换------------" << endl;
    A* pa = pd;
    cout << "D* pd--->A* pa: " << pa << endl;
    B* pb = pd;
    cout << "D* pd--->B* pb: " << pb << endl;
    C* pc = pd;
    cout << "D* pd--->C* pc: " << pc << endl;

    //各个基类型指针 ---> 子类型指针
    //
    cout << "-------------static_cast------------" << endl;
    D* p1 = static_cast<D*>(pa);
    cout << "A* pa--->D* p1: " << p1 << endl;
    D* p2 = static_cast<D*>(pb);
    cout << "B* pb--->D* p2: " << p2 << endl;
    D* p3 = static_cast<D*>(pc);
    cout << "C* pc--->D* p3: " << p3 << endl;
   

    cout << "-------------reinterpret_cast------------" << endl;
    // 多重继承下，不要使用重解释类型转换
    pa = reinterpret_cast<A*>(pd);
    cout << "D* pd--->A* pa: " << pa << endl;
    pb = reinterpret_cast<B*>(pd);
    cout << "D* pd--->B* pb: " << pb << endl;
    pc = reinterpret_cast<C*>(pd);
    cout << "D* pd--->C* pc: " << pc << endl;
    return 0;
} // d.~D()

#endif








