//
//  cal.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/17.
//

//用C++制作一个库，用C语言调用C++库，
//C++制作库会换名，C语言调用不会换名，会不会无法调用？？ 答案：链接失败，无法调用。
//要求C++编译器不换名，函数名前面加上“extern "C” "，按照C语言的方式编译
//用extern “C”大括号，将所有的函数包含进去也可以，使用于很多函数的时候。
//如果函数的声明和定义分开写，extern “C”写在函数声明那里。
extern "C"{
    int sum(int a, int b){
        return a+b;
    }

    int sub(int a, int b){
        return a-b;
    }
}
//生成库命令：g++ -c cal.cpp
//生成cal.o形式的库文件即可
//编译main.c：gcc -c main.c
//生成main.o文件
//链接：gcc mian.o cal.o
