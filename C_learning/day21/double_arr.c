//
//  double_arr.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/11.
//
#if 0
//数组指针演示
#include <stdio.h>

int main(void){
    //定义二维数组, 将其显示到屏幕上
    int a[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("------------\n");
    //利用数组指针来访问二维数组
    int (*p)[4] = a;//定义初始化数组指针保存二维数组的首地址a
    //假设p=0x1000 p + 1 = p + 4*sizeof(int) = p + 0x10 = 0x1000 + 0x10 = 0x1010
    //假设数组a的首地址是0x1000, 数组a一种有三个元素, 每个元素都是4个int类型的数组
    //a[0] - 下标为0的数组名 - 首地址
    //a[1] - 下表为1的数组名 - 首地址
    //a[2] - 下标为2的数组名 - 首地址
    //p + 1 == a[1]
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++)
            printf("%d ", p[i][j]);
        printf("\n");
    }
    
    return 0;
}

#endif

