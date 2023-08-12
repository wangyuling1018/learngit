//
//  02enum.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/11.
//
#if 0
//枚举演示
#include <stdio.h>

enum COLOR {
    GREEN,//0- 别名 - GREEN
    RED, //1 - 别名 - RED
    BLUE = 10,//10 - 别名 - BLUE
    YELLOW//11 - 别名 - YELLOW
};

int main(void){
    printf("%d %d %d %d\n", GREEN, RED, BLUE, YELLOW);
    return 0;
}

#endif

