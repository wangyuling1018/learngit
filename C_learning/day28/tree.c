//
//  tree.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/16.
//

#include "tree.h"

//定义遍历有序二叉树的递归函数
//根节点
static void travel(node_t* proot){
#ifdef A
    //先序遍历
    if(proot != NULL){
        printf("%d ", proot->data);//打印节点自身数据
        travel(proot->left);//遍历左子树
        travel(proot->right);//遍历右子树
        return;
    }
#endif
#ifdef  B //中序遍历
    if(proot != NULL){
        travel(proot->left);//遍历左子树
        printf("%d ", proot->data);//打印节点自身数据
        travel(proot->right);//遍历右子树
        return;
    }
#endif
#ifdef C //后序遍历
    if(proot != NULL){
        travel(proot->left);//遍历左子树
        travel(proot->right);//遍历右子树
        printf("%d ", proot->data);//打印节点自身数据
        return;
    }

#endif
}
//遍历
void tree_travel(tree_t* tree){
    //调用递归函数从根节点开始遍历
    travel(tree->root);
    printf("\n");
}

//清除所有节点的递归函数
//clear(&tree->root)
static void clear(node_t** pproot){
    if(*pproot != NULL){
        clear(&(*pproot)->left);//释放左节点 //(*pproot)->left 获取left，然后&取left的地址。
        clear(&(*pproot)->right);          //(*pproot)->right 获取right，然后&取right的地址。
        free(*pproot);//释放节点内存
        *pproot = NULL;
    }
}

//定义清空所有节点的函数
void tree_clear(tree_t* tree){
    clear(&tree->root);
    tree->cnt = 0;//节点个数为0, 清零
}

//定义创建新节点的函数
static node_t* create_node(int data){
    node_t* pnew = (node_t*)malloc(sizeof(node_t));
    pnew->data = data;
    pnew->left = NULL;
    pnew->right = NULL;
    return pnew;//返回新节点首地址
}

//向有序二叉树中插入一个新的节点
//1.根节点的地址
//2.新节点的地址
static void insert(node_t** pproot, node_t* pnew){
    if(*pproot == NULL){
        *pproot = pnew;//插入新节点
        return;
    }
    if((*pproot)->data > pnew->data){//插入到左子树
        insert(&(*pproot)->left, pnew);
        return;
    }else{//插入到右子树
        insert(&(*pproot)->right, pnew);
        return;
    }
}
//定义插入新节点的函数
void tree_insert(tree_t* tree, int data){
    //1.创建新节点
    node_t* pnew = create_node(data);
    //2.调用递归函数插入新节点
    insert(&tree->root, pnew);
    //3.更新计数
    tree->cnt++;
}
//定义查找节点的递归函数
static node_t** find(node_t** pproot, int data){
    //1.是否为空
    if(*pproot == NULL)
        return pproot;//没有找到
    //2.比较
    if((*pproot)->data == data)
        return pproot;//找到了
    else if((*pproot)->data > data){
        //往左边找
        return find(&(*pproot)->left, data);
    }else{
        //往右边找
        return find(&(*pproot)->right, data);
    }
}
//定义查找节点的函数
static node_t** find_node(tree_t* tree, int data){
    return find(&tree->root, data);
}

//定义删除指定数字所在节点的函数
void tree_del(tree_t* tree, int data){
    //1.找节点
    node_t** ppnode = find_node(tree, data);
    if(*ppnode == NULL){
        printf("没有找到节点.\n");
        return;
    }
    //2.找新爹
    if((*ppnode)->left != NULL)
        insert(&(*ppnode)->right,  (*ppnode)->left);
    //3.提一级
    node_t* ptmp = *ppnode;//临时备份要删除的节点, 将来用于free释放
    *ppnode = (*ppnode)->right;//提一级
    free(ptmp);//释放要删除的节点
    tree->cnt--;
}
//修改节点值的函数
//20 - 130
void tree_mod(tree_t* tree, int old_data, int new_data){
    //1.删除旧节点
    tree_del(tree, old_data);
    //2.添加新节点
    tree_insert(tree, new_data);
}









