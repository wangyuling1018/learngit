//
//  03void_pointer.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//
#if 0

#include <stdio.h>

int main(void){
    int a = 520;
    void* p = &a;//p保存a的地址, p指向a
    //printf("%d\n", *p); //error,目标类型不确定，不能解引用，gcc迷茫了

    //1.间接使用
    //将无类型指针变量p强制转换为int类型指针, 再赋值给变量p1
    //p1也指向a
    int* p1 = (int *)p;
    printf("*p1 = %d\n", *p1);
    *p1 = 521;
    printf("*p1 = %d\n", *p1);

    //2.直接使用
    *(int *)p = 522;//先将p的数据类型转换为int类型指针, 然后再做解引用
    printf("a = %d\n", a);

    //3.运算
    printf("%p\n", p);
    printf("%p\n", ++p);
    printf("%p\n", ++p);
    return 0;
}
#endif

