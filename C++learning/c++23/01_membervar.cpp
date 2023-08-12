//
//  01_membervar.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/3.
//

/*
 模板型成员变量
    成员变量，但其类型是由一个类模板实例化的未知类，那么它才可以称之为模板型成员变量
例如： template<class T>class Array{...};
      template<class D>class Sum{
      public:
            Array<D> m_s;   //模板型成员变量
      };
 如果在类外实现：
    template<class T>template<class D> void CMath<T>::foo(){....}
 */

#if 0

//模板型成员变量
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

template<typename D>class Sum{
public:
    Sum(Array<D>& s) : m_s(s){}
    D add(){
        D d = 0;
        for(int i = 0; i < 10; i++)
            d += m_s[i];
        return d;
    }
private:
    Array<D> m_s; //模板型成员变量
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
    
    Sum<int> s(a);
    cout << "求和："<< s.add() << endl;
    
    
}
#endif
