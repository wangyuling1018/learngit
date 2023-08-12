//
//  01_consover.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//
#if 0

//构造函数的重载
/*
 构造函数也可以通过参数表的差别化形成重载
 重载的构造函数，通过构造函数的实参类型进行匹配
 不同的构造函数，表示对象的不同创建方式
 使用缺省参数可以减少构造函数的重载数量
 */


#include <iostream>
using namespace std;
class Human{
public:
    /*
    Human(){
        cout << "1.Human()---->" ;
        m_age = 0;
        m_name = "无名";
    }
    Human(int age){ //互为重载关系
        cout << "2.Human(int)---->" ;
        m_age = age;
        m_name = "无名";
    }
    Human(int age,const char* name){ //互为重载关系
        cout << "3.Human(int,const char*)---->" ;
        m_age = age;
        m_name = name;
    }
     */
    
    Human(int age = 0,const char* name = "无名"){//给参数加缺省（默认）值，可以代替以上3个构造函数，减少重载函数的数量
        cout << "3.Human(int,const char*)---->" ;
        m_age = age;
        m_name = name;
    }
    
    void getinfo(){
        cout << "姓名：" << this->m_name << ",年龄：" << this->m_age << endl;
    }
private:
    int m_age;
    string m_name;
};



//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    Human h;
    h.getinfo();
    
    Human h2(22);
    h2.getinfo();
    
    Human h3(22,"张飞");
    h3.getinfo();
    return 0;
}

#endif

