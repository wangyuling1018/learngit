//
//  06_copyassignment.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//
#if 0
/*拷贝赋值函数
 1.函数名必须是 operator=
 2.只有一个参数
 3.唯一的参数名必须和类名一样
 */
//拷贝赋值函数用于：对象之间的 赋值
// 如果是赋值,并且"="两边类型完全相同,那么触发operator=函数的调用

#include <iostream>
using namespace std;
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
    //如果类没有提供拷贝赋值函数，编译器将提供一个默认的拷贝赋值函数
    Human& operator=(const Human& that){
        cout << "Human类拷贝赋值构造函数被调用" << endl;
        this->m_age = that.m_age;
        this->m_name = that.m_name;//this->m_name.operator=(that.m_name) --->触发string的拷贝赋值函数
        return *this;//返回Human的自引用，支持串联赋值 //this是指向对象的指针，*this是对象，谁调operator=函数，this指针就指向谁。
    }
    /*
    void operator=(const Human& that){ //自定义的拷贝赋值函数
        //编译器不会在自定义的拷贝赋值函数塞 任何操作
        this->m_age = that.m_age;
        this->m_name = that.m_name;
    }
     */
    
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
    Human h; // 定义h,利用h.Human() --> h维护的内容为(无名,0)
    h.getinfo( );

    cout << "--------------h2创建信息-----------------" << endl;
    Human h2( 22, "张飞" ); // 定义h2,利用h2.Human(22,"张飞") --> h2维护的内容为(张飞,22)
    h2.getinfo( );

    cout << "--------------h3创建信息-----------------" << endl;
    Human h3(h2); //= h2; // 定义h3,利用h3.Human(h2) --> h3维护内容 和 h2维护的内容相同
    h3.getinfo( );
    
    cout << "--------------h4创建信息-----------------" << endl;
    Human h4; // 定义h4,利用h4.Human() --> h4维护内容为(无名,0)
    cout << "h4被赋值前------";
    h4.getinfo( );

    //h4 = h3;//h4.operator=(h3) ---->拷贝赋值函数
    (h4 = h3) = h;//串联赋值
    //h4.operator=(h3)是一个h4的别名，h4.operator=(h3).operator=(h)是h4的别名。
    //如果拷贝赋值函数的返回值是Human，那么h4.operator=(h3)返回的就是一块无名内存，用h给一块无名内存赋值？？？
    cout << "h4被赋值后------";
    h4.getinfo( );
    return 0;
}
#endif

