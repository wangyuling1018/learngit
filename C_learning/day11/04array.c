//
//  04array.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0
#include <stdio.h>

int main(void){

    int a[5] = {1,2,3,4,5};//定义初始化数组

    for(int i = 0; i < 5; i++)
        printf("%d ", a[i]);//i:0 1 2 3 4 - 就是数组的下标 - 使用数组使用下标作为循环变量
    printf("\n");

    for(int i = 0; i < 5; i++)
        a[i] *= 10;//将数组中的所有的元素,放大10倍

    for(int i = 0; i < 5; i++)
        printf("%d ", a[i]);//i:0 1 2 3 4 - 就是数组的下标 - 使用数组使用下标作为循环变量
    printf("\n");

    for(int i = 0; i < 5; i++)
        printf("%p\n", &a[i]);
    printf("\n");

    for(int i = 0; i < 5; i++)
        *&a[i] *= 10;//将数组中的所有的元素,放大10倍

    for(int i = 0; i < 5; i++)
        printf("%d ", *&a[i]);//i:0 1 2 3 4 - 就是数组的下标 - 使用数组使用下标作为循环变量
    printf("\n");

    return 0;
}
#endif

