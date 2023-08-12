//
//  04_autoptr.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//
#if 0

//解引用操作符（平常也叫：星号操作符）
//间接成员访问操作符（平常也叫：箭头操作符）

/*解引用和间接成员访问操作符
 1.如果一个类重载了 “解引用操作符” 和 “间接持有访问操作符” ，那么该类的 对象 就可以被当作 指针 来使用
 2.应用的体现（智能指针）：
   智能指针的本质就是一个类对象，并且维护一个指针型成员变量
 */

/*常规指针的缺点：
 1.当一个常规指针离开它的作用域时，只有该指针变量本身所占据的内存空间（通常是4个字节）会被释放，而它所指向的动态内存并未得到释放
 2.必须自己手动释放
 */

/*智能指针的优点：
 智能指针是一个类对象（封装了常规指针），当它离开作用域时，其析构函数负责释放该常规指针所指向的动态内存
 */

/*常规指针缺点演示代码：
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
using namespace std;
class A{
public:
    A() : m_f(open("./file",O_CREAT | O_RDWR,0664)){
        //【int m_f=open(...);】定义m_f,初值为文件描述符-->文件表等内核结构(动态资源)
        cout << "A() is invoked...打开了file文件" << endl;
    }
    ~A(){
        close(m_f);
        cout << "~A() is invoked...关闭了file文件" << endl;
        // 释放m_f本身所占内存空间
    }
    void foo(){
        write(m_f,"hello file" ,10);
        cout << "foo() is invoked...写入file文件" << endl;
    }
private:
    int m_f;
};



//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    //常规指针
    A* pa = new  A;
    pa->foo();
    (*pa).foo();
    delete pa; //pa --->~A(),pa调用～A() 释放A类堆对象所占内存空间  //必须自己手动释放
        
    return 0;
}//常规指针离开作用域后，只释放 pa 本身所占内存空间

*/

//智能指针标准库已经设计好了
//智能指针优点演示代码
//模仿C++的智能指针类，设计一个智能智能类
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <memory>
using namespace std;
class A{
public:
    A() : m_f(open("./file",O_CREAT | O_RDWR,0664)){
        //【int m_f=open(...);】定义m_f,初值为文件描述符-->文件表等内核结构(动态资源)
        cout << "A() is invoked...打开了file文件" << endl;
    }
    ~A(){
        close(m_f);
        cout << "~A() is invoked...关闭了file文件" << endl;
        // 释放m_f本身所占内存空间
    }
    void foo(){
        write(m_f,"hello file" ,10);
        cout << "foo() is invoked...写入file文件" << endl;
    }
private:
    int m_f;
};

class Auto_ptr{//智能指针类
public:
    Auto_ptr(A* a) : m_a(a){
        
    }
    ~Auto_ptr(){
        delete m_a;//释放 用户申请的堆内存
    }
    A& operator*(){
        return *m_a; //返回的是对象，*是解引用
    }
    
    A* operator->(){
        return m_a; //返回的是指针
    }
    Auto_ptr(Auto_ptr& that) : m_a(that.m_a){
        //【A* m_a = that.m_a】
        that.m_a = NULL;
    }
private:
    A* m_a;//常规指针（保存的是用户申请的堆内存地址）
};


//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    auto_ptr<A> pau(new A);
    (*pau).foo( );
    pau->foo( );

    auto_ptr<A> pbu = pau;
    (*pbu).foo();
    pbu->foo();
    
    //(*pau).foo( ); -- pau已经失效
    
    //自己设计的智能指针----维护一块堆内存
    //Auto_ptr pau = new A;//定义 匿名Auto_ptr类对象，匿名Auto_ptr类对象.Auto_ptr(new A),然后Auto_ptr pau = 匿名Auto_ptr类对象
    //Auto_ptr pau(new A);//定义pau，利用pau.Auto_ptr(new A) //比110行代码效率高
    
    //让pau这个智能指针 像 常规指针 一样使用，必须定义星号操作符函数和箭头操作符函数
    //(*pau).foo();//pau.operator*().foo()
    //pau->foo();//pau.operator->().foo()
    
    //Auto_ptr pbu = pba;//error,涉及浅拷贝问题，
    
    //不用 用户自己调用析构函数释放堆内存了

    return 0;
}//（1）pau.~Auto_ptr() 当pau离开作用域时，其析构函数自动调用了 (2)释放pau本身所占内存空间
#endif

