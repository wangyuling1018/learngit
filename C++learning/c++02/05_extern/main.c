//
//  main.c
//  C++learning
//
//  Created by 王育玲 on 2023/2/17.
//

#if 0
//用C++制作一个库，用C语言调用C++库，
//C++制作库会换名，C语言调用不会换名，会不会无法调用？？ 答案：链接失败，无法调用。
//解决方案：函数名前加上extern “C”，要求C++编译器不换名，但是无法重载了，重载的本质就是换名
#include <stdio.h>
int main(void){
   // int c = sum(5,4); //无法链接成功
    //int d = sub(5,4);
    
    //int c = _Z3sumii(5,4);//替换换名后的函数名，可以链接成功
    //int d = _Z3subii(5,4);
    
    //要求C++编译器不换名，函数名前面加上“extern "C” "，按照C语言的方式编译
    //用extern “C”大括号，将所有的函数包含进去也可以，使用于很多函数的时候。
    //如果函数的声明和定义分开写，extern “C”写在函数声明那里。
    int c = sum(5,4);
    int d = sub(5,4);
    
    printf("c=%d,d=%d",c,d);
    return 0;
}

#endif 
