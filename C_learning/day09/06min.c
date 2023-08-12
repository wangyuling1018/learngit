//
//  06min.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0
//获取最小数
#include <stdio.h>

int main(void){
    int a = 0, b = 0, c = 0;
    printf("请输入a b c的值:");
    scanf("%d%d%d", &a, &b, &c);
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    //判断那个值小, 输出到屏幕上
    if(a > b){
        //此时a不可能为最小值,min只能为b,或者为c
        if(b > c)
            printf("min = %d\n", c);
        else
            printf("min = %d\n", b);
    }else{
        //此时b不可能为最小值,min只能为a,或者为c
        if(a > c)
            printf("min = %d\n", c);
        else
            printf("min = %d\n", a);
    }
    return 0;
}

#endif

