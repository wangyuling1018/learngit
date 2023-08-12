//
//  02_virtualinherit.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0
//虚继承----钻石继承的问题的解决方法
//(1)汇聚子类（Z类）对象中 只包含1个 公共基类（A类）子对象
//（2）公共基类子对象 要被 多个中间子类对象 共享

/*
 虚继承实现原理：
    汇聚子类对象 中的每个 中间子类子对象 都持有一个指针，通过该指针可以获取 中间子类子对象 的首地址 到 公共虚基类子对象 的首地址的 偏移量
 */
#include <iostream>
using namespace std;
#pragma pack(1) //64位操作系统的对齐补齐方式是按照8字节对齐补齐，不想让计算机因为对齐补齐占内存，让计算机按照1字节对齐补齐
class A{//公共基类(人类)
public:
    int m_a;
};
class X: virtual public A{//中间子类（学生类）
public:
    int m_x;
    void setAge(/* X* this */ int age){
        this->m_a = age;// (1)this (2)X中间子类子对象 (3) 指针1  (4) 偏移量1  (5)this+偏移量1  (6)A公共基类子对象首地址 (7)m_a
    }
};

class Y : virtual public A{//中间子类（老师类）
public:
    int m_y;
    int getAge(/* Y* this */ ){
        return this->m_a;//(1)this (2)Y中间子类子对象 (3)指针2  (4)偏移量2  (5)this+偏移量2  (6)A公共基类子对象首地址 (7)m_a
    }
};

class Z : public X ,public Y{//汇聚子类（助教类）
public:
    int m_z;
    void foo(){
        m_a = 100;//中间子类加virtual，实现虚继承
    }
};



//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    Z z;// |X中间子类子对象|Y中间子类子对象|m_z|A公共基类子对象|==>|指针1 m_x|指针2 m_y|m_z|m_a|  //汇聚子类对象中仅有一份m_a
    cout << "汇聚子类对象z的大小：" << sizeof(z) << endl;
    z.m_a = 100;//中间子类加virtual，实现虚继承
    
    z.setAge(25);//公共基类子对象A中的m_a 被 中间子类子对象X、Y 所共享
    cout << z.getAge() << endl;
    
    return 0;
}
#endif

