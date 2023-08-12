//
//  list.h
//  C_learning
//
//  Created by 王育玲 on 2023/5/12.
//
#if 0
#ifndef list_h
#define list_h

//头文件
#include <stdio.h>
#include <stdlib.h>
//描述节点信息的结构体
typedef struct node{
    int data;
    struct node* next;
}node_t;
//描述整个单链表结构体
typedef struct list{
    struct node* head;//头节点
    struct node* tail;//尾节点
}list_t;

extern void list_init(list_t* list);//初始化函数
//定义单链表遍历函数
void list_travel(list_t* list);
//定义插入新节点函数
void list_add(list_t* list, int data);
//后插函数
void list_add_last(list_t* list, int data);
//前插:插入到head和第一个有效节点之间
void list_add_first(list_t* list, int data);
//定义删除指定数据所在的节点
void list_del(list_t* list, int data);
//定义释放链表所有节点的函数
void list_deinit(list_t* list);

#endif /* list_h */
#endif

