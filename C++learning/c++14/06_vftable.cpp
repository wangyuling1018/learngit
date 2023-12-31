//
//  06_vftable.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//
/*
 动态绑定：
   当编译器看到通过指针或引用调用虚函数的语句时，并不急于生成有关函数调用的指令，相反它会用一段代码替代该语句，这段代码在运行时才能被执行，完成如下操作：
        1.确定指针或引用的目标对象所占内存空间
        2.从目标对象所占内存空间中找到虚表指针
        3.利用虚表指针找到虚函数表
        4.从虚函数表中获取所调用虚函数的入口地址
        5.根据入口地址，调用该函数
 
 动态绑定对性能的影响：
 1.虚函数表本身会增加进程内存空间的开销
 2.与普通函数调用相比，虚函数调用要多处几个步骤，会增加运行时间的开销
 3.动态绑定会妨碍编译器通过内联来优化代码
 4.只有在确实需要多态特性的场合才使用虚函数，否则尽量使用普通函数
     
 */

#if 0

#include <iostream>
using namespace std;
// 多态解密 -- 虚函数表
class A { // 编译器根据A类信息,将制作一张虚函数表（A::foo的地址   A::bar的地址） //虚函数表 存在 数据段
public:
    virtual void foo( ) {   cout << "A::foo" << endl;   }
    virtual void bar( ) {   cout << "A::bar" << endl;   }
};

class B : public A { // 编译器根据B类信息,将制作一张虚函数表（B::foo的地址   A::bar的地址）//虚函数表 存在 数据段
public:
    void foo( ) {   cout << "B::foo" << endl;   }//如果没有foo函数，编译器根据B类信息,将制作一张虚函数表（A::foo的地址   A::bar的地址）
};

// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    A a; // |虚表指针|-->编译器根据A类信息制作的虚函数表 //代码段存的是a对象中的 虚表指针，因为是64位系统，所以指针占8个字节，虚表指针 指向 虚函数表
    cout << "a对象的大小: " << sizeof(a) << endl;
    B b; // |虚表指针|-->编译器根据B类信息制作的虚函数表
    cout << "b对象的大小: " << sizeof(b) << endl;
    
    //类类型 转 指针 编译器不让转，可以先&a获取a中的指针，变成3级指针，然后接引用*变成2级指针
    void(**pfunc)() = *((void(***)())&a); // 从a所占内存中 获取 虚表指针
    pfunc[0](); // A::foo   //pfunc[0]是A::foo的地址
    pfunc[1](); // A::bar
    
    void(**pfunc2)() = *((void(***)())&b); // 从b所占内存中 获取 虚表指针
    pfunc2[0](); // B::foo
    pfunc2[1](); // A::bar
    
    A* pa = &b;
    pa->foo( ); //B::foo, 编译期间，编译器并不知道 到底调用 哪个类的foo
    // 1.根据pa找到b对象所占内存空间
    // 2.从b对象所占内存空间中获取虚表指针
    // 3.利用虚表指针 找到 编译器根据B类信息制作的虚函数表
    // 4.从虚函数表中获取虚函数的入口地址
    // 5.利用 虚函数的入口地址 调用 函数
}
#endif

