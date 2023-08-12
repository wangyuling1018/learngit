//
//  07for.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0
#include <stdio.h>

int main(void){
    //形式1
    int i;//循环变量
    //i=0;
    //i<5; printf(0); i++; i=1
    //i<5; printf(1); i++; i=2
    //i<5; printf(2); i++; i=3
    //i<5; printf(3); i++; i=4
    //i<5; printf(4); i++; i=5
    //i<5; no ->结束循环
    for(i = 0; i < 5; i++){
        printf("i = %d\n", i);
    }
    printf("--------------------\n");
    //形式2
    int j = 0;
    for(; j < 5; j++)
        printf("j = %d\n", j);
    printf("--------------------\n");
    //形式3
    int k = 0;
    for( ; k < 5; ){
        printf("k = %d.\n", k);
        k++;
    }
    printf("--------------------\n");
    //形式4
    //while(1){
    /*
    for(;;){
        printf("hello,world\n");
    }
    */
    printf("--------------------\n");
    int h = 0;
    for(;;){
        printf("h = %d\n", h);
        h++;
        if(h >= 5)
            break;//退出当前的for循环
    }
    printf("--------------------\n");
    //形式5
    //比较常用
    for(int p = 0; p < 5; p++){//p只能用于当前for循环,出了for循环无效
                                //C99标准支持的特性, 如果gcc不支持, 添加选项-std=c99
                                //gcc 07for.c -o 07for -std=c99
        printf("p = %d\n", p);
    }
    printf("--------------------\n");
    //形式6:
    //continue; - 关键字
    int z = 0;
    for(z = 0; z < 5; z++){
        if(z == 3){
            continue;//当z=3,条件成立, 执行continue; 跳转到表达式3,也即是z++
                    //直接开启下一次循环
            printf("我会被执行吗.\n");
        }
        printf("z = %d.\n", z);
    }
    printf("--------------------\n");
    return 0;
}
#endif











