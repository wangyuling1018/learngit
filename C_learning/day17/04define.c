//
//  04define.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0
//通过-D选项可以传递给常量宏,字符串使用转移字符 \" 得到 "
//gcc -DSIZE=100 -DTOMORROW=\"Sunday\" 04define.c -o 04define
#include <stdio.h>

int main(void){
    int arr[SIZE] = {0};

    //初始化数组的值
    for(int i = 0; i < SIZE; i++)
        arr[i] = i + 100;

    for(int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("%s\n", TOMORROW);

    //调试程序相关宏  //使用预定义宏
    int* p = NULL;
    int a = 100;
    //p = &a;
    //假设在此处忘记对p赋值
    if(p == NULL){
        //p有问题
        printf("此处出现了空指针:\n"
                "日期:%s \n"
                "事件:%s \n"
                "文件:%s \n"
                "函数:%s \n"
                "行号:%d\n",
                __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__);
        return -1;
    }
    return 0;
}
#endif







