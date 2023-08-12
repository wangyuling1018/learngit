//
//  queue.h
//  C_learning
//
//  Created by 王育玲 on 2023/5/12.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>//malloc
//声明描述队列信息的结构体数据类型和操作函数
typedef struct queue{
    int* arr;//首地址
    int cap;//容量
    int size;//有效数据个数
    int rear;//队尾, 入队
    int front;//队首, 出队
}queue_t;
extern void queue_init(queue_t* queue, int cap);//初始化队列
extern void queue_deinit(queue_t* queue);//释放队列内存


//判断是否为满的函数
int queue_full(queue_t* queue);
//判断是否为空的函数
int queue_empty(queue_t* queue);
//获取队列中有效数据个数
int queue_size(queue_t* queue);
//入队函数定义 - 对列已经非满
void queue_push(queue_t* queue, int data);
//出队函数定义
int queue_pop(queue_t* queue);

#endif /* queue_h */
