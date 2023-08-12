//
//  05_string.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//

//移动语义：C++11标准提出的 凸显的执行效率更高
//一哥们要挂了，这哥们把他的资产给我了---体现的就是移动语义
/*
 移动语义
 方法：资源的转移 代替 资源的重建
 作用：保证功能正确的情况下，做到性能提升
 */

#if 0
// 模拟C++标准库的string类，自己设计一个String类
#include <iostream>
#include <cstring>
using namespace std;
// 默认的拷贝构造 和 拷贝赋值 函数，在特定场景下(类中有指针成员变量) 会出现 浅拷贝的缺陷
class String {
public:
    String( const char* psz="" ) : m_psz(new char[strlen(psz)+1]) {
        //【char* m_psz=new char[strlen(psz)+1];】定义m_psz,初值为指向一块堆内存(动态资源)
        strcpy( m_psz, psz );
    }
    ~String( /* String* this */ ) {
        delete[] this->m_psz;
        // 释放 m_psz 本身所占内存空间
    }
    char* c_str() {
        return m_psz;
    }
    /* 默认的拷贝构造
    String( const String& that ) {
       【char* m_psz=that.m_psz;】只复制了地址,没有复制地址指向的数据-->浅拷贝
    }
    */
    // 深拷贝构造函数(体现的为资源的重建)
    String( /* String* this */ const String& that ) : m_psz(new char[strlen(that.m_psz)+1]) {
        //【char* m_psz=new char[strlen(that.m_psz)+1];】
        strcpy( m_psz, that.m_psz ); // 复制数据，而不复制地址-->深拷贝
        cout << "String类的深拷贝构造函数被调用" << endl;
    }
    // 转移构造函数(体现的为资源的转移)
    String( /* String* this */ String&& that ) : m_psz(that.m_psz) {
        //【char* m_psz = that.m_psz;】只复制了地址,没有复制地址指向的数据
        that.m_psz = NULL;
        cout << "String类的转移构造函数被调用" << endl;
    }
    /* 默认拷贝赋值函数
    String& operator=( const String& that ) {
        this->m_psz = that.m_psz; // 只复制了地址，没有复制地址指向的数据-->浅拷贝
        return *this;
    }
    */
    // 深拷贝赋值函数(体现的为资源的重建)
    String& operator=( /* String* this */ const String& that ) {
        cout << "String类深拷贝赋值函数被调用" << endl;
        if( this != &that ) { // 防止自赋值
            delete[] this->m_psz; // 释放旧资源
            this->m_psz = new char[strlen(that.m_psz)+1]; // 申请新内存(资源)
            strcpy( this->m_psz, that.m_psz ); // 复制新数据
        }
        return *this; // 返回自引用
    }
    // 转移赋值函数(体现的为资源的转移)
    String& operator=( /* String* this */ String&& that ) {
        cout << "String类转移赋值函数被调用" << endl;
        delete[] this->m_psz;
        this->m_psz = that.m_psz; //只复制地址
        that.m_psz = NULL;
        return *this;
    }
private:
    char* m_psz; // 指针型成员
    friend ostream& operator<<(ostream& os, const String& that ) ;
};
ostream& operator<<(ostream& os, const String& that ) {
    os << that.m_psz;
    return os;
}
// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    String a("hello");
    cout << "--------------------1--------------------" << endl;
    String b = a; // 定义b,利用b.String(a) --> 触发String类的深拷贝构造函数函数 //a是左值，不会死亡，下面代码可能还会用到a，应该调用深拷贝构造函数
    cout << "--------------------2--------------------" << endl;
    String c = String("world"); // 定义c,利用c.String( String("world") ); --> 触发String类的转移构造函数  //String("world")是右值，即将死亡，应该调用转移构造函数 //右值 更匹配 右值引用
    
    cout << "--------------------3--------------------" << endl;
    String d;
    d = a; // d.operator=(a) --> 触发的为String类的深拷贝赋值函数  //a是左值，不会死亡，下面代码可能还会用到a，应该调用深拷贝赋值函数

    cout << "--------------------4--------------------" << endl;
    d = String("hello world"); // d.operator=( String("hello world") ) --> 触发的为转移赋值函数  //String("world")是右值，即将死亡，应该调用转移赋值函数 //右值 更匹配 右值引用

    return 0;
}

#endif

//加-std=c++11，让编译器按照11标准编译
//2 没有打印，是被编译器优化了，可以加上-fno-elide-constructors，再次编译
//编译：g++ 05_string.cpp -std=c++11 -fno-elide-constructors

