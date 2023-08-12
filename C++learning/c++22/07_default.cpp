//
//  07_default.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/2.
//
/*
 类模板扩展-类型参数的缺省值
 1.类模板的类型参数可以带缺省值
    实例化类模板时，如果提供类类型实参，则用所提供的类型实参来实例化类模版，如果没有提供类型实参，则相应的类型形参的缺省类型来实例化模板
 2.如果类模板的某个类型形参带有缺省值，那么它后面的类型形参都必须带有缺省值
 */

#if 0
#include <iostream>
using namespace std;

//template<typename T = int,typename D >class CMath{ //error
template<typename T = int,typename D = short>class CMath{
public:
    void print(){
        cout << "m_t:" << typeid(m_t).name() << " "
             << "m_d:" << typeid(m_d).name() << endl;
    }
private:
    T m_t;
    D m_d;
};

int main(){
    CMath<int,double> m; //int,double
    m.print();
    
    CMath<float> m2;// float,short
    m2.print();
    
    CMath<> m3;//int,short
    m3.print();
    return 0;
}
#endif
