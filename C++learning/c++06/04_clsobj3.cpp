//
//  04_clsobj3.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/18.
//
#if 0

//对象的定义与销毁

//C++中11种定义对象的方法
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
    Human(32,"machao").getinfo();//定义匿名Human类对象，利用匿名Human类对象.Human(32,"machao")
    //匿名对象的生命周期 是 过了分号就死了，匿名对象也叫匿名内存
    
    Human h(22,"张飞");//定义h（给h分配内存空间）,利用h.Human()
    h.getinfo();
    
    Human h2;//对象的定义，定义h2，利用h2.Human()
    //Human h2();//error,如果加了（）不对，会报错Human h2()编译器会理解为函数的声明，切记不要加括号
    h2.getinfo();
    
    Human h3[3];//定义3个Human类对象，并分别利用这3个Human类对象.Human()
    for(int i = 0; i < 3; i++){
        h3[i].getinfo();
    }
    
    Human h4[3] = { Human(22,"张飞"),Human(20,"zhaoyun"),Human(25,"guanyu")};
    for(int i = 0; i < 3; i++){
        h4[i].getinfo();
    }
    
    Human h5[] = { Human(22,"张飞"),Human(20,"zhaoyun"),Human(25,"guanyu"),Human(45,"huanghzong")};
    for(int i = 0; i < 4; i++){
        h5[i].getinfo();
    }
    
    Human* ph = new Human;//定义 Human类堆对象，利用 Human类堆对象.Human()
    (*ph).getinfo();
    delete ph;
    ph = NULL;
    
    Human* ph2 = new Human();//定义 Human类堆对象，利用 Human类堆对象.Human()
    (*ph2).getinfo();
    delete ph2;
    ph2 = NULL;
    
    Human* ph3 = new Human(18,"wusong");//定义 Human类堆对象，利用 Human类堆对象.Human()
    (*ph3).getinfo();
    delete ph3;
    ph3 = NULL;
    
    Human* ph4 = new Human[3];//定义 Human类堆对象，利用 Human类堆对象.Human()
    for(int i = 0; i < 3; i++){
        (*ph4).getinfo();
    }
    delete[] ph4;
    ph4 = NULL;
    
    Human* ph5 = new Human[3]{ Human(22,"张飞"),Human(20,"zhaoyun"),Human(25,"guanyu")};//定义 Human类堆对象，利用 Human类堆对象.Human()
    for(int i = 0; i < 3; i++){
        (*ph5).getinfo();
    }
    delete[] ph5;
    ph5 = NULL;
    
    return 0;
}


#endif

