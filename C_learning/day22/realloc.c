//
//  realloc.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/12.
//
#if 0
//realloc.c
//动态内存调整
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int* p = NULL;
    p = (int *)malloc(8);//连续分配8个字节, 想要存储int类型数据, 返回分配内存首地址
    if(NULL == p){
        printf("malloc memory fialed.\n");
        return -1;
    }
    printf("malloc memory success.\n");
    *(p+0) = 520;
    *(p+1) = 521;
    printf("%d, %d\n", p[0], p[1]);
    //调整realloc函数调整内存大小
    //xxxx xxxx yyyy yyyy
    p = realloc(p, 16);//在原先malloc分配的8字节基础上再分配8字节,构成16个字节
    for(int i = 0; i < 4; i++)
        p[i] = i + 100;
    for(int i = 0; i < 4; i++)
        printf("%d ", p[i]);
    printf("\n");

    //调用free函数主动释放分配的内存
    free(p);//将分配的内存释放掉
    p = NULL;//将p设置为NULL, 避免野指针的出现

    return 0;
}
#endif

