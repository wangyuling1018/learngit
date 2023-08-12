//
//  03_hastodef.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0

#include <iostream>
using namespace std;
// 必须给一个类提供 无参(缺省)构造函数:因为这个类的对象可能作为另外一个类的成员变量
class A {
public:
    /*
    A( int i) { //目前A类无 无参构造函数，只有 有参构造函数
        m_i = i;
    }*/
    A( int i=0) {//给参数指定一个默认值，可以代表 无参构造函数 了
        m_i = i;
    }
    
private:
    int m_i;
};

class Human {
public:
//  如果类没有提供任何构造函数,编译器将提供一个无参的构造函数，但是人为提供了有参构造函数，编译器就不会提供无参构造函数了
/*  Human( ) {
       【int m_age;】定义m_age,初值为随机数
       【string m_name;】定义m_name,利用m_name.string()
       【A m_a;】定义m_a,利用m_a.A() //如果A类没有无参构造函数，则error
    }*/
    Human( int age=0, const char* name="无名" ) {
        //【int m_age;】定义m_age,初值为随机数
        //【string m_name;】定义m_name,利用m_name.string()
        //【A m_a;】定义m_a,利用m_a.A() //如果A类没有无参构造函数，则error
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
    A m_a; // 类类型成员变量
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








