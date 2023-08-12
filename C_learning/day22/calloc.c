//
//  calloc.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/12.
//
#if 0
//动态内存分配 calloc.c
#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int* p = NULL;
    //调用calloc函数分配内存
    p = (int *)calloc(4, sizeof(int));//连续分配了4*4个字节, 返回首地址给p
    if(NULL == p){
        printf("calloc memory failed\n");
        return -1;
    }
    printf("calloc memory success\n");

    for(int i = 0; i < 4; i++)
        p[i] = i + 200;
    for(int i = 0; i < 4; i++)
        printf("%d ", p[i]);
    printf("\n");

    free(p);
    p = NULL;
    return 0;
}

#endif

