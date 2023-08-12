//
//  file.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/12.
//
#if 0
//file.c
//文件的打开和关闭
#include <stdio.h>

int main(void){
    FILE* fp = NULL;
    //以只写的方式打开文件, 存在清空, 不存在创建
    fp = fopen("/Users/wyl/C++_Projects/C_learning/day22/a.txt", "w");
    if(NULL == fp){
        printf("file open failed\n");
        return -1;
    }
    printf("file open success\n");

    //关闭文件
    fclose(fp);
    fp = NULL;//好习惯
    return 0;
}

#endif

