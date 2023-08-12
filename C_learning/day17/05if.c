//
//  05if.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0

#include <stdio.h>

//#define A (1)//定义了宏A, 并且给的值为1

int main(void){

/*
 * gcc -E if.c -o if.i -> vim if.i -> gcc if.i -o if
 * 第一种编译的方式, 没有定义宏A, 宏A等于1, 条件不成立, 不会编译#endif之前代码
 * gcc -E -DA=1 if.c -o if.i -> vim if.i -> gcc if.i -o if
 * 第二种编译的方式, 定义了宏A, 而且宏A等于1, 条件成立, 会编译#endif之前代码
 * */
#if A==1    //如果宏A等于1, 条件成立, #endif之前的代码被编译到可执行程序
            //如果宏A不等于1, 那么不会编译#endif之前的代码
    printf("1.\n");
#endif

/*
 * gcc -E if.c -o if.i -> vim if.i -> gcc if.i -o if
 * gcc -E -DB=1 if.c -o if.i -> vim if.i -> gcc if.i -o if
 * */
#if B==1//如果宏B存在, 而且宏B==1, 条件成立, #else之前的代码会被编译进去;
        //如果宏B==1, 这个条件不成立, 否则#else和#endif之前的代码会被编译进去
    printf("2.\n");
#else
    printf("3.\n");
#endif

//gcc if.c -> 没有定义宏C
//gcc if.c -DC -> 定义了宏C
#ifndef C   //如果没有定义宏C, 条件成立, printf4会被编译进来;否则printf5会被编译进来
    printf("4.\n");
#else
    printf("5.\n");
#endif

    return 0;
}
#endif

