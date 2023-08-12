//
//  02char.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/6.
//
#if 0
//char演示
#include <stdio.h>

int main(void){
    char c = 'A';//分配1字节内存存储字符A的ascii值65
    printf("c = %c\n", c);//按照字符常量的方式输出
    printf("c = %hhd\n", c);//按照数字的方式输出
    c = c + 1;//实际运算 c = 65 + 1 = 66 = 'B'
    printf("c = %c\n", c);//按照字符常量的方式输出
    printf("c = %hhd\n", c);//按照数字的方式输出

    char d = 69;
    printf("d = %c\n", d);//按照字符常量的方式输出
    printf("d = %hhd\n", d);//按照数字的方式输出

    return 0;
}

#endif

