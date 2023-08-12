//
//  main.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/12.
//
#if 0
//i栈的测试
#include "stack.h"

int main(void){
    //定义栈变量
    stack_tt stack;
    
    //初始化
    stack_init(&stack, 20);//指定容量为20
    int data = 1000;
    while(!stack_full(&stack))//循环压栈
        stack_push(&stack, data++);
    printf("有效数据个数为:%d\n", stack_size(&stack));

    //循环出栈
    while(!stack_empty(&stack))
        printf("%d ", stack_pop(&stack));
    printf("\n");

    printf("有效数据个数为:%d\n", stack_size(&stack));
    
    //释放栈变量
    stack_deinit(&stack);
    return 0;
}
#endif

