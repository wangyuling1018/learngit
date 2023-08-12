//
//  05pointer.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//
#if 0

#include <stdio.h>

int main(void){
    int a[] = {1,2,3,4};
    //a++;//error
    int* pa = a;//pa保存a的首地址, pa指向a
    //a==pa
    printf("%d, %d, %d, %d\n", a[0], a[1], a[2], a[3]);
    printf("%d, %d, %d, %d\n", *(a+0), *(a+1), *(a+2), *(a+3));
    printf("%d, %d, %d, %d\n", pa[0], pa[1], pa[2], pa[3]);
    printf("%d, %d, %d, %d\n", *(pa+0), *(pa+1), *(pa+2), *(pa+3));
    //修改数组中的值
    a[1] *= 10;
    *(a+1) *= 10;
    pa[1] *= 10;
    *(pa+1) *= 10;
    printf("%d, %d, %d, %d\n", *(pa+0), *(pa+1), *(pa+2), *(pa+3));
    
    //计算数组中的元素个数
    printf("sizeof(a)/sizeof(a[0]) = %d\n", sizeof(a)/sizeof(a[0]));
    printf("sizeof(pa)/sizeof(pa[0]) = %d\n", sizeof(pa)/sizeof(pa[0]));//error
    return 0;
}
#endif

