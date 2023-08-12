//
//  main.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/15.
//
#if 0
#include "dlist.h"
int main(void){
    
    list_t list;
    list_init(&list);
    
    //各种插入节点
    list_add_head(&list, 50);
    list_add_head(&list, 30);
    list_add_last(&list, 70);
    list_add_last(&list, 100);
    list_add(&list, 40);
    list_add(&list, 20);
    list_add(&list, 80);
    list_add(&list, 90);
    list_add(&list, 60);
    list_add(&list, 10);
    list_add(&list, 110);
    list_add(&list, 120);

    int size = list_size(&list);
    for(int i = 0; i < size; i++){
        printf("%d ",list_get(&list, i));
    }
    printf("\n");
    
    //删除节点
    list_del_head(&list);
    list_del_tail(&list);
    
    size = list_size(&list);
    for(int i = 0; i < size; i++){
        printf("%d ",list_get(&list, i));
    }
    printf("\n");
    
    list_deinit(&list);
    return 0;
    
}
#endif

