//
//  ppointer.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/11.
//
#if 0
//二级指针演示
#include <stdio.h>

int main(void){
    int n = 10;
    int* p = &n;//一级指针变量p, 保存变量n的地址
    int** pp = &p;//二级指针变量pp 保存一级指针p的地址

    printf("n = %d, &n = %p\n", n, &n);
    printf("p = %p, &p = %p, *p = %d\n", p, &p, *p);
    printf("pp = %p, *pp = %p, **pp = %d\n", pp, *pp, **pp);

    //通过一级指针修改
    *p = 11;
    printf("%d, %d\n", *p, n);
    //通过二级指针修改
    **pp = 12;
    printf("%d, %d\n", **pp, n);
    return 0;
}
#endif

