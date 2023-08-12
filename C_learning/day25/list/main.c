//
//  main.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/12.
//
#if 0
//单链表测试
#include "list.h"

int main(void){
    list_t list;//创建单链表
    list_init(&list);//初始化
    
    //链表操作
    list_add(&list, 10);
    list_add(&list, 20);
    list_add(&list, 30);
    list_add(&list, 40);
    list_add(&list, 50);
    list_travel(&list);
    list_add_first(&list, 5);
    list_add_first(&list, 1);
    list_travel(&list);
    list_add_last(&list, 80);
    list_add_last(&list, 90);
    list_travel(&list);
    list_del(&list, 30);
    list_del(&list, 40);
    list_travel(&list);


    list_deinit(&list);//释放内存
    return 0;
}
#endif

