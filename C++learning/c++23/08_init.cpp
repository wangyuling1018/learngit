//
//  08_init.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/3.
//
/*零值初始化
 问题：
    基本类型不存在缺省构造函数，未被初始化的局部变量都具有一个不确定的值（int a;//值不确定）
    类类型由于存在缺省构造函数，在未被初始化的情况下，可以有一个确定的缺省初始化状态（Integer a;//值确定）
    基于以上两点，就会在模板实现中产生不一致的语法语义
 
 解决方法：
    如果希望模板中，所有类型参数的变量，无论是类类型还是基本类型 都可以以缺省方式获得初始化，就必须对其进行显示的缺省构造 T().
 
 */

#if 0
#include <iostream>
using namespace std;
//零值初始化

class Integer{
public:
    Integer() : m_i(888) {}
private:
    int m_i;
    friend ostream& operator<<(ostream& os ,const Integer& that);
};
ostream& operator<<(ostream& os ,const Integer& that){
    os << that.m_i;
    return os;
}

template<typename T>void Func(){
    //T t; //基本类型int、double实例化后 值不确定 是随机数，类类型Integer实例化后 值确定
    T t = T();//解决方案 取零值：int() / double() / Integer()
    cout << "t=" << t << endl;
}

int main(){
    Func<int>(); // t=1,int 基本类型 值不确定，随机数
    Func<double>(); //t=2.12207e-314,double 基本类型 值不确定，随机数
    Func<Integer>();//t=888,Integer 类类型 值确定，调用了缺省构造
    
}
#endif
