//
//  01arrary.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//
#if 0
#include <stdio.h>

int main(void){
    int a[10] = {0};
    int size = sizeof(a)/sizeof(a[0]);
    printf("请输入10个整数:");
    int i;
    for(i = 0; i < size; i++)
        scanf("%d", &a[i]);//0 1 2 3 4 .... 9
    //循环的将数据依次放入到
    //a[0]=100 a[1]=101 a[2]=102 a[3]=103 ... a[9]=109
    //第一个for循环结束后, i的值变为了10

    //i=10
    //逆序输出:就是将数组中的数据,a[9] a[8] a[7] a[6] ... a[0]
    printf("逆序:");
    
    //逆序输出:下标从9变化为0,i=10,i-- -> i=9
    //for(i--; i >= 0; i--)
    for(i = 9; i >= 0; i--)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
#endif

