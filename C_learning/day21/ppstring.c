//
//  ppstring.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/11.
//
#if 0
#include <stdio.h>

int main(void){
    char* arr[] = {"hello", "world"};

    char** parr = arr;//二级指针变量p 指向字符指针数组

    printf("%s, %s\n", arr[0], arr[1] );
    printf("%s, %s\n", *(arr+0), *(arr+1) );
    printf("-----------------------------\n");

    printf("%s, %s\n", parr[0], parr[1] );
    printf("%s, %s\n", *(parr+0), *(parr+1) );

    
    return 0;
}
#endif

