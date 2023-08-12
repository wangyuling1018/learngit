//
//  06_partial.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/2.
//
/*
 类模板扩展-局部特化
 1.类模板的局部特化，除非必要否则尽量不要特化，因为特化版本过多容易引发编译器匹配歧义
 */

#if 0
#include <iostream>
using namespace std;

template<typename T,typename D>class CMath{
public:
    static void foo(){
        cout << "0:CMath<T,D>::foo()" << endl;
    }
};
//局部特化 形式一
template<typename T>class CMath<T,short>{
public:
    static void foo(){
        cout << "1:CMath<T,short>::foo()" << endl;
    }
};

//局部特化 形式二
template<typename T>class CMath<T,T>{
public:
    static void foo(){
        cout << "3:CMath<T,T>::foo()" << endl;
    }
};

// 局部特化 形式三
template<typename T,typename D>class CMath<T*,D*>{
public:
    static void foo(){
        cout << "3: CMath<T*,D*>::foo()" << endl;
    }
};
int main(){
    CMath<int,double>::foo(); //0
    CMath<int,short>::foo(); //1
    // 特化形式一和特化形式二
//  CMath<short,short>::foo();   // error 匹配歧义    1? 2?
//  CMath<int*,int*>::foo();     // error 匹配歧义    2? 3?
    
    return 0;
}
#endif
