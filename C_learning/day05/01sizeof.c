//
//  01sizeof.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/6.
//

#if 0

//sizeof关键字演示
#include <stdio.h>

int main(void){
    printf("%lu\n", sizeof(char));
    printf("%lu\n", sizeof(unsigned char));
    printf("%lu\n", sizeof(short));
    printf("%lu\n", sizeof(unsigned short));
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(unsigned int));
    printf("%lu\n", sizeof(long));
    printf("%lu\n", sizeof(unsigned long));
    printf("%lu\n", sizeof(float));
    printf("%lu\n", sizeof(double));
    unsigned int a = 520;
    //gcc给整形常量默认的类型是int类型
    printf("%lu %lu %lu\n", sizeof(a), sizeof(520), sizeof(1+1));
    sizeof(a = 1024);//无效赋值
    printf("a = %d.\n", a);
    return 0;
}

#endif

