//
//  02rel.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.

//

#if 0

#include <stdio.h>

int main(void){
    printf("1 == 1 : %d\n", 1==1);
    printf("1 != 1 : %d\n", 1!=1);
    printf("1 > 2: %d\n", 1>2);
    printf("1 < 2: %d\n", 1<2);
    printf("2 >= 2: %d\n", 2>=2);
    printf("1 >= 2: %d\n", 1>=2);

    //计算机在判断两个数据之间的关系的时候,
    //一步一步计算
    //5<4<3
    //1. 5<4 -> 不成立 -> 0
    //2. 0 < 3 -> 成立 -> 1
    printf("5<4<3 : %d\n", 5<4<3);

    return 0;
}

#endif

