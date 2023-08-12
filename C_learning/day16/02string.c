//
//  02string.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0
#include <stdio.h>

int main(void){
    char str[100] = {0};//分配内存用于暂存输入的字符串

    //scanf("%s", str);//按照字符串方式从键盘上输入字符串保存到str数组中, 遇到空格结束

    //printf("%s\n", str);

    gets(str);//从键盘捕获输入的字符串保存到str中 //字符串输入 //有可能输入的太多，存不下，有风险
    puts(str);//对于输入字符串, 会自动追加\n字符 //字符串输出

    return 0;
}
#endif

