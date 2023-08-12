//
//  02define.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0
#include <stdio.h>

//gcc -E 02define.c -o 02define.i
//vim 02define.i 按G跳转到文件末尾

//在代码 - PI 表示 3.14
#define PI (3.14)

int main(void){
    double r = 10;

    //面积,周长
    //如果后续修改3.14, 数量较大, 大量修改
    printf("面积:%lg\n", 3.14*r*r);
    printf("周长:%lg\n", 2 * 3.14 * r);
    
    //优秀代码
    //预处理阶段 - 所有的PI使用3.14进行替换, 然后做运算
    printf("面积:%lg\n", PI*r*r);
    printf("周长:%lg\n", 2 * PI * r);
    return 0;
}

#endif

