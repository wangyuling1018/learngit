//
//  find.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/16.
//

//find.c:定义
#include "find.h"


int line_find(int data[], int size, int key){
    for(int i = 0; i < size; i++){
        if(data[i] == key)
            return i;//找到数据, 并且返回下标
    }
    return -1;
}

//定义递归二分查找函数
static int recu_find(int data[], int left, int right, int key){
    if(left <= right){
        int mid = (left + right) / 2;
        if(key < data[mid])
            return recu_find(data, left, mid-1, key);
        else if(key > data[mid])
            return recu_find(data, mid+1, right, key);
        else
            return mid;//返回目标下标
    }
    return -1;//没有找到
}

int half_find(int data[], int size, int key){
   //调用递归函数来实现
   return recu_find(data, 0, size-1, key);
}

