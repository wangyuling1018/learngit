//
//  06dowhile.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0
#include <stdio.h>

int main(void){
    do{
        printf("hello,world\n");
    }while(0);

    int i = 0;
    //i=0,
    //printf(0), i++, i=1, i<5;
    //printf(1), i++, i=2, i<5;
    //printf(2), i++, i=3, i<5;
    //printf(3), i++, i=4, i<5;
    //printf(4), i++, i=5, i<5->结束循环
    do{
        printf("i = %d.\n", i);
        i++;
    }while(i<5);

    //实现0+1+2+...+100求和结果
    int m = 0;
    int sum = 0;
    do{
        sum += m;
    }while(m++<100);
    printf("sum = %d\n", sum);
    return 0;
}
#endif

