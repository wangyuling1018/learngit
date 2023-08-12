//
//  03switch.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0
#include <stdio.h>

int main(void){
    /*
    float l = 1.0;
    switch(l){
        case 1.0:
            break;
    }
    switch("abc"){
        case "abc":
            break;
    }
    int a = 520;
    switch(a){
        case 520:
            break;
        case 520:
            break;
    }
    */
    int a = 520;
    switch(a){
        case 520:
            printf("520.\n");
        case 521:
            printf("521.\n");
        case 522:
            {
                int b = 522;
                printf("%d.\n", b);
                break;
            }
    }

    //printf("%d.\n", b);//不允许访问
    return 0;
}

#endif

