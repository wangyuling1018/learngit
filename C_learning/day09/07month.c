//
//  07month.c
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
    return 0;
}

#endif

