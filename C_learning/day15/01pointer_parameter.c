//
//  01pointer_parameter.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//
#if 0
//函数通过形参指针变量可以直接访问实参变量的内存
#include <stdio.h>

void swap_n(int x, int y){
    int c = x;
    x = y;
    y = c;
}
//swap_n(a,b);//将a和b的值复制了一份给x和y, 不会对a和b产生任何影响

//swap函数:pa和pb都是指针变量, 函数的形参
//通过pa来访问a, 通过pb来访问b
void swap(int *pa, int *pb){//int *pa = &a, int *pb = &b;
    int c = *pa;//直接将实参a的值给c, c=*pa=a
    *pa = *pb;//a = b, 将实参b的值给实参a
    *pb = c;//b = c,将ca的值直接给实参b
}

int main(void){
    int a = 10, b = 20;//实现两个变量数据的交换, a=20, b=10
    printf("a = %d, b = %d\n", a, b);
    /*
    int c = a;//c=10
    a = b;//a=20
    b = c;//b=10
    printf("a = %d, b = %d\n", a, b);
    */
    swap(&a, &b);///调用swap函数, 将实参a和b的地址, 分别给pa和pb
    printf("a = %d, b = %d\n", a, b);
    return 0;
}

#endif

