//
//  01_clsobj1.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/18.
//

#if 0
//构造函数
//构造函数：函数名与类名相同，且没有返回值类型，
//在定义对象的同时自动被调用，且仅被调用一次（如果定义10个对象，10个对象都各自调用一次）
//构造函数的作用：定义 对象的各个成员变量（造包子馅），并赋初始值，设置对象的初始状态
//对象的状态：是每个成员变量状态的组合


#include <iostream>
using namespace std;
class Human{
public:
    Human(/* Human* this */ int age = 0 ,const char* name = "无名"){//构造函数
        //在this所指向的内存空中定义m_age（给m_age分配内存空间）初值为随机数
        //在this所指向占的内存空中定义m_name（给m_name分配内存空间）初值为随机数
        cout << "Human类的构造函数被调用" << endl;
        this->m_age = age;
        strcpy(this->m_name,name);
    }
   
//    void setinfo(/* Human* this */ int age = 0, const char* name = "无名"){
//       this->m_age = age;
//       strcpy(this->m_name,name);
//  }
 
    
    void getinfo(/* Human* this */ ){
        cout << "姓名：" << this->m_name << "，年龄：" << this->m_age << endl;
    }
    
private:
    int m_age;
    char m_name[256];
};


//以上代码模块库
//.............................................................................
//以下代码模拟用户
int main(void){
    Human h(22,"张飞");//定义h（给h分配内存空间）,利用h.Human()
            
    //cout << "h的大小：" << sizeof(h) << endl; //260个字节
    //h.setinfo(22,"张飞");
    h.getinfo();
    
    
    return 0;
}
#endif


