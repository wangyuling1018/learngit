//
//  06dynamic_arr.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//

#if 0
#include <stdio.h>

int main(void){
    int n;
    printf("请输入数组的长度(又称为元素个数):");
    scanf("%d", &n);

    int a[n];//定义动态数组

    ///初始化数组
    for(int i = 0; i < n; i++)
        a[i] = i + 10;
    //打印内存值
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
#endif

