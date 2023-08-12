//
//  02string.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0
#include <stdio.h>
#include <string.h>

int main(void){
    char str[3][20] = {"beijing", "tianjin", "shanghai"};
    for(int i = 0; i < 3; i++)
        printf("%s ", str[i]);
    printf("\n");
    //str[0] = "hello";//将字符串hello的首地址给str[0], 不可以, 无法修改
    strcpy(str[0], "guangzhou");
    str[1][0] = 'T';

    for(int i = 0; i < 3; i++)
        printf("%s ", str[i]);
    printf("\n");
    return 0;
}

#endif

