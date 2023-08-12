//
//  05_special.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/2.
//
/*
 类模板扩展-全局特化
 1.全类特化：特化一个类模板可以特化该类模板所有的成员函数，相当于重新写了一个针对某种特定数据类型的具体类
        声明形式：template<>class 类模版名<类型参数1,....>{....};
        例如： template<>class CMath<char*>{....};
 
 2.成员特化：类模板特化除了可以对整个类进行特化外，可以只针对某部分成员函数进行特化
        声明形式：template<>
                返回值类型 类模板名<类型参数1,...>::成员函数名(调用参数1,...){...}
        例如： template<>char* const CMath<char* const>::sum(...){...}
 */

//模板技术 就是针对 类型的泛化，写出针对类型通用的代码
//范型 意思是针对类型的泛化
//有些情况针对类型是不能通用的，如果这种类型不能用模板技术，但是非要用，就要做特殊化处理，这种情况叫特化
//泛化 是做 类型兼容。
//特化 是针对不兼容的类型，做特殊化处理。

//全局特化：特化类型参数表中的所有类型形参。
//全类特化：针对某种特定数据类型，写一个类，这样编译器就不会生产类了。

//如果类模板中有8个函数，其中有7个函数需要做特化处理，就没必要用类模板，直接写8个类
//如果类模板中有8个函数，只有1个函数需要做特化处理，可以用类模板。

//一般工作中很少用到全局特化

#if 0
#include <iostream>
using namespace std;

//类模板
template<typename T>
class CMath{
public:
    CMath(T const& t1,T const& t2): m_t1(t1),m_t2(t2){}
    T add(){
        return m_t1 + m_t2;
    }
     
private:
    T m_t1;
    T m_t2;
};
/*
//全类特化
template<>class CMath<char* const>{
public:
    CMath(char* const& t1,char* const& t2): m_t1(t1),m_t2(t2){}
    char* const add(){
        return strcat(m_t1,m_t2);
    }
private:
    char* const m_t1;
    char* const m_t2;
};
*/

//成员特化
template<> char* const CMath<char* const>::add(){
    return strcat(m_t1,m_t2);
}


int main(){
    int nx = 10, ny = 20;
    CMath<int> m1(nx,ny);
    cout << m1.add() << endl;
    double dx = 1.23, dy = 4.56;
    CMath<double> m2(dx,dy);
    cout << m2.add() << endl;
    string sx = "Hello," , sy = "world!";
    CMath<string> m3(sx,sy);
    cout << m3.add() << endl;
    char cx[256] = "hello", cy[256] = "world";
    CMath<char* const>  m4(cx,cy); //数组名是具有常属性的指针
    cout << m4.add() << endl;
    return 0;
}
#endif
