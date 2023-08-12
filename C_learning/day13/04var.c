//
//  04var.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//

#if 0

//04var.c:调用
#include <stdio.h>

//声明全局变量g_a
extern int g_a;  //extern 一会你调用的时候, 如果没有找到这个函数, 先别报错, 可能在后面, 或者在其他文件中
//声明全局函数
extern void print(void);
//extern void print1(void);
//extern int g_b;
int main(void){
    printf("main函数:g_a=%d\n", g_a);
    //printf("main函数:g_b=%d\n", g_b);
    print();
    //print1();

    return 0;
}

#endif

