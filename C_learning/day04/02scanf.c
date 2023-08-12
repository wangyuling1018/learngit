//
//  02scanf.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/6.
//

/*
 *实验步骤:
 cd /home/tarena/stdc/day04
 vim 02scanf.c //编辑
 gcc 02scanf.c -o 02scanf
 ./02scanf
 * */

#if 0
#include <stdio.h>
int main(void){
    int age;//定义变量, 分配4字节内存, 之定义不初始化, gcc会给一个随机数
    printf("age = %d.\n", age);
    printf("请输入年龄:");
    scanf("%d", &age);//&age:获取变量age的内存首地址, %d:按照整形数据的形式从键盘输入
                    //程序执行到scanf函数, 程序就停止不动, 等待用户从键盘输入
                    //输入一个整形数据, 一旦输入完毕, 按回车键, 程序立刻从scanf函数
                    //结束继续向下运行, 将输入的数字保存到变量age中
    printf("age = %d.\n", age);

    int height;//定义变量, 分配4字节内存, 存储身高
    printf("请输入两个数字, 数字之间使用空格隔开:");
    scanf("%d%d", &age, &height);
    printf("age = %d, height = %d.\n", age, height);
    return 0;
}
#endif




