//
//  02_memberfunc.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/3.
//
/*
 模板型成员函数
    类模板的成员函数模板
    例如：   template<class T>class CMath{
            public:
                template<class D>void foo(){....} //成员函数模板
            }；
如果在类外实现：
        template<class T>template<class D>void CMath<T>::foo(){.....}
 */

#if 0
#include <iostream>
using namespace std;
//模板型成员函数
template<typename T>class CMath{
public:
    /*类中声明，并定义
    template<typename D> void foo(){
        cout << "CMath<T>::foo<D>()" << endl;
    }
     */
    template<typename D> void foo();//声明
};

//定义
template<typename T>
template<typename D>
void CMath<T>::foo(){
    cout << "CMath<T>::foo<D>()" << endl;
}

int main(){
    CMath<int> m;
    m.foo<double>();
}
#endif
