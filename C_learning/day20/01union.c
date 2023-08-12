//
//  01union.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/11.
//
#if 0
//联合体演示
#include <stdio.h>

int main(void){
    union{
        unsigned int un;
        unsigned char uc[4];
    }mb;//直接定义联合体变量mb, 分配4字节
    mb.un = 0x12345678;//向4字节内存写入数据0x12345678
//un
//0x78  0x56  0x34  0x12
//__    __    __    __
//uc[0] uc[1] uc[2] uc[3]
    for(int i = 0; i < 4; i++)
        printf("%#x ", mb.uc[i]);
    printf("\n");
    //那里面的数据类型也是共用的么？
    //数据类型不是共用的, 共用的只是这几个字节的数据
    //un
    //0x78  0x56  0x43  0x12
    //__    __    __    __
    //uc[0] uc[1] uc[2] uc[3]
    mb.uc[2] = 0x43;//0x34->0x43
    printf("%#x\n", mb.un);
    
    //面试-如何判断大小端/当前主机字节序
    //采用联合计算当前主机字节序
    mb.un = 1;//0x00000001
    if(mb.uc[0])
        printf("小端.\n");
    else
        printf("大端.\n");



    return 0;
}

#endif

