//
//  02_hastoinit.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0

/*
 类的常量型和引用型成员变量，必须在初始化表中显示初始化
 类的成员变量按其在类中的声明顺序依次被初始化，而在其初始化表中的顺序无关
 */

#include <iostream>
using namespace std;
// 必须使用初始化表的情况
class Human {
public:
    /*Human( int age=0, const char* name="无名", float score=0.0 )
    : m_age(age),m_name(name),m_score(score), m_len(strlen(m_name)) //如果不考虑初始化顺序，在初始化表中 某个成员变量初始化 不要互相牵扯其他成员变量
     */
    Human( int age=0, const char* name="无名", float score=0.0 )
                                : m_age(age),m_name(name),m_score(score), m_len(strlen(name)) {//初始化表中成员变量初始化最好用形参初始化
        //【int m_len=strlen(name);】
        //【int m_age=age;】定义m_age,初值为age
        //【string m_name(name);】定义m_name,利用m_name.string(name)
        //【const float m_score=score;】定义m_score,初值为score
        cout << "Human类的缺省构造函数被调用" << endl;
    }
    Human( const Human& that )
            : m_age(that.m_age), m_name(that.m_name), m_score(that.m_score), m_len(that.m_len) {
        //【int m_len=that.m_len;】
        //【int m_age=that.m_age;】定义m_age,初值为that.m_age
        //【string m_name(that.m_name);】定义m_name,并利用m_name.string(that.m_name)
        //【const float m_score=that.m_score;】定义m_score,初值为that.m_score
        cout << "Human类拷贝构造函数被调用" << endl;
    }
    void getinfo( /* Human* this */ ) {
        cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age
             << ", 成绩: " << m_score << ", 名字的长度: " << m_len << endl;
    }
private:
    int m_len; // 保存名字字符串的长度 //18-19行代码报错，因为初始化m_len的时候，m_name还没有定义，无法求出m_name的长度
    int m_age;
    string m_name; // 保存名字的字符串
    const float m_score; // 常量型的成员变量
//    int m_len; //18-19行代码--ok，类的成员变量初始化顺序，是按照在类中的声明顺序依次被初始化的
};
// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    cout << "--------------h2创建信息-----------------" << endl;
    Human h2( 22, "张飞", 88.5 );
    h2.getinfo( );

    cout << "--------------h3创建信息-----------------" << endl;
    Human h3(h2); //= h2;
    h3.getinfo( );

    return 0;
}

#endif



