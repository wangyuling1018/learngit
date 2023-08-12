//
//  07_consexcept.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//

/*构造函数中的异常：
 构造函数可以抛出异常，某些时候还必须抛出异常：
 1.构造过程中可能遇到各种错误，比如内存分配失败
 2.构造函数没有返回值，无法通过返回值通知调用者
 
 构造函数抛出异常，对象将被不完整构造，而一个被不完整构造的对象，其析构函数永远不会被执行
 1.所有对象形式的成员变量，在抛出异常的瞬间，都能得到正确地析构（构造函数的回滚机制）
 2.所有动态分配的资源，必须在抛出异常之前，自己手动释放，否则将形成资源的泄漏
 
 
 */


#if 0
#include <iostream>
using namespace std;
// 构造函数中的异常
class A {
public:
    A() {   cout << "A() is invoked" << endl;   }
    ~A() {   cout << "~A() is invoked" << endl;   }
};

class C {
public:
    C( ) : m_p(new int) {
        //【A m_a;】定义m_a,利用m_a.A()
        //【int* m_p=new int;】定义m_p,初值为指向一块堆内存(动态资源)
        cout << "C() is invoked" << endl;
        FILE* pfile = fopen("./cfg", "r");
        if( !pfile ) {
            delete m_p; //动态资源，需要手动释放
            // 对于m_a 利用 m_a.~A(）//编译器塞的操作，编译器会自己回滚掉
            // 释放 m_a/m_p 本身所占内存空间  //编译器塞的操作，编译器会自己回滚掉
            throw -1;
        }
        // ...构造函数中后续的代码...
    }
    ~C( ) {
        delete m_p;
        cout << "~C() is invoked" << endl;
        // 对于m_a 利用 m_a.~A()
        // 释放 m_a/m_p 本身所占内存空间
    }
private:
    A m_a;
    int* m_p;
};
// 以上的代码模拟库
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    try {
        C c; // 定义c,利用c.C()
    } // 如果c是完整对象将利用c.~C()   但是如果c是残缺对象,将不会利用c.~C()
    catch( ... ) {
        // ...
    }
    return 0;
}



#endif
