//
//  03logic.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0

#include <stdio.h>

int main(void){
    //逻辑与
    printf("%d\n", 5>3 && 5<8);//1
    printf("%d\n", 5>3 && 5>8);//0
    printf("%d\n", 5<3 && 5<8);//0
    printf("%d\n", 5<3 && 5>8);//0
    printf("%d\n", 520 && 250);//1
    printf("%d\n", 520 && 0);//0
    printf("5<4<3的结果为:%d\n", 5 < 4 && 4 < 3);//0

    //逻辑或
    printf("%d\n", 5>3 || 5<8);//1
    printf("%d\n", 5>3 || 5>8);//1
    printf("%d\n", 5<3 || 5<8);//1
    printf("%d\n", 5<3 || 5>8);//0
    printf("%d\n", 520 || 250);//1
    printf("%d\n", 520 || 0);//1

    //逻辑非
    printf("%d\n", !(5>3 && 5<8));//0
    printf("%d\n", !(10>100));//1
    printf("%d\n", !10>100);//!10 > 100 ; !10 == 0; 0 > 100 -> 不成立 -> 0

    //短路运算
    int a = 1;
    int b = 1, res = 0;
    res = (a>b) && ++a;//将++a忽略掉, 不在执行++a操作
    printf("a = %d, b = %d\n", a, b);

    a = 2;
    b = 1;
    res = (a>b) || ++a;//a>b条件成立, ||为真, 忽略++a,
    printf("a = %d, b = %d\n", a, b);
    

    return 0;
}

#endif



