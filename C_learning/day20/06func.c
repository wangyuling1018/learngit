//
//  06func.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/11.
//
#if 0
//回调函数：函数的参数是函数
//函数指针本质上就是自定义的数据类型, 将来可以使用这种数据类型来保存函数的地址
#include <stdio.h>
//声明函数指针类型为(int (*)(int, int)) 并且取别名为pfunc_t
typedef int (*pfunc_t)(int, int);


//定义回调函数sub和add, 将来这些函数可以作为参数传递给其他函数
int add(int x, int y){
    return x+y;
}
int sub(int x, int y){
    return x-y;
}
//cal函数:调用函数, 将来可以通过函数指针来调用回调函数
//pfunc:第三个参数 - 函数指针变量 - 将来pfunc参数可以传递函数首地址/函数名作为参数
int cal(int a, int b, pfunc_t pfunc){
    if(NULL == pfunc)
        return a*b;//如果第三个参数给了NULL, 计算a*b的值, 作为返回值
    else
        return pfunc(a,b);//如果给pfunc传递了函数名, 传递了回调函数
                          //那么cal函数就间接调用回调函数
}
int main(void){
    printf("%d\n", cal(100, 200, add));//pfunc_t func = add;
    printf("%d\n", cal(100, 200, sub));//pfunc_t func = sub;
    printf("%d\n", cal(100, 200, NULL));//pfunc_t func = NULL;
    return 0;
}
#endif

