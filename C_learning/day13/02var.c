//
//  02var.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//

#if 0

//全局变量的作用域和生命周期
#include <stdio.h>

void A(void){
    static int a = 520;//定义初始化静态局部变量
                        //作用域:在函数的内部, 和局部变量是一致的
                        //生命周期:程序运行的时候(./02var)就已经分配好了内存,直到程序结束
    //printf("A函数:g_a = %d\n", g_a);//no
    printf("A函数:a = %d\n", a);
    a = 10;
}

static int g_b = 10000;

int g_a = 520;//定义初始化全局变量, g_ = global = 全局
              //作用域:从定义的位置开始, 依次向下所有的函数都可以访问
              //生命周期:程序运行的时候就分配好内存了, 直到程序结束
              //    程序结束:main函数结束

int main(void){
    //int g_a = 500;//局部变量和全局变量同名 - 局部变量
    A();
    A();
    printf("main函数:g_a = %d\n", g_a);
    return 0;
}

#endif

