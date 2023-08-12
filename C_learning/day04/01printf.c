//
//  01printf.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/6.
//

/*printf输出函数演示
 *实验步骤:
 mkdir -p /home/tarena/stdc/day04/
 cd /home/tarena/stdc/day04
 vim 01printf.c //编辑
 gcc 01printf.c -o 01printf //编译程序 实际:一步到位, 练习:分步法
 ./01printf //运行:将硬盘上的可执行程序加载到内存并且让程序从main函数开始运行
 * */


#if 0
#include <stdio.h>
int main(void){
    printf("hello,world");
    printf("1234\n");//\n让光标到下一行的行首
    //hello,world1234
    //|光标在这里闪烁
    printf("abcd\n");

    printf("%d\n", 520);//%d:格式化占位符,整型数占位符, 帮助我们占一个位置将来
                        //显示输出整形数字
                        //将来输出的时候,使用整数520放到原先%d所在位置
                        //printf("520\n");
    printf("%d %d %d %d %d\n", 521, 1+1, 1-1, 2*2, 2/2);

    int a = 520;//分配4字节存储区存储数字520, int类型就是整形数据
    //printf - 按照一定的格式 - 输出变量
    //将来%d就会使用变量a的值作为替代
    printf("a = %d\n", a);//打印输出变量a的内存值520

    a = 521;//修改a的内存值为521
    printf("a = %d\n", a);//打印输出变量a的内存值521

    int b;//没有对变量进行初始化
    printf("b = %d\n", b);//变量b的值为随机值

    int c, d = 100;
    printf("c = %d, d = %d\n", c, d);
    return 0;
}
#endif
