//
//  05while.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0
#include <stdio.h>

int main(void){
    int i = 0;//叫做循环变量
    //i=0, i<5, -> printf(); i++;
    //i=1, i<5, -> printf(); i++;
    //i=2, i<5, -> printf(); i++;
    //i=3, i<5, -> printf(); i++;
    //i=4, i<5, -> printf(); i++;
    //i=5, i<5, 不成立-> 退出循环
    while(i < 5){
        printf("i = %d.\n", i);
        i++;
    }
    printf("-----------\n");
    i = 0;
    //i=0, i++;0<5; i=1; printf(1);
    //i=1, i++;1<5; i=2; printf(2);
    //i=2, i++;2<5; i=3; printf(3);
    //i=3, i++;3<5; i=4; printf(4);
    //i=4, i++;4<5; i=5; printf(5);
    //i=5, i++;5<5;不成立 - 结束
    while(i++ < 5)
        printf("i = %d.\n", i);//12345
    printf("-----------\n");
    i = 0;
    while(++i < 5)
        printf("i = %d.\n", i);//1234
    //实现0+1+...+100求和的结果
    int m = 0;//循环变量
    int sum  = 0;//将求和结果放到sum中
    while(m++ < 100)
        sum = sum + m;
    printf("sum = %d\n", sum);
    //m = 1 sum = 0 + 1
    //m = 2 sum = 0 + 1 + 2
    //m = 3 sum = 0 + 1 + 2 + 3
    //...
    //m = 100 sum = 0 + 1 + 2 + ... + 100

    //死循环, 条件表达式永远为真 - 永远执行
    //ctrl+c 强制退出
    while(1){
        printf("hello,world.\n");
    }
    return 0;
}
#endif







