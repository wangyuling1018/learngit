//
//  01odd.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//

/*
 1.求1-100之间的所有奇数
 */
#if 0
#include <stdio.h>

int main(void){
    for(int i = 1; i <= 100; i++){
        if(i%2)//不是0就是1
            printf("%d ", i);
    }
    printf("\n");

    for(int i = 1; i <= 100; i += 2)
        printf("%d ", i);//等差数列
    printf("\n");

    for(int i = 0; i < 50; i++)
        printf("%d ", 2*i + 1);//等差数列通项公式
    printf("\n");

    return 0;
}
//1 3 5 7 9 11 ...
//2*i + 1
//1 3 5 7 ...

#endif
