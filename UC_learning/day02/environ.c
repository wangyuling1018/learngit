//
//  environ.c
//  UC_learning
//
//  Created by 王育玲 on 2023/5/17.
//
#if 0
//根据环境变量表打印环境变量

//输出结果与bash的环境变量差不多一致，a.out是bash的儿子，儿子继承爹的环境变量
#include <stdio.h>

//envp和全局变量eniron一样都是当前进程的环境变量表
int main(int argc,char* argv[],char* envp[]){
    extern char** environ;
    for(char** pp = environ;*pp != NULL; pp++)
        printf("%s\n",*pp);
    
    printf("-------------------------------\n");
    printf("envrion = %p\n",environ);
    printf("envp = %p\n",envp);
    return 0;
}
#endif

