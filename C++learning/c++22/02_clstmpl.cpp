//
//  02_clstmpl.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/2.
//
/*
 类模板的使用
 1.使用类模板，必须对类模板进行实例化（产生真正的类）
    类模板本身并不代表一个确定的类型（即不能用于定义对象），只能通过类型实参实例化 成真正的类后，才具备类的语义（即可以定义对象）
    例如：CMath<int,double> math;
 2.类模板被实例化时，类模板中的成员函数并没有实例化，成员函数只有在被调用时，才会被实例化（即产生真正的成员函数），注意：成员虚函数除外
 3.某些类型虽然并没有提供类模板 所需要的全部功能，但照样可以实例化类模板，只要不调用那些未提供功能的成员函数即可。
 */
#if 0
#include <iostream>
using namespace std;

class Integer{
public:
    Integer(int i) : m_i(i) {}
    Integer operator+(const Integer& that) const {//增加加法操作符函数
        return this->m_i + that.m_i;
    }
private:
    int m_i;
};

//类模板
template<typename T>
class CMath{
public:
    CMath(T const& t1,T const& t2): m_t1(t1),m_t2(t2){
        
    }
    
    T add(){
        return m_t1 + m_t2;
    }
     
private:
    T m_t1;
    T m_t2;
};


int main(){
    //类模板实例化 是分步实例化
    //类模板被实例化时，类模板中的成员函数并没有实例化
    int nx = 10, ny = 20;
    CMath<int>; //类模板实例化时，编译器只实例化成员变量
    /*编译器生成的代码
    class CMath<int>{
    private:
        int m_t1;
        int m_t2;
    };
     */
    
    //成员函数只有在被调用时，才会被实例化（即产生真正的成员函数）
    CMath<int> m(nx,ny);//使用实例化的创建对象，会调用构造函数，所以实例化出类中就包含了对应的构造函数
    /*编译器生成的代码
    class CMath<int>{
    public:
        CMath<int>(int const& t1,int const& t2) : m_t1(t1),m_t2(t2){}
    private:
        int m_t1;
        int m_t2;
    };
     */
    
    //成员函数只有在被调用时，才会被实例化（即产生真正的成员函数）
    m.add();//调用成员函数add，类中会产生add函数
    /*编译器生成的代码
    class CMath<int>{
    public:
        CMath<int>(int const& t1,int const& t2) : m_t1(t1),m_t2(t2){}
        int add(){
            return m_t1 + m_t2;
        }
    private:
        int m_t1;
        int m_t2;
    };
     */
    
    Integer ix = 100, iy = 200;
    CMath<Integer> m2(ix,iy);
    /*
     class CMath<Integer>{
     public:
        CMath<Integer>(Integer const& t1,Integer const& t2) : m_t1(t1),m_t2(t2){}
        Integer add(){ //Integer类型不支持加法运算， Integer类只中无operator+操作符函数
            return m_t1 + m_t2;
        }
     private:
        Integer m_t1;
        Integer m_t2;
     };
     */
    
    m2.add();//error,不支持add函数的功能，不支持的功能只要不调用就行了，支持谁调用谁
             //OK，Integer类中增加operator+ 加法操作符函数
    
    return 0;
}
#endif
