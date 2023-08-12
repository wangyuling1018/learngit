//
//  04_tmplparam.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/3.
//
/*
 模板型模板参数
    类模板的模板形参也可以是类模板，可以有缺参值
    例如：
        template<class T>class Arrary{....};
        template<template<class D>class C = Arrary>class Sum{
            ........
        };
 */

#if 0
//模板型模板参数
#include <iostream>
using namespace std;
template<typename T>class Array{
public:
    T& operator[](int i){
        return this->m_arr[i];
    }
private:
    T m_arr[10];
};

//加template<typename M>，带尖括号，意思是C是模板,其中typename M 意思是模板类C中只能有一个类型参数
//template<typename D,template<typename M>typename C>class Sum{
template<typename D,template<typename M>typename C=Array>class Sum{ //可以给默认值
public:
    Sum(C<D>& s) : m_s(s){}
    D add(){
        D d = 0;
        for(int i = 0; i < 10; i++)
            d += m_s[i];
        return d;
    }
private:
    C<D> m_s; //模板型成员变量
};



int main(){
    Array<int> a;
    for(int i = 0;i < 10; i++){
        a[i] = i;
    }
    for(int i = 0;i < 10; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    
    //Sum<int,Array> s(a);//调用方式
    Sum<int> s(a);//给了默认值的调用方法
    cout << "求和："<< s.add() << endl;
    
    
}
#endif
