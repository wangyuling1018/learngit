//
//  05pfunc.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/11.
//
#if 0
//函数指针第二种用法：可以使用typedef来给数据类型起别名，后续使用别名去定义函数指针变量
//函数指针本质上就是自定义的数据类型, 将来可以使用这种数据类型来保存函数的地址
#include <stdio.h>

int add(int x, int y){
    return x+y;
}
int sub(int x, int y){
    return x-y;
}
//声明函数指针类型为(int (*)(int, int)) 并且取别名为pfunc_t
typedef int (*pfunc_t)(int, int);
int main(void){
    int ret = 0;
    pfunc_t pfunc = add;
    //通过pfunc间接调用指向的add函数, 并且给add函数传递参数100, 200, 使用ret保存返回值
    ret = pfunc(100, 200);
    printf("add函数返回值是%d\n", ret);
    printf("%p, %p\n", pfunc, add);
    //pfunc是一个变量 - 可以存储其他函数的地址
    pfunc = sub;//pfunc指向了sub函数
    ret = pfunc(100, 200);
    printf("sub函数返回值是%d\n", ret);
    printf("%p, %p\n", pfunc, sub);
    return 0;
}
#endif

