//
//  main.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/16.
//
#if 0
//main.c:测试
#include "sort.h"

int main(void){
    int data[] = {9, 0, 7, 2, 5, 3, 4, 1, 8, 6};
    int size = sizeof(data) / sizeof(data[0]);

    //select_sort(data, size);//选择排序
    //insert_sort(data, size);//插入排序
    bubble_sort(data, size);//冒泡排序

    for(int i = 0; i < size; i++)
        printf("%d ", data[i]);
    printf("\n");

    return 0;
}
#endif

