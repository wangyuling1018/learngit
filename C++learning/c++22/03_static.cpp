//
//  03_static.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/2.
//
/*
 类模板的静态成员
 1.类模板中的静态成员即不是每个对象拥有一份
 2.也不是类模板拥有一份
 3.而应该是由类模板实例化出的每一个真正的类各有一份
 4.且为该实例化类定义的所有对象共享
 */

/*
                     /   对象1
            实例化类1 ——  对象2
         /  {静态成员} \   对象3
        /
       /              /    对象1
 类模板  ——  实例化类2  ——   对象2
       \   {静态成员}  \    对象3
        \
         \            /    对象1
            实例化类3  ——   对象2
            {静态成员} \    对象3

 */

//实例化类有多少份，静态成员就有有多少份

#if 0
#include <iostream>
using namespace std;
template<typename T>class A{
public:
    static void print(){
        cout << "&m_i:" << &m_i << " ,&m_t:" << &m_t << endl;
    }
    static int m_i;
    static T m_t;

};
template<typename T>int A<T>::m_i; //=0；
template<typename T>T A<T>::m_t; //=?; //值不确定
int main(){
    A<int> x,y,z;
    x.print();
    y.print();
    z.print();
    A<int>::print();
    
    cout << "------------------------" << endl;
    A<double> m,n,p;
    m.print();
    n.print();
    p.print();
    A<double>::print();
    
    return 0;
}
#endif
