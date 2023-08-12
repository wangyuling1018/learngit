//
//  06_hastodes.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//
#if 0

//若对象在其生命周期的最终时刻，持有动态资源则必须自己定义析构函数，释放对象所持有的动态资源

#include <iostream>
#include <fcntl.h>
#include <unistd.h>

using namespace std;
// 必须自己定义析构函数的情况:对象临死时，持有动态资源
class A {
public:
    A( int i=0 ) : m_i(i),m_p(new int),m_f(open("./file",O_CREAT|O_RDWR,0644)) {
        //【int m_i=i;】定义m_i(给m_i分配内存空间),初值为i
        //【int* m_p=new int;】定义m_p,初值为指向一块堆内存(动态资源) //堆内存是在运行过程中申请的资源
        //【int m_f=open(...);】定义m_f,初值为文件描述符-->文件表等内核结构(动态资源)
    }
    ~A( ) {
        // 可以书写对象临死之前，想做的任何事情
        delete m_p;
        close( m_f );
        // 释放 m_i/m_p/m_f 本身所占内存空间
    }
    /* 默认析构
    ~A( ) {
        释放 m_i/m_p/m_f 本身所占内存空间 //只能释放m_p指针本身占用的内存，m_f本身的int内存。
    }
    */
private:
    int m_i;
    int* m_p;
    int m_f;
};
// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    A a; // 定义a(给a分配内存空间),利用a.A()
    return 0;
} // a.~A()   释放a本身所占内存空间

#endif

