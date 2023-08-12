//
//  file3.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/12.
//
#if 0
//file3.c
//非格式化输出与输入
//echo 1234567890abcd > a.txt
//.file3
//cat a.txt
//cat b.txt
//_ _ _ \0
#include <stdio.h>

int main(void){
    FILE* fpr = fopen("a.txt", "r");
    FILE* fpw = fopen("b.txt", "w+");
    char str[4] = {0};//暂存从文件中读取的字符串
    while(fgets(str, 4, fpr) != NULL) //循环从文件中读取3个字符
        fputs(str, fpw);//将读取到的数据写入到文件中

    fclose(fpr);
    fclose(fpw);

    return 0;
}
#endif

