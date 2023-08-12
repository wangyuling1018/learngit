//
//  01_clstmpl.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/2.
//
/*
 类模板的声明
 形式：template<class 类型形参1，...> class 类模板名{...};
    例如：
        template<class A,class B>class CMath{
        public:
                A m_a;
                B func() {...};
        };
 
 如果在类模板外实现成员函数
 template<class 类型形参1,....>
 返回值类型 类模板名<类型形参1,...>::函数名(调用形参1,...){函数体实现；}
 例如： template<class A,class B> B CMath<A,B>::func(){
            .....;
        }
        //template<class A,class B> 是模板的固定前缀
        // CMath<A,B> 是类名限定符
 */

//类模板的成员函数，之前讲的各种成员函数都支持，只是比之前讲的更丰富。

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

//类模板
template<typename T>
class CMath{
public:
    CMath(T const& t1,T const& t2): m_t1(t1),m_t2(t2){
        
    }
    //T add();//类模板内部声明
    
    T add(){
        return m_t1 + m_t2;
    }
     
private:
    T m_t1;
    T m_t2;
};
/*
//类模板外实现成员函数
template<typename T> //类模板前缀
T CMath<T>::add(){ //CMath<T> 是类名限定：类模板名<类型参数表>
    return m_t1 + m_t2;
}
*/


int main(){
    /*
    //类模板的实例化，产生真正的类
    CMath<int>;   //编译器根据这句代码，生成class CMath<int>{....}    //编译器实例化出的类
    CMath<double>;//编译器根据这句代码，生成class CMath<double>{....}  //编译器实例化出的类
    CMath<string>;//编译器根据这句代码，生成class CMath<string>{....}  //编译器实例化出的类
    */
    
    //使用实例化类去创建对象，进而去调用
    int nx = 10, ny = 20;
    CMath<int> m1(nx,ny);
    cout << m1.add() << endl;
    double dx = 1.23, dy = 4.56;
    CMath<double> m2(dx,dy);
    cout << m2.add() << endl;
    string sx = "Hello," , sy = "world!";
    CMath<string> m3(sx,sy);
    cout << m3.add() << endl;
    
    return 0;
}
#endif
