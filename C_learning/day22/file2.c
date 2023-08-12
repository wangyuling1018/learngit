//
//  file2.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/12.
//
#if 0

//file2.c
//格式化输出与输入
#include <stdio.h>

int main(void){
    FILE* fp = NULL;
    //以只写的方式打开文件, 存在清空, 不存在创建
    fp = fopen("/Users/wyl/C++_Projects/C_learning/day22/a.txt", "r");
    if(NULL == fp){
        printf("file open failed\n");
        return -1;
    }
    printf("file open success\n");
    //按照一定的格式从文件中读取数据
    int i = 0;
    char a[20] = {0};
    double d = 0.0;
    fscanf(fp, "%d%s%lf", &i, a, &d);
    //关闭文件
    fclose(fp);
    fp = NULL;//好习惯
    printf("i = %d, a = %s, d = %lg\n", i, a, d);

    //按照一定的格式从想文件中写入数据
    FILE* fpw = fopen("/Users/wyl/C++_Projects/C_learning/day22/b.txt", "w+");
    //将变量i, a, d按照一定的格式保存到fpw对应的b.txt文件中
    fprintf(fpw, "copy:%d %s %lf\n", i, a, d);
    fclose(fpw);
    fpw = NULL;

    return 0;
}
#endif


