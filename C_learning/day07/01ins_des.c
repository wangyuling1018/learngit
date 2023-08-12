//
//  01ins_des.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0

#include <stdio.h>

int main(void){
    int a = 10;
    printf("%d\n", ++a);//先加在用
    printf("%d\n", a);//

    a = 10;
    printf("%d\n", a++);//先计算a++的结果10, 然后对a加1, 11, 先用再加
    printf("%d\n", a);//

    a = 10;
    printf("%d\n", --a);//先减再用
    printf("%d\n", a);//

    a = 10;
    printf("%d\n", a--);//先用再减
    printf("%d\n", a);//

    a = 10;
    printf("%d\n", a++ + ++a);//11 + 11
    printf("%d\n", a);//

    a = 10;
    printf("%d\n", ++a + a++);
    printf("%d\n", a);



    return 0;
}
#endif

