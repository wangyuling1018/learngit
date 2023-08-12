//
//  04pointer.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//

#if 0
#include <stdio.h>

int main(void){
    printf("char-------\n");
    char a = 'a';
    char* pa = &a;
    printf("%p\n", pa);
    pa++;
    printf("%p\n", pa);

    printf("short-------\n");
    short b = 400;
    short* pb = &b;
    printf("%p\n", pb);
    pb++;
    printf("%p\n", pb);

    printf("int-------\n");
    int c = 1000;
    int* pc = &c;
    printf("%p\n", pc);
    pc++;
    printf("%p\n", pc);

    printf("long-------\n");
    long d = 1000;
    long* pd = &d;
    printf("%p\n", pd);
    pd++;
    printf("%p\n", pd);
    return 0;
}


#endif






