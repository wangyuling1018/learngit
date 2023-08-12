//
//  02_throw.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//

/*
 抛出异常：
 1.throw 异常对象；
 2.可以抛出基本类型的对象，如：throw -1; thow "内存分配失败！“；
 3.也可以抛出类类型的对象，如：A a; throw a; throw A();
 4.但不要抛出局部对象的指针，如：A a; throw &a; ----因为局部对象指针的生命期短，抛出不能使用的地址？？
 */

/*
 关于异常处理机制：
    如果程序中 没有捕获异常的代码，一旦异常被抛出，最终将被操作系统捕获，操作系统将我们的程序杀死
    如果程序中 有捕获异常的代码，一旦异常被抛出，层层退出右花括号，直到异常被捕获为止，程序回归正常流程
 */

//抛出的异常，可以解决就近点捕获，无法解决就远点捕获

//抛出的异常，是抛出给标准库
#if 0

#include <iostream>
using namespace std;
class A{
public:
    A(){
        cout << "A() is invoked" << endl;
    }
    ~A(){
        cout << "~A() is invoked" << endl;
    }
    
};

void foo(){
    cout << "foo出错前的几百行代码" << endl;
    A a;
    FILE* pfile = fopen("./cfg","r");
    if(!pfile)
        throw -1;
    cout << "foo出错后的几百行代码" << endl;
}//a.~A() 释放a本身所占内存空间

void  bar(){
    cout << "bar出错前的几百行代码" << endl;
    A b;
//    try{
        foo();
//    }
//    catch(int e){
//        cout << "bar中捕获异常信息：" << e << endl;
//    }
    
    cout << "bar出错后的几百行代码" << endl;
}//b.~A() 释放b本身所占内存空间

void hum(){
    cout << "hum出错前的几百行代码" << endl;
    A c;
//    try{
        bar();
//    }
//    catch(int e){
//        cout << "hum中捕获异常信息：" << e << endl;
//    }
    cout << "hum出错后的几百行代码" << endl;
}//c.~A() 释放c本身所占内存空间

// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    cout << "main出错前的几百行代码" << endl;
    A d;
    try{
        hum();
    }
    catch(int e){
        cout << "main中捕获异常信息：" << e << endl;
    }
    cout << "main出错后的几百行代码" << endl;
    return 0;
}//d.~A() 释放d本身所占内存空间
#endif

/*在bar函数中捕获异常try...catch
 main出错前的几百行代码
 A() is invoked         d
 hum出错前的几百行代码
 A() is invoked         c
 bar出错前的几百行代码
 A() is invoked         b
 foo出错前的几百行代码
 A() is invoked         a
 ~A() is invoked        ~a  //foo抛出异常了，找foo函数的右花括号，调用a.~A()
 bar中捕获异常信息：-1    //退出到bar中try的右花括号，直到异常被捕获为止，程序回归正常流
 bar出错后的几百行代码    //程序回归正常流
 ~A() is invoked       ~b  //自然流转到bar函数的右花括号
 hum出错后的几百行代码
 ~A() is invoked       ~c //自然流转到hum函数的右花括号
 main出错后的几百行代码
 ~A() is invoked       ~d //自然流转到main函数的右花括号
 
 */

/*在hum函数中捕获异常try...catch
 main出错前的几百行代码
 A() is invoked          d
 hum出错前的几百行代码
 A() is invoked          c
 bar出错前的几百行代码
 A() is invoked          b
 foo出错前的几百行代码
 A() is invoked          a
 ~A() is invoked         ~a //foo抛出异常了，找foo函数的右花括 号，调用a.~A()
 ~A() is invoked         ~b //foo执行完后，接着退出bar函数的右花括号，调用b.~A()
 hum中捕获异常信息：-1         //bar函数执行完后，退出到hum中的try的右花括号，然后异常信息被捕获
 hum出错后的几百行代码         //异常一旦被捕获，程序回归到正常流程
 ~A() is invoked         ~c  //自然流转到hum的右花括号
 main出错后的几百行代码
 ~A() is invoked         ~d   //自然流转到main的右花括号
 */

/*在main函数中捕获异常try...catch
 main出错前的几百行代码
 A() is invoked            d
 hum出错前的几百行代码
 A() is invoked            c
 bar出错前的几百行代码
 A() is invoked            b
 foo出错前的几百行代码
 A() is invoked            a
 ~A() is invoked           ~a //foo抛出异常了，找foo函数的右花括 号，调用a.~A()
 ~A() is invoked           ~b //foo执行完后，接着退出bar函数的右花括号，调用b.~A()
 ~A() is invoked           ~c //bar执行完后，接着退出hum函数的右花括号，调用c.~A()
 main中捕获异常信息：-1           //hum函数执行完后，退出到main中try的右花括号，然后异常信息被捕获
 main出错后的几百行代码           //异常一旦被捕获，程序回归到正常流程
 ~A() is invoked           ~d  //自然流转到main的右花括号，调用d.~A()
 */


