//
//  04_copycons.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//
#if 0
/*拷贝构造函数
 如果一个类没有定义拷贝构造函数，那么编译器会为其提供一个默认拷贝构造函数
     对其基本类型成员变量进行定义，并赋初值
     对类类型成员变量进行定义，并调用相应类型的拷贝构造函数
 如果自己定义了拷贝构造函数，编译器将不再提供默认拷贝构造函数，这时所有与成员复制相关操作，都必须在自定义拷贝构造函数中自己编写代码完成
 
 若默认拷贝构造函数不能满足要求，则需自己定义
 
 */

//拷贝类构造函数的作用：克隆

//默认拷贝构造函数 比 自己定义的拷贝构造函数效率高，但是有初始化表后，二者效率就是一样的了

//编译器默认提供任何构造函数都是public，自己定义的任何构造函数可以放入private


#include <iostream>
using namespace std;
// 拷贝构造函数
class Human {
public:
//  如果类没有提供 任何构造函数（包括拷贝构造）,编译器将提供一个无参的构造函数
//只要提供了构造函数（包括拷贝构造），编译器就不会提供无参构造函数了
/*  Human( ) {
       【int m_age;】定义m_age,初值为随机数
       【string m_name;】定义m_name,利用m_name.string()
    }*/
    Human( int age=0, const char* name="无名" ) {
        //【int m_age;】定义m_age,初值为随机数
        //【string m_name;】定义m_name,利用m_name.string()
        cout << "Human类的缺省构造函数被调用" << endl;
        m_age = age;
        m_name = name;
    }
//  如果类没有提供拷贝构造函数,编译器将提供一个默认的拷贝构造函数
//只提供了无参构造，编译器还会提供一个默认的拷贝构造
/*  Human( const Human& that ) {
       【int m_age=that.m_age;】定义m_age,并赋初值为that.m_age
       【string m_name(that.m_name);】定义m_name,利用m_name.string(that.m_name)
    }*/
    //Human(Human that){ //不加&也是拷贝构造函数
    Human( const Human& that ) {//不加&也是拷贝构造函数，加&的目的是为了高效传参（引用） //加const限定是万能引用，传参数的时候，既能传非常左值，又能传常左值
        //【int m_age;】定义m_age,初值为随机数
        //【string m_name;】定义m_name,并利用m_name.string()
        cout << "Human类拷贝构造函数被调用" << endl;
        m_age = that.m_age;
        m_name = that.m_name;
    }
    void getinfo( /* Human* this */ ) {
        cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age << endl;
    }
private:
    int m_age; // 基本类型的成员变量
    string m_name; // 类类型的成员变量
};
// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    cout << "--------------h创建信息-----------------" << endl;
    Human h; // 定义h,利用h.Human() --> h维护的内容为(无名,0) //调用缺省构造
    h.getinfo( );

    cout << "--------------h2创建信息-----------------" << endl;
    Human h2( 22, "张飞" ); // 定义h2,利用h2.Human(22,"张飞") --> h2维护的内容为(张飞,22) //调用缺省构造
    h2.getinfo( );

    cout << "--------------h3创建信息-----------------" << endl;
    Human h3(h2); //= h2; // 定义h3,利用h3.Human(h2) --> h3维护内容 和 h2维护的内容相同  //调用拷贝构造
    h3.getinfo( );
    return 0;
}

#endif







