//
//  02_clsobj2.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/18.
//
#if 0

//成员函数的声明和定义分开写，目的是为了分文件
//声明：声明不意味着分内存，只是告诉编译器
//定义：定义xxx就是给xxx分配内存

#include <iostream>
using namespace std;
class Human{
public:
    Human(/* Human* this */ int age = 0 ,const char* name = "无名");//函数参数的默认值只能在声明中指定，在定义中指定就会报错
    void getinfo(/* Human* this */ );//声明，声明不意味着分内存，只是告诉编译器
    
private:
    int m_age;//声明，声明不意味着分内存，只是告诉编译器
    char m_name[256];//声明，声明不意味着分内存，只是告诉编译器
};
Human::Human(/* Human* this */ int age,const char* name){//定义
    //在this所指向的内存空中定义m_age（给m_age分配内存空间）初值为随机数
    //在this所指向占的内存空中定义m_name（给m_name分配内存空间）初值为随机数
    cout << "Human类的构造函数被调用" << endl;
    this->m_age = age;
    strcpy(this->m_name,name);
}
void Human::getinfo(/* Human* this */ ){//定义
    cout << "姓名：" << this->m_name << "，年龄：" << this->m_age << endl;
}

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

