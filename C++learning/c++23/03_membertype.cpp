//
//  03_membertype.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/3.
//
/*
 模板型成员类型
    类模板中嵌套的类模板
    例如：
        template<class X>class A{
        public:
            template<class Y>class B{....};//模板型成员类型
        };
 */

#if 0
#include <iostream>
using namespace std;
//模板型成员类型
template<typename X>class A{
public:
    void foo(){//普通成员函数
        cout << "A<X>::foo()" << endl;
    }
    template<typename Y>class B{//模板型成员类型
    public:
        template<typename Z>class C;//模板型成员类型 //类模板C 的声明
        int m_i;
    };
    class CMath{//普通成员类
    public:
        void bar(){
            cout << "A<X>::CMath::bar()" << endl;
        }
    };
};

//类模板C 的定义
template<typename X>
template<typename Y>
template<typename Z>
class A<X>::B<Y>::C{
public:
    template<typename T>void Func(){
        cout << "A<X>::B<Y>::C<Z>::Func<T>()" << endl;
    }
    
};

int main(){
    A<int> a;
    a.foo();
    
    A<int>::CMath m;
    m.bar();
    
    A<double>::B<int> b;
    b.m_i = 10;
    cout << "b.m_i=" << b.m_i << endl;
    
    A<short>::B<double>::C<int> c;
    c.Func<string>();
    
}
#endif
