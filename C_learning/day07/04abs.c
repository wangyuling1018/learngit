//
//  04abs.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0

#include <stdio.h>

int main(void){
    /*
    int a = -100;

    int b = 0;
    b = (a > 0) ? a : (0-a);
    printf("|a|=%d\n", b);
*/
    int a = 2, b = 4, c = 6, x, y;
    //此时圆括号里面, 逗号表达式
    //x = a + b = 6, 表达式1
    //b + c = 10, 表达式2
    //表达式1, 表达式2 -> 使用表达式2作为运算结果
    //y = (b + c) = 10;
    y = (x = a + b, b + c);
    printf("%d, %d\n", x, y);//6 10

    a = 520;
    printf("%p\n", &a);//打印a的地址
    printf("%d\n", *&a);//通过a的地址, 获取变量a的内容
    *&a = 521;//根据变量a的地址, 修改a的值
    printf("%d\n", *&a);//通过a的地址, 获取变量a的内容

    return 0;
}
#endif

