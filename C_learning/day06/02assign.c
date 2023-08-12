//
//  02assign.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0
//赋值运算符
#include <stdio.h>

int main(void){
    int a, b, c;
    a = 100;
    printf("a = %d.\n", a);

    a = b = c = 1000;//c = 1000, b = c, a = b;
    printf("a = %d, b = %d, c = %d.\n", a,b,c);

    /*
    100 = a;
    a + b = c;
    */

    a += b; // a = a + b;
    printf("a = %d, b = %d.\n", a, b);
    return 0;
}

#endif

