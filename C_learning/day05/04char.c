//
//  04char.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/6.
//
#if 0
#include <stdio.h>

int main(void){
    //字符数字转换为数字:'5' - 5
    char c = '5';
    int i = c - '0';
    printf("%d\n", i);

    //小写字母转换为大写字母: a - A
    char c1;
    printf("请用户输入一个小写字母:");
    scanf("%c", &c1);
    printf("转换之后的大写字母是%c\n", c1 - 32);

    return 0;
}
#endif

