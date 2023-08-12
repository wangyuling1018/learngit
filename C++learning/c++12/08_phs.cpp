//
//  08_phs.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

/*
 公有继承独有的特点：
 1.只有在公有继承下，子类对象在类的外部 可以访问 基类的公有成员，其他继承不可以
 2.只有在公有继承下，子类类型的指针 和 基类类型的指针 可以进行转换
                  子类类型的引用 和 基类类型的引用 可以进行转换
                  其他继承方式不可以。
 
 
 关于指针的一个原理探讨：
   指针为什么需要类型？答：指针的类型 决定了 指针的眼界（*） 和 步长（+1）
    int* pa;  *pa (站在pa指针上可以看到4个字节)   pa+1（加1，pa可以移动4个字节）
    double* pb;  *pb(站在pb指针上可以看到8个字节)    pb+1(加1，pb可以移动8个字节）
    short* pc;   *pc(站在pc指针上可以看到2个字节)    pc+1(加1，pc可以移动2个字节)
    char* pd;    *pd(站在pd指针上可以看到1个字节)    pd+1(加1，pd可以移动1个字节)
*/

//编译器认为访问访问缩小是安全的


#if 0

#include <iostream>
#include <cstring>
using namespace std;
class Base {
public:
    int m_a;
    void foo( ) {   cout << "Base::foo" << endl;    }
protected:
    int m_b;
    void bar( ) {   cout << "Base::bar" << endl;    }
private:
    int m_c;
    void hum( ) {   cout << "Base::hum" << endl;    }
};
class Derived : public Base {
public:
    void foo( ) {   cout << "Derived::foo" << endl; }
private:
    int m_d;
};
// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    Derived d;
    d.m_a = 1000; // ok
    d.Base::foo( );     // ok,只有在公有继承下，子类对象在类的外部 可以访问 基类的公有成员，其他继承不可以
    return 0;
}

#endif
 
