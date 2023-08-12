//
//  07unl_pointer.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//
#if 0

#include <stdio.h>
//可以使用unsigned long变量存储地址 - 不建议使用
int main(void){
    int a = 520;
    unsigned long p = (unsigned long)&a;//p是普通变量，可以存储地址
    *(int *)p = 1000;//将指针p强转为int*,再解引用 //指针就是地址，地址就是指针
    printf("%d, %d\n", a, *(int *)p);
    return 0;
}
#endif

