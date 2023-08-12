//
//  02arrary.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//
#if 0
#include <stdio.h>

int main(void){
    int a[2][3] = {{1,2,3},{4,5,6}};
    //打印二维数组中的每个元素
    //i=0
    //i<2 -> 循环体 -> for(j=0; j) -> i++
    for(int i = 0; i < 2; i++){//打印2组
        for(int j = 0; j < 3; j++)//打印每一组3个元素
            printf("%d ", a[i][j]);
        printf("\n");
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++)
            a[i][j] += 100;
    }
    //打印二维数组中的每个元素
    for(int i = 0; i < 2; i++){//打印2组
        for(int j = 0; j < 3; j++)//打印每一组3个元素
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
#endif

