//
//  main.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0
//main.c:负责调用
//编译:gcc main.c cal.c arr.c -o main
//./main

#include "arr.h"//数组操作
#include "cal.h"//算数运算

int main(void){
    printf("%d\n", add(100,20));
    printf("%d\n", sub(100,20));


    int arr[] = {1,2,3,4,5,6};
    print(arr, ASIZE(arr));

    return 0;
}

#endif

