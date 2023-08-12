//
//  03define.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0

//gcc -E 03define.c -o 03define.i
#include <stdio.h>

#define SQUARE1(x) (x*x) //定义求平方宏函数
#define SQUARE2(x) ((x)*(x)) //定义求平方宏函数
#define SUB(x,y)    ((x) - (y))//定义求相减宏函数
#define MAX(x,y)    ((x)>(y)?(x):(y))   //求两个数最大数

int main(void){
    printf("%d\n", SQUARE1(10));//10*10=100
    printf("%d\n", SQUARE1(3+7));//3+7*3+7 = 31  //宏定义中的x最好加括号，否则不是想要的结果
    printf("%d\n", SQUARE2(10));//(10)*(10)=100
    printf("%d\n", SQUARE2(3+7));//(3+7)*(3+7) = 100

    int a = 10, b = 20;
    printf("%d\n", MAX(a,b));//替换结果:(a)>(b)?(a):(b)
    printf("%lg\n", MAX(4.5, 6.7));//(4.5)>(6.7)?(4.5):(6.7)

    printf("%d\n", SUB(200, 100));//(200)-(100)

#undef SUB //从该代码后, 不可以使用SUB这个宏了, 之前的代码不受影响
    printf("%d\n", SUB(200, 100));//(200)-(100)

    return 0;
}

#endif

