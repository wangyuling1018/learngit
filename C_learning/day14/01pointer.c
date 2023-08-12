//
//  01pointer.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//
#if 0
#include <stdio.h>

int main(void){
    int a = 520;
    int *pa = &a;//定义初始化指针变量pa保存变量a的首地址, 简称pa指向a
    //打印a的地址, 打印pa, 打印&pa
    printf("&a = %p, pa = %p, &pa = %p\n", &a, pa, &pa);
    //打印a的值, pa指向的内存值
    printf("a = %d, *pa = %d\n", a, *pa);
    //修改pa指向的a的值
    *pa = 521;
    //打印a的值, pa指向的内存值
    printf("a = %d, *pa = %d\n", a, *pa);

    int b;
    pa = &b;//pa指针保存b变量的内存地址, 简称pa指向b
    //打印b的地址, 打印pa, 打印&pa
    printf("&b = %p, pa = %p, &pa = %p\n", &b, pa, &pa);
    //打印b的值, pa指向的内存值
    printf("b = %d, *pa = %d\n", b, *pa);
    //修改pa指向的b的值
    *pa = 522;
    //打印b的值, pa指向的内存值
    printf("b = %d, *pa = %d\n", b, *pa);
    return 0;
}
#endif

