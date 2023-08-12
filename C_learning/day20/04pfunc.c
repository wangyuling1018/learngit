//
//  04pfunc.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/11.
//
#if 0
//函数指针第一种用法：缺点 - 定义的时候, 很麻烦
//函数指针本质上就是自定义的数据类型, 将来可以使用这种数据类型来保存函数的地址
#include <stdio.h>

int add(int x, int y){
    return x+y;
}
int sub(int x, int y){
    return x-y;
}

int main(void){
    int ret = 0;
    //定义初始化函数指针变量pfunc并且保存add函数的首地址
    //pfunc变量对应的数据类型 - 描述其指向的函数数据类型
    //去掉变量名pfunc, 剩余的都是数据类型 - pfunc数据类型 int (*)(int, int)
    //该数据类型是自定义的数据类型
    int (*pfunc)(int, int) = add; //缺点 - 定义的时候, 很麻烦
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

