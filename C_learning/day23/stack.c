//
//  stack.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/12.
//
#include "stack.h"
//定义初始化函数
void stack_init(stack_tt* stack, int cap){
    stack->arr = malloc(sizeof(int)*cap);//给栈分配内存
    stack->cap = cap;//初始化容量
    stack->top = 0;//空栈, 一开始没有数据 - 入栈 - 0 - top=0
}

//释放栈内存函数
void stack_deinit(stack_tt* stack){
    free(stack->arr);//释放内存
    stack->arr = NULL;
    stack->cap = 0;
    stack->top = 0;
}

//判断栈是否为满的函数
int stack_full(stack_tt* stack){
    return stack->top >= stack->cap;//成立, 满, 返回1;否则, 返回0
}
//判断栈是否为空的函数逆
int stack_empty(stack_tt* stack){
    return stack->top == 0;
}

//定义入栈函数
void stack_push(stack_tt* stack, int data){
    stack->arr[stack->top++] = data;
    //stack->top++;
}

//定义出栈函数
int stack_pop(stack_tt* stack){
    //stack->top--;
    return stack->arr[--stack->top];
}

//定义获取栈有效数据个数的函数
int stack_size(stack_tt* stack){
    return stack->top;
}





