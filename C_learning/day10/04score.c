//
//  04score.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0
#include <stdio.h>

int main(void){
    printf("请输入一个分数:");
    int score = 0;
    scanf("%d", &score);
    if(score < 0 || score > 100){
        printf("无效分数.\n");
        return -1;
    }

    switch(score/10){
        case 10:
        case 9:
            printf("优.\n");
            break;
        case 8:
            printf("良.\n");
            break;
        case 7:
            printf("中.\n");
            break;
        case 6:
            printf("差.\n");
            break;
        default:
            printf("差不多.\n");
            break;
    }
    return 0;
}
#endif

