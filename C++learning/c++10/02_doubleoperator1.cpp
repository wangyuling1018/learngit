//
//  02_doubleoperator1.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0

/*运算类双目操作符：+、-、*、/等
 1.左右操作数均可以为非常左值、常左值或右值
 2.表达式的结果为右值
 */

//右值：无名内存，表达式的值存在无名内存中

/*
 int a = 10, b = 20;  //非常左值
 const int c = 20, d = 30; //常左值
 |30 |a + b; //ok，a+b表达式的结果30 存放在无名内存中，结果为右值
 a + 5; //ok
 c + b; //ok
 5 + b; //ok
 
 */

/*友元
 1.可以通过friend关键字，把一个全局函数、另一个类的成员函数或者另一个类的整体，声明为授权类的友元
 2.友元拥有访问授权类任何非公有成员的特权
 3.友元声明可以出现在授权类的公有、私有或者保护等任何区域，且不受访问控制限定符的约束
 4.友元不是成员，其作用域并不隶属于授权类，也不拥有授权类类型的this指针
 */

//全局函数不会因为加了friend，全局函数就会变为类的成员函数。全局函数永远是全局函数，朋友就是朋友

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
    /*
    //定义成员操作符函数（函数内部定义运算规则）
    Human operator+( /* Human* this */ const Human& r)const{//第一个const表示右操作数均可以为非常左值、常左值或右值，//第二个const表示左操作数均可以为非常左值、常左值或右值 //表达式的结果为右值，表示返回值不能是引用,返回值只能放在无名内存中
        return Human(this->m_age + r.m_age,(this->m_name + "+" + r.m_name).c_str());
    }
    */
protected:
    //friend Human operator+(const Human& r,const Human& l);//友元声明可以出现在授权类的公有、私有或保护等任何区域，且不受访问控制符的约束
private:
    int m_age; // 基本类型的成员变量
    string m_name; // 类类型的成员变量
    friend Human operator+(const Human& r,const Human& l);//友元声明 //声明这个函数是Human类的朋友，那么这个朋友就可以访问Human类的非公有成员了
};

//定义全局操作符函数
Human operator+(const Human& r,const Human& l){//第一个const表示右操作数均可以为非常左值、常左值或右值，//第二个const表示左操作数均可以为非常左值、常左值或右值 //表达式的结果为右值，表示返回值不能是引用,返回值只能放在无名内存中
    return Human(r.m_age + l.m_age,(r.m_name + "+" + l.m_name).c_str());
}

//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    Human a(22,"张飞"),b(23,"赵云");
    const Human c(25,"关羽"),d(34,"马超");
    Human res = a + b; //a.operater+(b) 或 operator+(a,b) //先找成员操作符函数，没有就找全局操作符函数
    res.getinfo();
    
    res = c + d; //c.operater+(d) 或 operator+(c,d)
    res.getinfo();
    
    res = Human(45,"黄忠") + Human(54,"刘备");// Human(45,"黄忠").operator+( Human(35,"刘备") ) 或
    // operator+( Human(45,"黄忠"), Human(35,"刘备") )
    res.getinfo();
    
    return 0;
}

#endif

