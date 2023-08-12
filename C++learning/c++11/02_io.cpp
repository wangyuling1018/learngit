//
//  02_io.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0
// cout是ostream的对象
/*
 class ostream {
 public:
      ostream& operator<<(int x) {...} //ostream类中有这样的，各种各样的操作符函数
      ostream& operator<<(const int x) {...} //ostream类中有这样的，各种各样的操作符函数
      ostream& operator<<(double x) {...}//ostream类中有这样的，各种各样的操作符函数
      ostream& operator<<(const double x) {...} //ostream类中有这样的，各种各样的操作符函数
      ostream& operator<<(float x) {...} //ostream类中有这样的，各种各样的操作符函数
      ostream& operator<<(const float x) {...}//ostream类中有这样的，各种各样的操作符函数
      .....
      ostream& operator<<(char x) {...}//ostream类中有这样的，各种各样的操作符函数
      ostream& operator<<(const char* x) {...}//ostream类中有这样的，各种各样的操作符函数
      ostream& operator<<(Human x) {...} // ostream类中肯定没有一个形参为Human类型的operator<<函数，绝对不允许我们添加
 };
 ostream cout;

 // 以上的代码模拟 C++标准库
 // --------------------------------
 // 以下的代码模拟 用户
 int main( ) {
     Human h;
     cout << h; // cout.operator<<(h) --> 实参是Human    或  operator<<(cout,h)

     int a;        double b;    float c;     short d;
     const int ca;       const double cb;     const float cc;     const short cd;
     cout << a;       //  cout.operator<<(a) --> 实参为int //编译器调用的是操作符函数
     cout << b;       //  cout.operator<<(b) --> 实参为double
     cout << c;       //  cout.operator<<(c) --> 实参为float
     cout << d;       //  cout.operator<<(d) --> 实参为short
     cout << ca;       //  cout.operator<<(ca) --> 实参为 const int
     cout << cb;       //  cout.operator<<(cb) --> 实参为const double
     cout << cc;        //  cout.operator<<(cc) --> 实参为const float
     cout << cd;          //  cout.operator<<(cd) --> 实参为const short
     cout << "hello world";        //  cout.operator<<("hello world") --> 实参为 const char*
     cout << '\n';          //  cout.operator<<('\n') --> 实参为char
 }
 */

/*输出操作符：<<
 1.左操作数为非常左值形式输出流（ostream）对象，右操作数为左值或右值
 2.表达式的结果为左操作数本身（而非副本）
 3.左操作数的类型为ostream，若以成员函数形式重载该操作符，就应该将其定义为ostream类的成员，该类
   为标准库提供，无法添加新的成员，因此只能以全局函数形式重载该操作符。
   ostream& operator<<(ostream& os,const RIGHT& right){...}
 */

/*输入操作符：>>
 1.左操作数为非常左值形式的数入流（istream）对象，右操作数为非常左值
 2.表达式的结果为左操作数本身（而非副本）
 3.左操作数的类型为istream，若以成员函数形式重载该操作符，就应该将其定义为istream类的成员，
   该类为标准库提供，无法添加新的成员，因此只能以全局函数形式重载该操作符。
   istream& operator>>(istream& is,RIGHT& right){....}
 */
 


#include <iostream>
using namespace std;
class Human {
public:
    Human( int age=0, const char* name="无名" ) : m_age(age),m_name(name) {
        //【int m_age=age;】定义m_age,初值为age
        //【string m_name(name);】定义m_name,利用m_name.string(name)
    }
    void getinfo( /* Human* this */ ) {//被operator<<函数取代了
        cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age << endl;
    }
    
    
private:
    int m_age; // 基本类型的成员变量
    string m_name; // 类类型的成员变量
    friend ostream& operator<<(ostream& os, const Human& that);
};

ostream& operator<<(ostream& os, const Human& that){
    os << "姓名：" << that.m_name << " ,年龄：" << that.m_age;
    return os;
}
istream& operator>>(istream& is, Human& that){
    is >> that.m_age >> that.m_name;
    return is;
}
    

// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    Human a(22,"张飞"),b(23,"赵云");//非常左值
    const Human c(25,"关羽"),d(34,"马超"); //常左值
    
    cout << a; // operator<<(cout,a)
    cout << b; // operator<<(cout,b)
    cout << Human(45,"黄忠"); //operator<<(cout,Human(45,"黄忠"));

    cin >> a; //operator<<(cin,a)
    cout << a << endl;
    
    
    return 0;
}


#endif

