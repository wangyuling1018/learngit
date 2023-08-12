#if 0

//虚拟地址空间布局
#include<stdio.h>
#include<stdlib.h>

const int const_global = 1;//常全局变量
int init_global = 2;//初始化全局变量
int uninit_global; //未初始化全局变量

int main(int argc,char* argv[],char* envp[]){
    const static int const_static = 3;//常静态变量
    static int init_static = 4;//初始化静态局部变量
    static int uninit_static;//未初始化静态局部变量
    const int const_local = 5;//常局部变量
    int local;//局部变量
    int* heap = malloc(sizeof(int));//堆变量
    char* string = "hello world!";//字面值常量

    printf("高地址------命令行参数和环境变量------\n");
    printf("        命令行参数:%p\n",argv);
    printf("          环境变量:%p\n",envp);
    printf("-----------------栈区-----------------\n");//局部变量
    printf("        常局部变量:%p\n",&const_local); //常局部变量是栈区的，常局部变量前加上static才是在代码区。
    printf("          局部变量:%p\n",&local);
    printf("-----------------堆区-----------------\n");
    printf("            堆变量:%p\n",heap);
    printf("----------------BSS区-----------------\n");
    printf("  未初始化全局变量:%p\n",&uninit_global);
    printf("  未初始化静态局部变量:%p\n",&uninit_static);//不带const
    printf("---------------数据区-----------------\n");
    printf("    初始化全局变量:%p\n",&init_global);
    printf("    初始化静态局部变量:%p\n",&init_static);//不带const
    printf("---------------代码区-----------------\n");
    printf("              函数:%p\n",main);
    printf("        字面值常量:%p\n",string);
    printf("        常全局变量:%p\n",&const_global); //带const属性
    printf("        常静态局部变量:%p\n",&const_static);//带const属性
    printf("低地址--------------------------------\n");
    return 0;
}
#endif
//全局变量：有const在代码区，有初始化在data区，未初始化在BSS区
//静态局部变量：有const在代码区，有初始化在data区，未初始化在BSS区
//常局部变量：有const，无const都在栈区，常局部变量是栈区的

/*
 高地址------命令行参数和环境变量------
         命令行参数:0x7ff7bfeff510
           环境变量:0x7ff7bfeff520
 -----------------栈区-----------------
         常局部变量:0x7ff7bfeff3b4
           局部变量:0x7ff7bfeff3b0
 -----------------堆区-----------------
             堆变量:0x600000010010
 ----------------BSS区-----------------
   未初始化全局变量:0x100008024
   未初始化局部静态变量:0x100008020
 ---------------数据区-----------------
     初始化全局变量:0x100008018
     初始化局部静态变量:0x10000801c
 ---------------代码区-----------------
               函数:0x100003b10
         字面值常量:0x100003cec
         常全局变量:0x100003ce4
         常静态局部变量:0x100003ce8
 低地址--------------------------------
 
 */
