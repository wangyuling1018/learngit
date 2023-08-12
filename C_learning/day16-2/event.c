//
//  event.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0
//迷你备忘录
#include <stdio.h>
#include <string.h>//声明

int main(void){
    printf("================\n");
    printf("    迷你备忘录\n");
    printf("================\n");

    char event[31][256];//定义初始化二维数组来保存事件信息
    //初始化二维数组
    for(int i = 0; i < 31; i++)
        event[i][0] = '\0';//全部给0,没有任何的字符串
    for(;;){
        printf("备忘信息:");
        int nday = -1;
        //int nday = 3;
        scanf("%d", &nday);//输入日期
        if(nday < 0 || nday > 31){
            printf("无效日期.\n");
            continue;
        }
        if(0 == nday)
            break;//结束死循环,结束循环输入
        scanf("%s", event[nday-1]);//输入日期对应的事件信息字符串保存到数组中
    }
    printf("-----------------\n");
    printf("备忘信息列表\n");
    printf("-----------------\n");
    
    for(int i = 0; i < 31; i++)//打印信息列表
        if(strlen(event[i]))//打印备忘的信息,如果某天没有信息, 不打印
            printf("%d日:%s\n", i+1, event[i]);
    printf("-----------------\n");
    
    return 0;
}

#endif











