//
//  01_singleoperator2.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0
/*在C语言中，前++ 与 后++ 的区别：
  前++：先加1再使用
  后++：先使用再加1
*/

//在C++中，不管前++还是后++ 都是直接加1（内部实现和C语言并不相同），但C++语言还想让用户感觉和C语言一样


/*后自增减类单目操作符：后++、后--
 1.操作数为非常左值
 2.表达式的结果为右值，且为自增减以前的值
 */

/*
int a=10, b=20;       // 非常左值
const int c=30, d=40; // 常左值

++a;
++c; // error
++5; // error

a++;
c++; // error
5++; // error
*/

//后++
#include <iostream>
using namespace std;
class Human {
public:
    Human( int age=0, const char* name="无名" ) : m_age(age),m_name(name) {
        //【int m_age=age;】定义m_age,初值为age
        //【string m_name(name);】定义m_name,利用m_name.string(name)
    }
    void getinfo( /* Human* this */ ) {
        cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age << endl;
    }
    Human& operator++(/* Human* this */ ){//前++
        this->m_age += 1; //直接加1操作
        return *this;
    }
    Human operator++(/* Human* this */ int){//后++
        Human old = *this; //克隆（备份）一份b原来的数据
        this->m_age += 1; //直接做加1操作
        return old; //返回b原来的数据
    }
   
private:
    int m_age; // 基本类型的成员变量
    string m_name; // 类类型的成员变量
};

// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    Human a(22,"张飞"), b(20,"赵云"); // 非常左值

    //(++a).getinfo( ); // a.operator++()
    
    (/*| |*/b++).getinfo( ); // b.operator++(0),在这里b的值已经改了，只是调getinfo是匿名对象调的，匿名对象拿的是更改之前的数据old
    b.getinfo( ); //这行代码b才调用了getinfo函数
    
    return 0;
}

#endif

