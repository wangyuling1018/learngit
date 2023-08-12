//
//  04_convert.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/18.
//

#if 0
//类型强转，专业叫法：显式类型转换，又叫强转
//隐式类型转换：编译器帮你转，编译器偷偷摸摸帮你转

/*C++不建议用强转，强转是告诉编译器必须转
 int a;
 double b = (double)a; //C语言风格的强转
 double b = double(a); //C++语言风格的强转
 */

/*总结：
 常转换 和 重类型转换 都局限在指针和引用的转换上
 静态转换 应用最广泛，只要是转换的逆转换可以隐式转换，就可以用静态转换
 */

// 显示（强制）类型转换
#include <iostream>
using namespace std;

//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    int a; double b; float c; short d; char e;
    //任何 基本类型的变量之间 都可以 隐式转换
    a = b = c = d = e;
    e = d = c = b = a;
    
    //任何其他类型的指针 到 void* 都可以隐式转换
    void* pv = &a;
    pv = &b;
    pv = &c;
    pv = &d;
    pv = &e;
    
    //void 到 任何其他类型的指针 都必须强转
    //静态强转的使用场景：隐式类型转换的逆转换，意思是该转换的逆转换可以隐式转换，就可以用静态转换
    // void* -> int* 的逆转换是 int* --> void*, int* --> void* 可以隐式转换
    int* pa = static_cast<int*>(pv);//(int*)(pv);//pv;
    double* pb =static_cast<double*>(pv);//(double*)(pv); //pv;
    float* pc = static_cast<float*>(pv);//(float*)(pv);//pv;
    short* pd = static_cast<short*>(pv);//(short*)(pv);//pv;
    char* pe = static_cast<char*>(pv);//(char*)(pv);//pv;
    
    //任何类型的非常指针 到 同类型的常指针 都可以隐式转换
    const int* cpa = pa;
    const double* cpb = pb;
    const float* cpc = pc;
    const short* cpd = pd;
    const char* cpe = pe;
    
    //任何类型的常指针 到 同类型的非常指针 都必须强转
    //const int* --> int* 的逆转换是 int* -> const int*, int* -> const int*可以隐式转换，虽然可以隐式逆转换，但是不能用静态转换
    //C++提供了专门用来去掉常属性的转换，去常转换，不能用静态转换
    //常转换：去除指针或引用上的const属性
    pa = const_cast<int*>(cpa);//(int*)(cpa);//cpa;
    pb = const_cast<double*>(cpb);//(double*)(cpb);//cpb;
    pc = const_cast<float*>(cpc);//(float*)(cpc);//cpc;
    pd = const_cast<short*>(cpd);//(short*)(cpd);//cpd;
    pe = const_cast<char*>(cpe);//(char*)(cpe);//cpe;
    
    //除了 void* 以外，任何其他类型的指针之间都必须强转
    /*重解释类型转换
     1.任意类型的指针或引用之间的转换
     2.任意类型的指针和整数之间的转换
     */
    //pa = pb;
    pa = reinterpret_cast<int*>(pb);//(int*)(pb);
    pa = reinterpret_cast<int*>(100);
    
    

    return 0;
}
#endif

