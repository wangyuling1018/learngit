//
//  list.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/12.
//
#if 0

#include "list.h"

//创建一个新的节点
static node_t* create_node(int data){
    node_t* pnew = malloc(sizeof(node_t));//分配节点内存
    pnew->data = data;//初始化节点数据
    pnew->next = NULL;
    return pnew;
}

//初始化函数
void list_init(list_t* list){
    //1.给头节点分配内存
    list->head = create_node(0);
    //2.给尾节点分配内存
    list->tail = create_node(0);
    //3.头节点指向尾节点, 尾节点指向NULL
    list->head->next = list->tail;
    list->tail->next = NULL;
}

//定义单链表遍历函数
void list_travel(list_t* list){
    for(node_t* pnode = list->head; pnode != list->tail; pnode = pnode->next){
        //1.定义三个游标
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        //2.判断pmid是否为有效节点
        if(pmid != list->tail)
            printf("%d ", pmid->data);
    }
    printf("\n");
}

//定义插入新节点函数
//按照顺序进行插入
void list_add(list_t* list, int data){
    //1.创建新节点
    node_t* pnew = create_node(data);
    //2.遍历查找要插入的位置
    //让pfirst指向要插入的前一个节点, 让pmid指向要插入的后一个节点
    //将pnew插入到pfirst和pmid之间即可
    for(node_t* pnode = list->head; pnode != list->tail; pnode = pnode->next){
        //1.定义三个游标
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        //如果要插入的节点的数据比所有节点数据都大, 插入到最后一个有效节点和尾节点之间
        if(pmid->data >= pnew->data || pmid == list->tail){
            pfirst->next = pnew;
            pnew->next = pmid;
            break;
        }
    }
}

//后插函数
//将新的节点插入在最后一个有效节点和尾节点之间
void list_add_last(list_t* list, int data){
    //1.创建新节点
    node_t* pnew = create_node(data);
    //2.遍历查找要插入的位置
    for(node_t* pnode = list->head; pnode != list->tail; pnode = pnode->next){
        //1.定义三个游标
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(pmid == list->tail){//pmid指向了尾节点, 此时pfirst指向了最后一个有效节点
            pfirst->next = pnew;
            pnew->next = pmid;
            break;
        }
    }
}

//前插:插入到head和第一个有效节点之间
void list_add_first(list_t* list, int data){
    //创建新节点
    node_t* pnew = create_node(data);
    //插入到头节点和第一个有效节点之间
    //先将原先的第一个有效节点存储起来
    node_t* ptmp = list->head->next;
    list->head->next = pnew;
    pnew->next = ptmp;
}

//定义删除指定数据所在的节点
//让pmid指向要删除的那个节点
void list_del(list_t* list, int data){
    for(node_t* pnode = list->head; pnode != list->tail; pnode = pnode->next){
        //1.定义三个游标
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(pmid->data == data && pmid != list->tail){
            pfirst->next = plast;//让前一个节点指向后一个节点
            free(pmid);//释放pmid指向的存储区内存
            break;
        }
    }
    
}

//定义释放链表所有节点的函数
void list_deinit(list_t* list){
    node_t* pnode = list->head;
    while(pnode){//pnode != NULL
        node_t* ptmp = pnode->next;//临时备份下一个节点
        free(pnode);//释放pnode指向的节点内存
        pnode = ptmp;//pnode指向原先的下一个节点
    }
}



#endif
