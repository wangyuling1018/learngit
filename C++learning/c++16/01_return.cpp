//
//  01_return.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//

#if 0
//利用return报告错误信息（体会优点以及缺点）

#include <iostream>
#include <fcntl.h>
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

int foo(){
    cout << "foo出错前的几百行代码" << endl;
    A a;
    FILE* pfile = fopen("./cfg","r");
    if(!pfile)
        return -1;//（1）将数据返回给调用者 （2）跳转至右花括号
    cout << "foo出错后的几百行代码" << endl;
    return 0;
}//a.~A() 释放a本身所占内存空间

int bar(){
    cout << "bar出错前的几百行代码" << endl;
    A b;
    if(foo() == -1)
        return -1;
    cout << "bar出错后的几百行代码" << endl;
    return 0;
}//b.~A() 释放b本身所占内存空间

int hum(){
    cout << "hum出错前的几百行代码" << endl;
    A c;
    if(bar() == -1)
        return -1;
    cout << "hum出错后的几百行代码" << endl;
    return 0;
}//c.~A() 释放c本身所占内存空间

// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    cout << "main出错前的几百行代码" << endl;
    A d;
    if(hum() == -1)
        return -1;
    cout << "main出错后的几百行代码" << endl;
    return 0;
}//d.~A() 释放d本身所占内存空间

#endif


