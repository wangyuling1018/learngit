//
//  02empty.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0
#include <stdio.h>

int main(void){
    ;//空语句
    //应用场景1:空死循环
    //想要让程序停在这里什么也不做, 但是不知道要怎么做
    /*
    printf("1.\n");
    for(;;);//程序就什么也不做, 永远的循环下去
    printf("2.\n");
    */

    //应用场景2:空循环, 起到延时等待的作用
    //想要让3出现后, 稍等一会在出现4
    //缺点:延时时间不确定 - 第二阶段
    printf("3.\n");
    long i = 900000000;
    for(; i >= 0; i--);//让程序在这里无聊的运行i--,消耗点时间,让程序在这里等待
    printf("4.\n");

    //应用场景3:简化代码,不需要循环体语句
    //求n的阶乘: n! = n * (n-1) * (n-2)... * 1
    //5! = 5 * 4 * 3 * 2 * 1 = 120
    int n = 5;
    int fact = 0;//存储得到的阶乘
    //fact = 1
    //  [2]       [4]      [3]
    //n!=0 true -> ; -> fact = 1 * 5 = 5 n=4
    //n!=0 true -> ; -> fact = 5 * 4 = 20 n=3
    //n!=0 true -> ; -> fact = 20 * 3 = 60 n=2
    //n!=0 true -> ; -> fact = 60 * 2 = 120 n=1
    //n!=0 true -> ; -> fact = 120* 1 = 120 n=0
    //n == 0 false->结束循环
    for(fact = 1; n; fact = fact * n--);
    printf("fact = %d\n", fact);

    //不要任意的添加 空语句 - 无意
    //打印输出的j的值为多少? -
    int j = 0;
    for(j = 0; j < 5; j++);//不小心在后面加了一个分号,结果是5次循环变为了5次空循环
        printf("j = %d\n", j);//该语句不在隶属于for循环, 独立的
    return 0;
}
#endif

