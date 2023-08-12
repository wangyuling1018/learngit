//
//  main.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/16.
//
#if 0

//main.c:测试
#include "sort_30.h"
#include "find.h"

int main(void){
    int data[] = {9, 0, 7, 2, 5, 3, 4, 1, 8, 6};
    int size = sizeof(data) / sizeof(data[0]);

    int key = 1;
    int index = -1;//没有选择
    //线性查找
    index = line_find(data, size, key);
    if(index == -1){
        printf("sorry that wo do not find the key.\n");
        return -1;
    }
    printf("找到:data[%d]=%d\n", index, data[index]);

    //先排序
    quick_sort(data, 0, size-1);
    index = half_find(data, size, key);
    if(index == -1){
        printf("sorry that wo do not find the key.\n");
        return -1;
    }
    printf("找到:data[%d]=%d\n", index, data[index]);


    return 0;
}

#endif

