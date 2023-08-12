//
//  sort_30.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/16.
//
#if 0
//sort.c:定义
#include "sort_30.h"

//冒泡排序
void bubble_sort(int data[], int size){
    int i, j;
    for(i = 0; i < (size-1); i++){//比较的趟次
        int ordered = 1;//记录数据是否发生了交换, 如果发生交换ordered=0, 否则ordered=1
        for(j = 0; j < (size-i-1); j++){//每一趟比较的次数
            if(data[j+1] < data[j]){
                int swap = data[j];
                data[j] = data[j+1];
                data[j+1] = swap;
                ordered = 0;//如果交换了位置, ordered设置为0
            }
        }
        //内侧循环结束 - 数据没有发生交换 - 已经有序
        if(ordered)
            break;//跳出循环 - 不再进行下一趟的比较
    }
}

//插入排序
void insert_sort(int data[], int size){
    int i;
    for(i = 1; i < size; i++){
        int inserted  = data[i];
        int j;//比较的次数
        //10 30
        //0  1  2
        //data[0]=10 data[1]=30
        //inserted=20; 此时i=2
        //j=2; j>0 && inserted < data[1];(20<30) -> data[2]=data[1];(data[2]=30)
        //j=1; j>0 && inserted < data[0];(20<10) -> 不成立 ->　结束循环
        for(j = i; j > 0 && inserted < data[j-1]; --j){
            data[j] = data[j-1];
        }
        //inserted = 40
        //10 20 30 40
        //0  1  2  3
        //i=3 j=3
        //j>0 && inserted < data[2](40<30) -> 不成立->结束循环
        //40 = inserted
        //j=1, i=2; data[1] = inserted;//20
        if(j != i)
            data[j] = inserted;//插入
    }
}


//选择排序
void select_sort(int data[], int size){
    int i;
    for(i = 0; i < (size-1); i++){
        int min = i;//假设下标为0的值为最小值, min记录最小值下标
        int j;
        for(j = i + 1; j < size; j++){//找最小数
            if(data[j] < data[min])
                min = j;//更新最小数的下标
        }
        if(min != i){//数据交换
            int swap = data[i];
            data[i] = data[min];
            data[min] = swap;
        }
    }
}



//快速排序
void quick_sort(int data[], int left, int right){
    int p = (left + right) / 2;//定义基准值下标, 随意
    int i = left;//left=0, 左边界
    int j = right;//right=size-1, 右边界
    
    int pivot = data[p];//将基准值存储起来
    while(i < j){
        //i变化
        //i不做自增运算的两种情况:ｉ对应的值大于基准值　ｉ和ｐ重合
        for(; !(i >= p || pivot < data[i]); i++);
        //i>=p, 不成立,则pivot < data[i]成立
        if(i < p){
            data[p] = data[i];//将ｉ对应的值挪到ｐ的位置上
            p = i;
        }
        //j变化
        for(; !(j <= p || data[j] < pivot); j--);
        if(j > p){
            data[p] = data[j];
            p = j;
        }
    }
    data[p] = pivot;//分组结束后将基准值放到p的位置上
    if(p - left > 1)
        quick_sort(data, left, p-1);//左边界还是0, 右边界为p-1
    if(right - p > 1)
        quick_sort(data, p+1, right);//右边界还是right, 左边界为p+1
}

#endif

