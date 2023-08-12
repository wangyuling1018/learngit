//
//  05sizeof.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0
#include <stdio.h>
#include <string.h>

int main(void){

    int a[10] ={1,2,3,4,5,6,7,8,9,10};//定义初始化数组

    printf("sizeof(a)=%lu\n", sizeof(a)); //40
    printf("sizeof(a[0])=%lu\n", sizeof(a[0])); //4
    printf("sizeof(a)/sizeof(a[0])=%lu\n", sizeof(a)/sizeof(a[0])); //10

    //垃圾代码
    for(int i = 0; i < 7; i++)
        printf("%d ", a[i]);//i:0 1 2 3 4 - 就是数组的下标 - 使用数组使用下标作为循环变量
    printf("\n");

    //beutiful代码
    int size = sizeof(a) / sizeof(a[0]); //动态转换数组元素个数
    for(int i = 0; i < size; i++)
        printf("%d ", a[i]);//i:0 1 2 3 4 - 就是数组的下标 - 使用数组使用下标作为循环变量
    printf("\n");
    
    int aa[10];
    printf("strlen(aa):%lu, sizeof(aa)=%lu\n",strlen(aa),sizeof(aa));
    //sizeof()和初不初始化，没有关系，
    //strlen()和初始化有关，打印结果值未知。

    return 0;
}
#endif

/*
 sizeof(a)=40
 sizeof(a[0])=4
 sizeof(a)/sizeof(a[0])=10
 1 2 3 4 5 6 7
 1 2 3 4 5 6 7 8 9 10
 strlen(aa):0, sizeof(aa)=40
 Program ended with exit code: 0
 */
