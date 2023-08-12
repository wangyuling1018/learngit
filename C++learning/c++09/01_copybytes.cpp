//
//  01_copybytes.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0
//拷贝构造函数 和 拷贝赋值函数 在某些特定条件下会有缺陷，所以有了深拷贝
//浅拷贝：对于指针成员变量，只复制地址，不复制地址指向的数据

//浅拷贝
//模拟C++标准库的string类，自己设计一个String类
//默认拷贝构造函数 和 拷贝赋值函数，在特定场景下（类中有指针成员变量）会出现 浅拷贝的缺陷

//尽量避免使用指针型成员变量，使用指针型成员变量要考虑深拷贝，或者将指针成员变量私有，不让用户去用即可。

//拷贝构造是深拷贝，那么拷贝赋值也应该是深拷贝

#include <iostream>
using namespace std;
class String{
public:
    String(/* String* this */const char* psz = "") : m_psz(new char[strlen(psz)+1]){
        //【char* m_psz=new char[strlen(psz)+1];】定义m_psz,初值为指向一块堆内存(动态资源)
        strcpy(m_psz, psz);
    }
    ~String(/* String* this */){
        delete [] this->m_psz;// 释放 m_psz 本身所占内存空间
    }
    char* c_str(){
        return m_psz;
    }
    /*默认的拷贝构造
     String(const String& that){
        【this->m_psz = that->psz;】//只复制了地址，没有复制地址指向的数据 ---->浅拷贝
        //把s1的地址复制给了s2，导致s1中有一个m_psz，s2中也有一个m_psz，有2份m_psz，但保存的是同一块地址。--这不叫完美克隆，是连体婴儿
     }
     */
    String(/* String* this */ const String& that) : m_psz(new char[strlen(that.m_psz)+1]){
        //【this->m_psz = new char[strlen(that.m_psz)+1];】
        strcpy(this->m_psz, that.m_psz);//复制数据，而不是复制地址 ---->深拷贝
    }
    /*默认拷贝赋值函数
    String& operator=(const String& that){
        this->m_psz = that.m_psz;
        return *this;
    }
     */
    String& operator=(/* String* this */ const String& that){
        if(this != &that){//防止自赋值
            delete [] this->m_psz; //释放旧资源 //释放一个字节的堆内存
            this->m_psz = new char[strlen(that.m_psz)+1]; //申请新内存（资源）
            strcpy(this->m_psz,that.m_psz);//复制新数据
        }
        return *this;//返回自引用
    }
    
private:
    char* m_psz;// 指针型成员
    friend ostream& operator<<(ostream& os,const String& that);
};

//操作符函数（规则：打印String类对象）
ostream& operator<<(ostream& os,const String& that){
    os << that.m_psz;
    return os;
}
/*
 String s1;
 cout << s1; //operator<<(cout,s1)
 */

//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    String s1("hello");// 定义s1,利用s1.String("hello")
    //cout << "s1:" << s1.c_str() << " ,s1中的m_psz指针的内存空间地址：" << (void*)s1.c_str() << endl;
    cout << "s1:" << s1 << " ,s1中的m_psz指针的内存空间地址：" << (void*)s1.c_str() << endl; //增加operator<<操作符函数，就可以不用加c_str()函数了

    String s2 = s1;// 定义s2,利用s2.String(s1)-->触发拷贝构造函数
    //cout << "s2:" << s2.c_str() << " ,s2中的m_psz指针的内存空间地址：" << (void*)s2.c_str() << endl;
    cout << "s2:" << s2 << " ,s2中的m_psz指针的内存空间地址：" << (void*)s2.c_str()  << endl;//增加operator<<操作符函数，就可以不用加c_str()函数了

    String s3;// 定义s3,利用s3.String()-->s3维护一个字节的堆内存
    cout << "s3被赋值前:" << s3.c_str() << " ,s3中的m_psz指针的内存空间地址：" << (void*)s3.c_str() << endl;
    s3 = s2;// s3.operator=(s2)-->触发拷贝赋值函数
    //s2 = s2;//自己给自己赋值
    cout << "s3被赋值后:" << s3.c_str() << " ,s3中的m_psz指针的内存空间地址：" << (void*)s3.c_str() << endl;

    return 0;
}//(1) s1.~String() s2.~String()  s3.~String()    (2)释放s1/s2/s3本身所占内存空间
//(1) s1.~String() s2.~String() -----这里析构调用了2次，都是释放同一块内存，double free了

#endif


