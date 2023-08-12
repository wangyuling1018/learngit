//
//  01month.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0
#include <stdio.h>

int main(void){
    int year, month;
    printf("请输入年份和月份:");
    scanf("%d%d", &year, &month);
    if(month<1 || month>12){
        printf("无效月份\n");
        return -1;
    }

    int day = 31;
    if(month==4 || month==6 || month==9 || month==11)
        day = 30;
    else if(month == 2)
        //闰年:28+1;平年:28+0;
        day = 28 + ((year%4==0 && year%100 !=0) || (year%400==0));
        
    printf("%d年%d月有%d天\n", year, month, day);
    return 0;
}

#endif

