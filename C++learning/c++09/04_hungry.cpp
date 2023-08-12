//
//  04_hungry.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//
#if 0
//单例模式：设计一个类，保证用户在使用时只能出现一个对象
/*
 1.一个类仅有一个实例（对象）
 2.将包括，类的拷贝构造函数在内的所有构造函数私有化防止使用者在类的外部创建对象
 3.公有静态成员函数getInstance（）是获取对象实例的唯一渠道
 4.饿汉式：无论用不用，程序启动即创建
 5.懒汉事：用的时候创建，不用了即销毁--引用计数
 */

//饿汉式单例：笨拙的单例实现，（程序一启动，唯一的对象就已经创建了，不管用户用不用这个唯一的对象，这个对象就已经在了，浪费内存）
//懒汉式单例：高级的实现方式，（用户不用不创建唯一对象，用的时候创建即可）

//以下是饿汉式单例的代码
#include <iostream>
using namespace std;
class Singleton{
public://第3步，定义一个桥梁函数用来返回对象，因为没有对象，无法调用普通函数，可以加static通过访问控制限定符调用
    static Singleton& getInstance(){//第4步，将返回值改成引用，不让出现匿名对象
        return s_instance;
    }
private:
    Singleton(){} //第1步，将构造函数私有化，防止用户定义对象，用户一个对象的都不能定义
    Singleton(const Singleton& that){ } //第5步，不让用户克隆，将拷贝构造函数私有化
    static Singleton s_instance;//第2步，我自己定义一个唯一的对象 //声明
};
Singleton Singleton::s_instance;//第3步，定义



//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    //Singleton s1,s2,s3;
    
    //Singleton s1 = /* |匿名对象| */Singleton::getInstance();//生成了3个匿名对象，同时拿着我给的一个对象克隆了3个对象
    //Singleton s2 = /* |匿名对象| */Singleton::getInstance();
    //Singleton s3 = /* |匿名对象| */Singleton::getInstance();
    
    Singleton& s1 = /* |匿名对象| */Singleton::getInstance();//s1 s2 s3都是唯一对象s_instance的别名，地址都一样
    Singleton& s2 = /* |匿名对象| */Singleton::getInstance();
    Singleton& s3 = /* |匿名对象| */Singleton::getInstance();

    cout << "&s1:" << &s1 <<" &s2:" << &s2 << " &s3:" << &s3 << endl;
    return 0;
}
#endif



