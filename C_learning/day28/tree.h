//
//  tree.h
//  C_learning
//
//  Created by 王育玲 on 2023/5/16.
//

#ifndef tree_h
#define tree_h

//包含公共头文件
#include <stdio.h>
#include <stdlib.h>
//声明描述节点属性的结构体
typedef struct node{
    int data;
    struct node* left;//保存左子节点的地址
    struct node* right;//保存右子节点的地址
}node_t;
//声明描述树属性的结构体
typedef struct tree{
    struct node* root;
    int cnt;
}tree_t;
extern void tree_travel(tree_t* tree);//遍历整个有序二叉树
extern void tree_clear(tree_t* tree);
//定义插入新节点的函数
extern void tree_insert(tree_t* tree, int data);
//定义删除指定数字所在节点的函数
extern void tree_del(tree_t* tree, int data);
//修改节点值的函数
extern void tree_mod(tree_t* tree, int old_data, int new_data);

#endif /* tree_h */
