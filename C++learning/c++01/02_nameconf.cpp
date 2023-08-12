//
//  02_nameconf.cpp
//  C++11
//
//  Created by 王育玲 on 2023/2/17.
//


//体会 名字空间 是不是可以划分更精细逻辑单元（空间），能够有效避免名字的冲突问题
/* 笔记
 作用域限定符-----高可靠，麻烦。
 名字空间指令、名字空间声明--------低可靠，省事。
 */
#include <iostream>
namespace ICBC{ //名字空间的定义
    int g_money = 0;
    void save( int money ){//连声明带定义
        g_money += money;
    }
/*
    void pay(int money){
        g_money -= money;
    }
 */
}

namespace CCB{//名字空间的定义
    int g_money = 0;
    void save( int money ){//连声明带定义
        g_money += money;
    }
void pay(int money);//声明
}
void CCB::pay(int money){//定义，可以把声明和定义分开写，但是定义的前面要加作用域限定符"::"，什么什么中的。
    g_money -= money;
}

namespace ICBC{ //编译器会把散落在各处相同的命名空间，合并为一个名字空间，为了多人协作开发，分文件开发
    void pay(int money){
        g_money -= money;
    }
}
/*
int main( void ){
    ICBC::save( 10000 );//调用
    ICBC::pay( 3000 );
    std::cout << "工行卡余额：" << ICBC::g_money << std::endl;
    
    CCB::save( 4000 );
    CCB::pay( 3000 );
    std::cout << "建行卡余额：" << CCB::g_money << std::endl;
    return 0;
}
 */


