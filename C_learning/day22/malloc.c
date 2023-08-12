//
//  malloc.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/12.
//
#if 0
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

    //调用free函数主动释放分配的内存
    free(p);//将分配的内存释放掉
    //free(p);//是否会报错呢?? - 会报错 - 警觉 - 运行报错
    //p的值是否变化, p是否为野指针
    //没有           是
    p = NULL;//将p设置为NULL, 避免野指针的出现

    return 0;
}

#endif

