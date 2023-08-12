//
//  fact.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/15.
#if 0
#include <stdio.h>

int fact(int n){
    if(n <= 1)
        return 1;
    return n * fact(n-1);
}

int main(void){
    int n = 7;
    printf("%d\n", fact(n));
    return 0;
}
#endif


