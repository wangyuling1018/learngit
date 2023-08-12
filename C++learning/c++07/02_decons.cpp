//
//  02_decons.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//
#if 0
//实际构造函数没有分类，只是为了方便理解才分类了而已
/*构造函数分类：
 无参（缺省）构造函数：按照无参方式构造
 多参构造函数：按照多参方式构造
 类型转换构造函数：利用不同类型的对象构造
 拷贝构造函数：利用相同类型的对象构造
 */
/*无参构造函数：
 无参构造函数亦称缺省构造函数，但其未必真的没有任何参数，为一个有参构造函数的每个参数都提供一个缺省值（默认值），同样可以达到无参构造函数的效果
 
 如果一个类没有定义任何构造函数，那么编译器会为其提供一个无参构造函数
    对其基本类型的成员变量进行定义，并初始化为随机数
    对类类型的成员变量进行定义，调用相应类型的无参构造
 
 如果一个类定义了构造函数，无论这个构造函数是否带有参数，编译器都不会再为这个类提供无参构造函数
 */

#include <iostream>
using namespace std;
// 无参(缺省)构造函数
class Human {
public:
//  如果类没有提供任何构造函数,编译器将提供一个无参的构造函数
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
    Human h; // 定义h,利用h.Human() --> h维护的内容为(无名,0)
    h.getinfo( );

    Human h2( 22, "张飞" ); // 定义h2,利用h2.Human(22,"张飞") --> h2维护的内容为(张飞,22)
    h2.getinfo( );
    return 0;
}

#endif






