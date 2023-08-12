//
//  dlist.h
//  C_learning
//
//  Created by 王育玲 on 2023/5/15.
//

#ifndef dlist_h
#define dlist_h

//包含公共头文件
#include <stdio.h>
#include <stdlib.h>
//声明描述节点的数据结构
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node_t;
//声明描述双链表的数据结构
typedef struct list{
    struct node head;
    struct node tail;
}list_t;

//声明操作函数
extern void list_init(list_t* list);//初始化函数
int list_empty(list_t* list);//判断空函数定义
int list_size(list_t* list);//获取双链表有效节点个数
//定义插入节点的函数
void insert_node(node_t* pfirst, node_t* pmid, node_t* pnew);
//向链表中插入新节点
//按照顺序插入函数
void list_add(list_t* list, int data);
   
//定义前插函数, 插入到head和第一个有效节点之间
void list_add_head(list_t* list, int data);

//定义后插函数, 插入到最后一个有效节点和尾节点之间
void list_add_last(list_t* list, int data);

//定义删除pmid指向的节点
static void del_node(node_t* pfirst, node_t* pmid, node_t* plast);
//删除指定的节点
void list_del(list_t* list, int data);
//删除第一个有效节点
void list_del_head(list_t* list);
//删除最后一个有效节点
void list_del_tail(list_t* list);

//根据节点编号获取节点数据的函数
int list_get(list_t* list, int index);
//清楚链表中的内容
void list_deinit(list_t* list);

#endif /* dlist_h */
