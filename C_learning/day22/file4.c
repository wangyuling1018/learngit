//
//  file4.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/12.
//
#if 0
//fwrite - fread
//fseek
#include <stdio.h>

int main(void){
    FILE* fp = fopen("c.txt", "w+");//读写, 存在清空, 不存在创建
    int a[] = {1,2,3,4,5,6,7,8};
    int len = sizeof(a) / sizeof(a[0]);
    int size = 0;
    //将数组a中的内容都写入到c.txt文件中
    size = fwrite(a, sizeof(int), len, fp);
    printf("实际写入了%d个元素\n", size);
    rewind(fp); //调整读写位置到头部 //== fseek(fp, 0, SEEK_SET);
    

    //读取8个int类型的数据到数组中
    int b[8] = {0};
    size = fread(b, sizeof(int), 8, fp);
    printf("实际读取了%d个元素\n", size);
    for(int i = 0; i < size; i++)
        printf("%d ", b[i]);
    printf("\n");

    //fseek函数演示
    int c[2] = {0};
    fseek(fp, 8, SEEK_SET);//从文件头开始向后数8个字节, 开始操作文件
    //1    2    3    4    5    6    7    8 -> int类型
    //---- ---- ---- ---- ---- ---- ---- ---- ---- ----
    //          ^
    fread(c, sizeof(int), 2, fp);//从当前位置读取2个int数据, 读写位置向后移动8字节
    printf("%d, %d\n", c[0], c[1]);
    //1    2    3    4    5    6    7    8 -> int类型
    //---- ---- ---- ---- ---- ---- ---- ---- ---- ----
    //                    ^
    fseek(fp, 8, SEEK_CUR);//从当前位置向后移动8字节, 到哪儿了
    //1    2    3    4    5    6    7    8 -> int类型
    //---- ---- ---- ---- ---- ---- ---- ---- ---- ----
    //                              ^
    //                              此时在7位置上
    fread(c, sizeof(int), 2, fp);//从当前位置读取2个int数据, 读写位置向后移动8字节
    printf("%d, %d\n", c[0], c[1]);
    //1    2    3    4    5    6    7    8 -> int类型
    //---- ---- ---- ---- ---- ---- ---- ---- ---- ----
    //                                        ^
    fseek(fp, -12, SEEK_END);//从文件末尾向前移动12个字节
    //1    2    3    4    5    6    7    8 -> int类型
    //---- ---- ---- ---- ---- ---- ---- ---- ---- ----
    //                         ^
    //                         到了6位置上
    fread(c, sizeof(int), 2, fp);//从当前位置读取2个int数据, 读写位置向后移动8字节
    printf("%d, %d\n", c[0], c[1]);
    //1    2    3    4    5    6    7    8 -> int类型
    //---- ---- ---- ---- ---- ---- ---- ---- ---- ----
    //                                   ^

    fseek(fp, 800, SEEK_SET);//从文件头向后移动800个字节
    printf("%ld\n", ftell(fp));


    return 0;
}

#endif

