//
//  01_type.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/17.
//

//复合类型：结构体、联合体、枚举
//C++复合类型 与 C语言复合类型的差别在于：c语言允许干的事情，c++仍然可以干，c语言不允许干的事情，c++也可以干了。
//C++是更大更大的C语言，c语言不允许干的事情，c++也可以干了。

//c++复合类型 与 c的复合类型 的差别,以及bool类型


#if 0
#include <iostream>
#include <cstring>
using namespace std;

void TestStruct(){
    struct Student{
        int m_age;//Student结构体的成员变量
        char m_name[256];//Student结构体的成员变量
        void  getinfo(){//Student结构体的成员函数,可以直接访问成员变量，不需要“->"或“.”
            cout << "姓名：" << m_name << " , 年龄：" << m_age << endl;
        }
    };
    
    /*struct*/ Student s;//C++中struct关键字可以省略
    s.getinfo();
    s.m_age = 22;
    strcpy(s.m_name, "张飞");
   
    cout << "姓名：" << s.m_name << " , 年龄：" << s.m_age << endl;

}
void TestUnion(){
    //union A{
    union { //匿名联合体，主要体现联合体中各个成员在内存中的排布方式（共用同一块内存空间）
        int i;
        char c[4];
    };
   // /* union */ A a;//C++中union关键字可以省略
    
    i = 0x12345678;//小端字节序 低数位 占 低地址。（高位）0x12345678（低位），c[0]低地址，c[3]高地址。
    cout << hex << (int)c[0] << " " << (int)c[1] << " " << (int)c[2] << " " << (int)c[3] << endl;
    //hex：告诉编译器按照16进制打印
}

void TestEnum(){
    enum color { red, green ,blue};
   // /* enum */ Color c = 0;//c语言可以，c++不可以，认为有风险，c++对类型的检查比c语言要严格。
    //c++崇尚更严谨，c语言崇尚自由。
    color c = red;//C++写法
    cout << "c=" << c << endl;
}

void TestBool(){
    //任何基本类型的数据 都可以 隐式转换（编译器帮我们转换）为布尔类型
    //任何复合类型的数据，如何转换为布尔类型？（第17次课会讲到）
    bool a ="fds";//"";//0.00000000001; //123;//true;   //"fds"将字符串的地址赋值给a 。“”空字符串也是将空字符串的地址赋值给a
    bool b = NULL;//0.0000000000;//0;//false;
    //""空串并非真的空，字符串以"\0"字符结尾的，空串里面包含一个字符“\0“，用NULL表示字符串为空。
    cout << "a=" << a << ",b="<< b << endl;
}

int main(void){
    TestStruct();
    TestUnion();
    TestEnum();
    TestBool();
    return 0;
}
#endif

