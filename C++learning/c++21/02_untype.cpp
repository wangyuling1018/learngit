//
//  02_untype.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/2.
//

/*
 宏可摆脱数据类型的限制
 1.宏是预处理阶段针对代码的纯文本替换
 2.宏本身没有函数的语义（不会对数据类型进行检查）
 3.因此借助参数宏虽然可以摆脱类型的约束和限制，但同时也丧失了对数据类型的检查
 
 */

#if 0
#include <iostream>
using namespace std;

#define Max(x,y)  (x > y ? x : y)

int main(){
    int nx = 10, ny = 20;
    cout << Max(nx,ny) << endl;
    //      (nx > ny ? nx : ny)
    double dx = 1.23, dy = 4.56;
    cout << Max(dx, dy) << endl;
    //      (dx > dy ? dx : dy)
    string sx = "world", sy = "hello";
    cout << Max(sx,sy) << endl;     // world
    //      (sx > sy ? sx : sy)
    char cx[256] = "world", cy[256]="hello";
    cout << Max(cx,cy) << endl;     // hello : 数组名是数组的首地址
    //      (cx > cy ? cx : cy)
    return 0;
}
#endif
