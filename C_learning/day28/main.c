//
//  main.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/16.
//
#if 0
//main.c 测试
#include "tree.h"

int main(void){
    tree_t tree;
    tree.root = NULL;
    tree.cnt = 0;

    tree_insert(&tree, 50);
    tree_insert(&tree, 70);
    tree_insert(&tree, 60);
    tree_insert(&tree, 30);
    tree_insert(&tree, 20);
    tree_insert(&tree, 40);
    tree_insert(&tree, 10);
    tree_insert(&tree, 90);
    tree_insert(&tree, 80);
    tree_travel(&tree);
    tree_del(&tree, 40);
    tree_del(&tree, 30);
    tree_mod(&tree, 10, 567);
    tree_travel(&tree);
    tree_clear(&tree);
    tree_travel(&tree);
    return 0;
}
#endif

