//
//  02pointer_ret.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//

/*
                内存生命周期            使用范围
局部变量            函数/块              函数/块
静态局部变量         程序                函数/块
全局变量            程序                所有文件（外部变量）
静态全局变量         程序                定义文件
全局函数            程序                所有文件
静态全局函数         程序                定义文件
 */
#if 0
//指针函数:函数的返回值是一个指针
#include <stdio.h>

extern int* A(void);//函数A返回一个int类型的指针

int main(void){
    int* p = NULL;
    p = A();//调用指针函数A并且保存起返回值, 返回的地址给变量p
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);
    *p = 1000;
    printf("*p = %d\n", *p);

    return 0;
}
int g_a = 521;//全局变量
static int g_b = 522;//静态全局变量

int* A(void){
    //int a = 520;//局部变量
    static int b = 520;//静态局部变量
    //return &a;//返回局部变量ａ的地址,不可以,  //函数结束, 局部变量a会被释放, p指向已经被释放的a的地址, p为野指针
    //return &b;//可以的，静态局部变量的生命周期是程序
    //return &g_a;//可以的
    return &g_b;
}

#endif

/*输出结果：
 p = 0x100008028
 *p = 522
 *p = 1000
 */
