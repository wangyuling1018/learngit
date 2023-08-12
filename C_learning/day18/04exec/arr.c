//
//  arr.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//

//arr.c:数组操作定义
#include "arr.h"//包含自己对应的头文件
//定义操作函数
void print(int* parr, int size){
    for(int i = 0; i < size; i++)
        printf("%d ", parr[i]);
    printf("\n");
}
