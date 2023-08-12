//
//  dlist.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/15.
//

#include "dlist.h"

//双链表初始化函数
void list_init(list_t* list){
    //对于头节点的初始化
    list->head.next = &list->tail;
    list->head.prev = NULL;
    list->head.data = 0;

    //对于尾节点的初始化
    list->tail.prev = &list->head;
    list->tail.next = NULL;
    list->tail.data = 0;
}

//判断空函数定义
int list_empty(list_t* list){
    return list->head.next == &list->tail;//空, 返回1; 非空返回0
}

//获取双链表有效节点个数
int list_size(list_t* list){
    int count = 0;//记录节点个数
    for(node_t* pnode = &list->head; pnode != &list->tail; pnode = pnode->next){
        //制造三个游标
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(pmid != &list->tail)
            count++;//更新计数
    }
    return count;
}

//构造新节点
static node_t* create_node(int data){
    node_t* pnew = malloc(sizeof(node_t));
    pnew->data = data;
    pnew->next = NULL;
    pnew->prev = NULL;
    return pnew;
}

//定义插入节点的函数
void insert_node(node_t* pfirst, node_t* pmid, node_t* pnew){
    pfirst->next = pnew;
    pnew->prev = pfirst;

    pnew->next = pmid;
    pmid->prev = pnew;
}

//向链表中插入新节点
//按照顺序插入函数
void list_add(list_t* list, int data){
    node_t* pnew = create_node(data);
    for(node_t* pnode = &list->head; pnode != &list->tail; pnode = pnode->next){
        //制造三个游标
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(pmid->data > pnew->data || pmid == &list->tail){
            insert_node(pfirst, pmid, pnew);
            break;
        }
    }
}

//定义前插函数, 插入到head和第一个有效节点之间
void list_add_head(list_t* list, int data){
    node_t* pnew = create_node(data);
    //制造游标
    node_t* pfirst = &list->head;
    node_t* pmid = pfirst->next;
    node_t* plast = pmid->next;
    //将pnew插入到pfirst和pmid之间
    insert_node(pfirst, pmid, pnew);
}

//定义后插函数, 插入到最后一个有效节点和尾节点之间
void list_add_last(list_t* list, int data){
    node_t* pnew = create_node(data);
    //制造游标
    node_t* pfirst = list->tail.prev;//指向原先的最后一个有效节点
    node_t* pmid = pfirst->next;//pmid指向尾节点
    node_t* plast = pmid->next;
    insert_node(pfirst, pmid, pnew);
}

//定义删除pmid指向的节点
static void del_node(node_t* pfirst, node_t* pmid, node_t* plast){
    pfirst->next = plast;
    plast->prev = pfirst;
    free(pmid);//释放内存
}
//删除指定的节点
void list_del(list_t* list, int data){
    for(node_t* pnode = &list->head; pnode != &list->tail; pnode = pnode->next){
        //制造三个游标
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(pmid->data == data && pmid != &list->tail){
            del_node(pfirst, pmid, plast);
        }
    }
}
//删除第一个有效节点
void list_del_head(list_t* list){
    //1.判断链表是否为空
    if(list_empty(list)){
        printf("链表为空, 无法删除\n");
        return;
    }
    //2.定义游标
    node_t* pfirst = &list->head;
    node_t* pmid = pfirst->next;
    node_t* plast = pmid->next;
    //3.删除pmid指向的节点
    del_node(pfirst, pmid, plast);
}
//删除最后一个有效节点
void list_del_tail(list_t* list){
    //1.判断链表是否为空
    if(list_empty(list)){
        printf("链表为空, 无法删除\n");
        return;
    }
    //2.定义游标
    node_t* plast = &list->tail;//plast指向尾节点
    node_t* pmid = plast->prev;//plast上一个节点 - 最后一个有效节点 - pmid
    node_t* pfirst = pmid->prev;//指向pmid的上一个节点
    //3.删除pmid指向的节点
    del_node(pfirst, pmid, plast);

}

//根据节点编号获取节点数据的函数
int list_get(list_t* list, int index){
    //循环+游标
    int size = 0;
    int res = 0;
    for(node_t* pnode = &list->head; pnode != &list->tail; pnode = pnode->next){
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(pmid != &list->tail && size == index){
            res = pmid->data;
            break;
        }
        size++;
    }
    return  res;
}

//清楚链表中的内容
void list_deinit(list_t* list){
    while(list->head.next != &list->tail){
        node_t* pfirst = &list->head;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        del_node(pfirst, pmid, plast);
    }
}
