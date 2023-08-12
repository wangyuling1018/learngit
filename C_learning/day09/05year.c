//
//  05year.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0

//判断闰年
#include <stdio.h>

int main(void){
    int year;
    printf("请输入年份:");
    scanf("%d", &year);

    if((year%4 == 0 && year%100 != 0) || (year%400 == 0))
        printf("闰年.\n");
    else
        printf("平年.\n");
    return 0;
}

#endif

