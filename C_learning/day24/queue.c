//
//  queue.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/12.
//

#include "queue.h"


//队列初始化函数
void queue_init(queue_t* queue, int cap){
    queue->arr = (int *)malloc(sizeof(int)*cap);
    queue->cap = cap;
    queue->size = 0;
    queue->rear = 0;
    queue->front = 0;
}
//队列释放函数
void queue_deinit(queue_t* queue){
    free(queue->arr);
    queue->arr = NULL;
    queue->cap = 0;
    queue->size = 0;
    queue->rear = 0;
    queue->front = 0;
}

//判断是否为满的函数
int queue_full(queue_t* queue){
    return queue->size >= queue->cap;
}
//判断是否为空的函数
int queue_empty(queue_t* queue){
    //return queue->size == 0;
    return !queue->size;//size=0, !size=!0=1, 真
}
//获取队列中有效数据个数
int queue_size(queue_t* queue){
    return queue->size;
}
//入队函数定义 - 对列已经非满 //如果是满的，这个函数就不要调用了
void queue_push(queue_t* queue, int data){
    if(queue->rear >= queue->cap)
        queue->rear = 0;//构造循环队列
    queue->arr[queue->rear++] = data;//将数据放入队列
    //queue->rear++;
    queue->size++;//有效数据个数加一
}
//出队函数定义
int queue_pop(queue_t* queue){
    //循环出队
    if(queue->front >= queue->cap)
        queue->front = 0;
    queue->size--;//更新计数
    return queue->arr[queue->front++];
}








