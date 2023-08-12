//
//  stack.h
//  C_learning
//
//  Created by 王育玲 on 2023/5/12.
//

#ifndef stack_h
#define stack_h
//包含公共的头文件
#include <stdio.h>
#include <stdlib.h>
//声明描述占占栈的属性的结构体
typedef struct stack{
    int* arr;//首地址
    int cap;//容量
    int top;//栈顶
}stack_tt;
//声明栈的操作函数

//定义初始化函数
void stack_init(stack_tt* stack, int cap);
//释放栈内存函数
void stack_deinit(stack_tt* stack);
//判断栈是否为满的函数
int stack_full(stack_tt* stack);
//判断栈是否为空的函数
int stack_empty(stack_tt* stack);
//定义入栈函数
void stack_push(stack_tt* stack, int data);
//定义出栈函数
int stack_pop(stack_tt* stack);
//定义获取栈有效数据个数的函数
int stack_size(stack_tt* stack);

#endif /* stack_h */
