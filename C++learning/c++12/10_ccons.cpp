//
//  10_ccons.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

//子类的构造、析构
//子类构造 研究 怎么造基类子对象的馅
//子类析构 研究 怎么吃掉基类子对象的馅

//不是所有的匿名对象生命周期 都 短暂 。例如基类子对象、new Human

/*子类的构造函数
 子类没有定义构造函数：
 1.编译器为子类提供的默认无参构造函数
 2.定义基类子对象，并调用其基类的无参构造函数，构造该子类对象中的基类子对象
 
 子类定义构造函数但没有在任何初始化表中指明基类部分构造方式：
 1.定义基类子对象，并调用其基类的无参构造函数，构造该子类对象中的基类子对象
 
 子类定义构造函数并在初始化表中指明基类部分构造方式：
 1.定义基类子对象，并调用指明的其基类的构造函数

 子类对象的构造过程：
   构造基类子对象->构造成员变量->执行构造代码
 
 阻断继承：
 1.子类的构造函数无论如何都会调用基类的构造函数，构造子类对象中的基类子对象
 2.如果把基类的构造函数定义为私有，那么该类的子类就永远无法被实例化为对象
 3.在C++中可以用这种方法阻断一个类被扩展。（不想让一个类被继承，就可以将该类的构造函数定义为私有）
 */

/*
 子类没有定义析构函数：
 1.编译器将提供一个默认的析构函数
 2.析构完所有的成员变量以后，会自动调用其基类的析构函数
 
 子类定义析构函数：
 1.子类的析构函数在执行完自身析构代码，并析构完所有的成员变量以后，会自动调用其基类的析构函数
 
 子类对象的析构过程：
   执行析构代码->析构成员变量->析构基类子对象
 */

/*子类的拷贝构造：
 子类没有定义拷贝构造函数：
 1.编译器为子类提供的默认拷贝构造函数
 2.定义基类子对象，并调用其基类的拷贝构造函数，构造该子类对象中的基类子对象
 
 子类定义拷贝构造函数，但没有在任何初始化表中指明基类部分构造方式：
 1.定义基类子对象，并调用其基类的无参构造函数，构造该子类对象中的基类子对象
 
 子类定义了拷贝构造函数，同时在初始化表中指明基类部分以拷贝方式构造：
 1.定义基类子对象，并调用基类的拷贝构造函数，构造该子类对象中的基类子对象
 */

/*子类的拷贝赋值
 子类没有定义拷贝赋值函数：
 1.编译器为子类提供的缺省拷贝赋值函数，会自动调用其基类的拷贝赋值函数，复制该子类对象中的基类子对象
 
 子类定义拷贝赋值函数，但没有在显示式的调用其基类的拷贝赋值函数：
 1.子类对象中的 基类子对象 将 得不到复制
 
 子类定义了拷贝赋值函数，同时显示式调用其基类的拷贝赋值函数：
 1.子类对象中的 基类子对象 将 得到复制
 */

#if 0

#include <iostream>
using namespace std;
//析构函数作用：销毁 对象的各个成员变量 （吃包子馅）
class Human {
public:
//  如果类没有提供任何构造函数,编译器将提供一个无参的构造函数

    Human( int age=0, const char* name="无名" ) : m_age(age),m_name(name) {
        //【int m_age=age;】定义m_age,初值为age
        //【string m_name(name);】定义m_name,利用m_name.string(name)
        cout << "Human类的缺省构造函数被调用" << endl;
    }

    Human( const Human& that ) : m_age(that.m_age), m_name(that.m_name) {
        //【int m_age=that.m_age;】定义m_age,初值为that.m_age
        //【string m_name(that.m_name);】定义m_name,并利用m_name.string(that.m_name)
        cout << "Human类拷贝构造函数被调用" << endl;
    }

    Human& operator=( const Human& that ) {
        // 编译器不会在 自定义的拷贝赋值函数中塞 任何操作
        cout << "Human类的拷贝赋值函数被调用" << endl;
        this->m_age = that.m_age;
        this->m_name = that.m_name;
        return *this;
    }
    
    ~Human( ) {//自定义的析构函数，编译器也会塞吃包子馅的操作
        cout << "Human类的析构函数被调用" << endl;
        // 对于基本类型的成员变量m_age,什么都不做  //吃包子馅操作
        // 对于类类型的成员变量m_name,利用m_name.~string() //吃包子馅操作
        // 释放m_age/m_name本身所占内存空间       //吃包子馅操作
    }
    void getinfo( /* Human* this */ ) {
        cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age;
    }
private:
    int m_age; // 基本类型的成员变量
    string m_name; // 类类型的成员变量
};
class Student : public Human{
public:
    void getinfo(){
        Human::getinfo();
        cout << " ,成绩: " << this->m_score << ", 评语: " << this->m_remark << endl;
    }
    
