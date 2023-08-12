//
//  fibo.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/15.
//
#if 0
#include <stdio.h>

int f(int n){
    if(n < 3)
        return 1;//设置退出条件
    return f(n-1) + f(n-2);
}


int main(void){
    printf("%d\n", f(13));
    return 0;
}
#endif


