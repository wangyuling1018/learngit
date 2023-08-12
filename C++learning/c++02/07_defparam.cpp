//
//  07_defparam.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/18.
//

#if 0
//“缺省”的意思在C++中的含义很广。
//但是在 缺省（默认）参数 中，“缺省”的意思就是“默认”的意思
//函数的形参带有默认值，我们将其称之为 缺省参数


//函数的形参指定缺省（默认值），当调用该函数时若未指定实参，则使用形参的缺省（默认）值
#include <iostream>
using namespace std;
/*
//void foo(int a ,double b = 3.14,float c ,short d ,char e = 'A'){//error，有一个形参有默认值，那么后面的所有的形参都要加默认值，形参c、d、e都要有默认值
void foo(int a ,double b,float c ,short d ,char e = 'A'){//连声明带定义，声明和定义 写一起的
    cout << "e=" << e << endl;
}
*/
/*
void foo(int a ,double b=3.24,float c=3.2 ,short d=4 ,char e = 'A'){
    cout << "e=" << e << endl;
}

void foo(int a){//与22行的foo互为重载关系，会产生重载匹配歧义
    
}
 */

void foo(int a ,double b=3.24,float c=3.5 ,short d=2 ,char e = 'A');//纯声明
 //形参默认值只能写在声明中指定，不能在定义的地方指定，除非是 声明和定义 写一起的 可以指定。


int main(void){
    foo(3,3.14,2,3.1);
    foo(3,3.14,2,3.1,'V');
    //foo(10);//编译器不知到选22行的foo，还是选26行的foo，会产生重载匹配歧义
    return 0;
}

//void foo(int a ,double b=3.24,float c=3.5 ,short d=2 ,char e = 'A'){//error
void foo(int a ,double b,float c ,short d ,char e){//定义，定义的地方不能指定形参默认值，除非是 声明和定义 写一起的 可以指定。
    cout << "e=" << e << endl;
}

#endif

