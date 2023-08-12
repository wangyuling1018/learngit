//
//  04const_pointer.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//
#if 0

#include <stdio.h>

int main(void){
    //1.修饰普通变量
    const int a = 520;//a以后就是常量了, 只能查看不能修改
    //a = 500;
    printf("a = %d\n", a);
    //2.常量指针:指针变量保存的地址可以改变, 但是指向的内存值不能改变, 起到保护作用
    int b = 520;
    const int *p = &b;//定义初始化产量指针p, p保存b的首地址, p指向b
    //*p = 10000;//error
    printf("%d\n", *p);
    int c = 521;
    p = &c;//可以的, 让p保c的首地址, 现在p指向c了, 而不再指向b
    //*p = 10000;//error
    printf("%d\n", *p);
    //3.指针常量:
    int d = 100;
    int* const p1 = &d;//定义初始化指针常量永远指向d
    *p1 = 101;//ok
    //p1 = &c;//error, p1永远指向d
    printf("%d\n", *p1);
    //4.常量指针常量, 指针变量保存的地址和指向的内存都不能修改
    int e = 400;
    const int* const p2 = &e;//定义初始化常量指针常量p2, p2永远指向e, 内存值不可以修改
    //*p2 = 100;//no
    //p2 = &d;//no
    printf("%d\n", *p2);

    return 0;
}
#endif

