//
//  02switch.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0
#include <stdio.h>

int main(void){
    printf("请输入季节的编号:");
    int season;
    scanf("%d", &season);

    switch(season){
        case 1:
            printf("春天.\n");
            break;
        case 2:
            printf("夏天.\n");
            break;
        case 3:
            printf("秋天.\n");
            break;
        case 4:
            printf("冬天.\n");
            break;
        default:
            printf("季节编号不对.\n");
            break;
    }

    return 0;
}
#endif

