//
//  main.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/12.
//
#if 0
//测试
#include "queue.h"

int main(void){
    queue_t queue;
    queue_init(&queue, 4);//4个元素的空间

    for(int i = 10; i <= 40; i+= 10){//10 20 30 40
        if(!queue_full(&queue))
            queue_push(&queue, i);//向队列中放入数据
    }
    printf("队列中有效数据个数为:%d\n", queue_size(&queue));
    //从队列中获取两个数据 10 20
    for(int i = 0; i < 2; i++){
        if(!queue_empty(&queue))
            printf("%d ", queue_pop(&queue));
    }
    printf("\n");
    printf("队列中有效数据个数为:%d\n", queue_size(&queue));
    //再将数据50 60入队, 然后将所有的数据获取出来, 判断队列中有效数据个数
    for(int i = 50; i <= 60; i += 10){//50 60 30 40
        if(!queue_full(&queue))
            queue_push(&queue, i);
    }
    while(!queue_empty(&queue))
        printf("%d ", queue_pop(&queue));//30 40 50 60
    printf("\n");
    printf("队列中有效数据个数为:%d\n", queue_size(&queue));

    //有始有终
    queue_deinit(&queue);
    return 0;
}
#endif

