//
//  04_overload3.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/17.
//
#if 0

//重载解析：安全匹配>常量转换>升级转换>标准转换>自定义转换>省略号匹配（优先级从高到低匹配）
//升级转换：绝对没有信息损失的转换，一般是小类型往大类型上转，例如char往short类型上转，不会有信息损失的转换。
//标准转换：可能有信息损失的转换，一般表现是大类型往小类型上转，例如int往short类型上转，short的范围是-32768~+32767

//函数指针方式调用重载关系的函数，根据 函数指针本身的类型 类确定到底调用哪个foo

//c++换名机制
//c++国际标准规定，所有c++函数都必须换名，全天下的c++编译器都必须遵守
//编译器是各个厂商自己提供的，例如linux的c++编译器是g++
//c++编译器，会更改我们所书写的函数名,命令：nm a.out查看

#include <iostream>
using namespace std;

void foo( char* c,short s){//完全匹配版本 // _Z3fooPcs，Z表示我们自己写的函数
    cout << "1.foo(char*,short)"<< endl;
}

void foo( const char* c,short s){//常量转换版本，char往const char转  //_Z3fooPKcs
    cout << "2.foo(const char*,short)"<< endl;
}

void foo(char* c,int s){//升级转换版本，short往int上转  //_Z3fooPci
    cout << "3.foo(char*,int)"<< endl;
}

void foo(char* c,char s){//标准转换版本，short往char上转,  //_Z3fooPcc
    cout << "4.foo(char*,char)"<< endl;
}

void foo(...){//省略号转换版本 //_Z3fooz
    cout << "5.foo(...)"<< endl;
}
//最好的编程习惯：工作中用完全匹配，笔试经常考这个。
int main(void){
    char* c; short s;
    foo(c,s);//_Z3fooPcs(c,s),普通方式调用重载关系的函数，根据 实参的类型 来确定到底调用哪个foo
    
    void (*pfunc)(const char*,short) = foo;//_Z3fooPKcs
    pfunc(c,s);//函数指针方式调用重载关系的函数，根据 函数指针本身的类型 类确定到底调用哪个foo
    //实参(c,s)是(char*,short)类型的，函数指针本身的类型是（const char*,short）
    return 0;
}
/*运行结果：
 1.foo(char*,short)
 2.foo(const char*,short)
 */
#endif

