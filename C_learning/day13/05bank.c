//
//  05bank.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//
#if 0

//0bank.c:银行系统
#include <stdio.h>
#include <stdlib.h>//exit函数

double g_balance = 0;//余额
double g_rate = 0.01;//利率

//定义菜单显示的函数
int menu(void){
    printf("------------------\n");
    printf("     银行系统\n");
    printf("------------------\n");
    printf("[1]清空账户\n");
    printf("[2]存款\n");
    printf("[3]取款\n");
    printf("[4]查询余额\n");
    printf("[5]利息结算\n");
    printf("[6]调整利率\n");
    printf("[0]退出\n");
    printf("------------------\n");
    printf("请选择:");
    int select = -1;
    scanf("%d", &select);
    return select;
}
//查询余额
void query(void){
    printf("当前余额为:%lg\n", g_balance);
}
//清空账户
void clear(void){
    g_balance = 0;
    query();
}
//存款
void save(void){
    printf("存款金额:");
    double Save;
    scanf("%lg", &Save);
    g_balance += Save;
    query();
}
//取款
void get(void){
    printf("取款金额:");
    double Get;
    scanf("%lg", &Get);
    if(g_balance < Get)
        printf("余额不足.\n");
    else{
        g_balance -= Get;
        query();
    }
}
//利息结算
void settle(void){
    g_balance *= (1 + g_rate);
    query();
}
//调整利率
void adjust(void){
    printf("当前利率:%lg\n", g_rate);
    printf("存款利率:");
    scanf("%lg", &g_rate);
}
//退出程序
void quit(void){
    printf("谢谢使用,再见.\n");
    exit(0);//标准C库函数, 直接让程序在这里结束
}


int main(void){
    for(;;){
        switch(menu()){
            case 1:
                clear();//注销账户
                break;
            case 2:
                save();//存款
                break;
            case 3:
                get();//取款
                break;
            case 4:
                query();//查询余额
                break;
            case 5:
                settle();//利息结算
                break;
            case 6:
                adjust();//调整利率
                break;
            case 0:
                quit();//退出程序
                break;
            default:
                printf("选择错误.\n");
        }
    }
    return 0;
}
#endif

