//
//  03var.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//
#if 0

//03var.c:定义变量,函数
#include <stdio.h>
int g_a = 520;//定义初始化全局变量

//定义初始化静态全局变量
//仅限于当前文件, 不可以跨文件访问
static int g_b = 521;

//静态全局函数,不可以跨文件访问
static void print1(void){
    printf("print1函数:g_a=%d\n", g_a);//ok
    printf("print1函数:g_b=%d\n", g_b);//ok
}
//定义一个函数- 全局函数
void print(void){
    printf("print函数:g_a=%d\n", g_a);
    printf("print函数:g_b=%d\n", g_b);
    print1();
}

#endif

