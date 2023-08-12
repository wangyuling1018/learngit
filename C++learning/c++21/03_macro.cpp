//
//  03_macro.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/2.
//
/*
 利用宏构建通用函数框架：
 1.通过实例化宏，让预处理器将这个代换为针对不同数据类型的真正函数
 2.将宏的通用性和函数的类型安全性完美结合起来
 */

#if 0
#include <iostream>
using namespace std;
#define MAX(T) T max_##T(T x, T y){\
                return x > y ? x : y;\
                }
MAX(int)  //实例化宏
MAX(double)
//double max_double(double x,double y){....}
MAX(string)
//string max_string(string x,string y){....}
//MAX(char*)
//char* max_char*(char* x,char* y){....}  //函数名还带星号？？星号不会作为函数的一部分

#define Max(T) max_##T

int main(){
    int nx = 10, ny = 20;
    //cout << max_int(nx,ny) << endl;
    cout << Max(int)(nx,ny) << endl;
    double dx = 1.23, dy = 4.56;
    //cout << max_double(dx, dy) << endl;
    cout << Max(double)(dx,dy) << endl;
    string sx = "world", sy = "hello";
    //cout << max_string(sx,sy) << endl;
    cout << Max(string)(sx,sy) << endl;
    char cx[256] = "world", cy[256]="hello";
    //cout << max_string(cx,cy) << endl;
    cout << Max(string)(cx,cy) << endl;
    return 0;
}
#endif
