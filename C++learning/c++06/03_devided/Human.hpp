//
//  Human.hpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/18.
//
#if 0

#ifndef Human_hpp
#define Human_hpp

class Human{
public:
    Human(/* Human* this */ int age = 0 ,const char* name = "无名");//函数参数的默认值只能在声明中指定，在定义中指定就会报错
    void getinfo(/* Human* this */ );//声明，声明不意味着分内存，只是告诉编译器
    
private:
    int m_age;//声明，声明不意味着分内存，只是告诉编译器
    char m_name[256];//声明，声明不意味着分内存，只是告诉编译器
};

#endif /* Human_hpp */
#endif

