//
//  03goto.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0
#include <stdio.h>

int main(void){
    int a = 1;
//标签 - 符合标识符标准 - 变量的标准
label:
    printf("1.\n");
    //如过a==1, 0赋值给a, goto label
    if(a == 1){
        a = 0;
        goto label;//让程序此时从label标签位置开始从上而下执行 -> 跳转到第6行
    }
    printf("2.\n");
    
    goto label2;//label2在goto的下面
    //该语句开始到label2,下面的语句都不执行 - 将其删除掉
    //取决于编译器
    //有的编译器 - 优化 - 删除
    //有的编译器 - 不优化 - 不删
    printf("3.\n");
    printf("3.\n");
    printf("3.\n");
    printf("3.\n");
    printf("3.\n");

label2:
    printf("4.\n");

    //求0+1+...+100求和结果
    int m = 0;
    int sum = 0;
next:
    if(m <= 100){
        sum += m;
        m++;
        goto next;
    }
    printf("sum = %d\n", sum);
    return 0;
}

#endif

