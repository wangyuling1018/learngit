//
//  05_lazy.cpp
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

//以下是懒汉式单例的代码
#include <iostream>
using namespace std;
class Singleton{
public:
    static Singleton& getInstance(){
        if(s_instance == NULL){//为空，表示用户第一次调用getInstance（）函数 ，不为空，表示再次调用getInstance（）函数
            s_instance = new Singleton; //唯一的对象
            cout << "创建了唯一的对象" << endl;
        }
        ++s_counter;
        return *s_instance;
    }
    void releaseInstance(){
        if(--s_counter == 0){  //最后一次创建对象的s3去销毁，前2次不用销毁对象，保证只销毁一次对象，防止出现double free（同一个对象释放多次）
            delete s_instance;//销毁唯一的对象
            cout << "销毁了唯一的对象" << endl;
            s_instance = NULL;
        }
        
    }
private:
    Singleton(){}
    Singleton(const Singleton& that){ }
    static Singleton* s_instance; //不是唯一的对象，仅仅是一个指针而已
    static int s_counter;//计数功能
};
Singleton* Singleton::s_instance = NULL;//程序刚刚启动的时候，唯一的对象不存在，当用户调用唯一的对象的时候，表示用户要创建唯一的对象了
int Singleton::s_counter = 0; //计数功能 记录调用了多少次getInstance函数


//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    Singleton& s1 = /* |匿名对象| */Singleton::getInstance();//用户第一次调用getInstance（）函数时，创建唯一对象
    Singleton& s2 = /* |匿名对象| */Singleton::getInstance();//以后再次调用getInstance（）函数时，获取第一次创建的对象
    Singleton& s3 = /* |匿名对象| */Singleton::getInstance();
    
    cout << "&s1:" << &s1 <<" &s2:" << &s2 << " &s3:" << &s3 << endl;
    
    s1.releaseInstance();
    s2.releaseInstance();
    s3.releaseInstance();//最后一次调用releaseInstance函数时，将唯一的对象销毁
    //最后一次创建对象的s3去销毁，前2次不用销毁对象，保证只销毁一次对象，防止出现double free（同一个对象被释放多次）
    
    return 0;
}

#endif