    // 如果子类没有提供任何构造函数,编译器将提供一个无参的构造函数
    /*
    Student(){
        //【Human();】定义 基类子对象,利用 基类子对象.Human()
        //【float m_score;】定义m_score,初值为随机数
        //【string m_remark;】定义m_remark,利用m_remark.string()
    }*/
    
    /*初始化表中没有指明基类的成员变量的构造方式，那么默认调用的是基类的无参构造
    Student(int age = 0, const char* name = "无名",float score = 0.0, const char* remark = "") : m_score(score),m_remark(remark){
        //【Human();】定义 基类子对象,利用 基类子对象.Human() //默认调用的是基类的缺省构造
        //【float m_score=score;】定义m_score,初值为score
        //【string m_remark(remark);】定义m_remark,利用m_remark.string(remark)
        cout << "Student类的缺省构造函数被调用" << endl;
    }
    */
    
    //初始化表中有指明基类的成员变量的构造方式，那么调用指明的其基类的构造函数
    Student( int age=0, const char* name="无名", float score=0.0, const char* remark="没有" )
                            : Human(age,name), m_score(score), m_remark(remark) {
        //【Human(age,name);】定义 基类子对象,利用 基类子对象.Human(age,name) //调用的是基类的有参构造   //构造基类子对象
        //【float m_score=score;】定义m_score,初值为score //构造成员变量
        //【string m_remark(remark);】定义m_remark,利用m_remark.string(remark)      //构造成员变量
        cout << "Student类的缺省构造函数被调用" << endl;    //执行构造代码
    }
    //  如果子类没有提供析构函数，编译器将提供一个默认的析构函数
    /*  ~Student( ) {
            针对类类型m_remark,利用m_remark.~string()
            针对基类子对象, 利用 基类子对象.~Human()
            释放 m_score/m_remark/基类子对象  本身所占内存空间
        }*/
    ~Student( ) {
        cout << "Student类的析构函数被调用" << endl; //执行析构代码
        // 针对基本类型m_score，什么也不做。
        // 针对类类型m_remark,利用m_remark.~string()  //析构成员变量
        // 针对基类子对象, 利用 基类子对象.~Human()      //析构基类子对象
        // 释放 m_score/m_remark/基类子对象  本身所占内存空间
    }
    //  如果子类没有提供拷贝构造函数，编译器将提供一个默认拷贝构造函数
    /*  Student( const Student& that ) {
           【Human(that);】定义 基类子对象,利用 基类子对象.Human(that)-->基类的拷贝构造函数 //const Student& that ---》const Human& that ，子类类型引用 可以隐士转换为 基类类型引用
           【float m_score=that.m_score;】
           【string m_remark=that.m_remark;】
        }*/
    Student( const Student& that ) : Human(that), m_score(that.m_score), m_remark(that.m_remark) {
        //【Human(that);】定义 基类子对象, 利用 基类子对象.Human(that)-->基类拷贝构造 //const Student& that ---》const Human& that ，子类类型引用 可以隐士转换为 基类类型引用
        //【float m_score=that.m_score;】
        //【string m_remark=that.m_remark;】
        cout << "Student类的拷贝构造函数被调用" << endl;
    }
    //  如果子类没有提供拷贝赋值函数,编译器将提供一个默认的拷贝赋值函数
    /*  Student& operator=( const Student& that ) {
            Human& rh = *this;
            rh = that; // rh.operator=(that)-->基类的拷贝赋值函数
            m_score = that.m_score;
            m_remark = that.m_remark;
            return *this;
        }*/
        Student& operator=( const Student& that ) {
            // ...编译器不会在自己定义的拷贝赋值函数中塞任何操作...
            cout << "Student类的拷贝赋值函数被调用" << endl;
            Human& rh = *this;
            rh = that; // rh.operator=(that)-->基类的拷贝赋值函数
            m_score = that.m_score;
            m_remark = that.m_remark;
            return *this;
        }
    
private:
    float m_score;
    string m_remark;
};

// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    cout << "-------s1的创建信息--------------" << endl;
    //Student s1;
    Student s1(22,"张飞",88.5,"良好");
    s1.getinfo();
    
    cout << "-------s2的创建信息--------------" << endl;
    Student s2(s1);
    s2.getinfo();
    
    cout << "-------s3的创建信息--------------" << endl;
    Student s3;
    cout << "s3被赋值前.....";
    s3.getinfo();
    s3 = s2;//s3.operator=(s2)
    cout << "s3被赋值后.....";
    s3.getinfo();
   
    cout << "-------main will be over--------------" << endl;
    return 0;
}

#endif


