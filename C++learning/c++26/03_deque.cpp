//
//  03_deque.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/7.
//
/*
 线型容器：
 向量：尾端高效增删     push_back/pop_back
      可以使用下标 -- 随机迭代器
 双端队列：首尾两端都可以实现高效增删     push_front/pop_front       push_back/pop_back
         可以使用下标   -- 随机迭代器
 列表：  任意位置都可以实现高效增删     push_front/pop_front       push_back/pop_back
        不可以使用下标  -- 没有随机迭代器
 */

//双端队列，增加push_front/pop_front,没有reserve()/capacity()
//vector、deque适合随机访问，不适合增删。

/*
 双端队列和向量的差别
    和向量的差别就是首尾两端同样都是开放的，因此他同时提供类首尾两端增删元素的接口
    没有提供设置/获取容量的函数，设置和获取容量的大小函数存在
 */

#if 0
#include<iostream>
#include <deque>
#include <algorithm> //find /sort
using namespace std;
//双端队列--deque

class Student{
public:
    Student(string const& name = "",int age = 0) : m_name(name),m_age(age){
    }
    bool operator==(const Student& that)const{
        return m_name == that.m_name  && m_age == that.m_age;
    }
    bool operator<(const Student& that)const{
        return m_age < that.m_age;
    }
    bool operator>(const Student& that)const{
        return m_age > that.m_age;
    }
private:
    string m_name;
    int m_age;
    friend ostream& operator<<(ostream& os,const Student& stu);
};

ostream& operator<<(ostream& os,const Student& stu){
    return os << stu.m_name << "," << stu.m_age;
}

void print(const string& str,deque<Student>& d){
    cout << str << endl;
    /*
    typedef deque<Student>::iterator IT;
    for(IT it = d.begin();it != d.end(); ++it){//用迭代器遍历
        cout << *it << " ";
    }*/
    for(auto const& s : d) //-std=c++11 //11标准支持
        cout << s << " ";
     /*
    for(int i = 0; i < d.size(); i++){//用下标遍历(支持随机迭代器)
        cout << d[i] << " ";
    }*/
    cout << endl << "----------------------------------------" << endl;
}

int main(){
    deque<Student> ds;
    //ds.reserve(10);
    ds.push_front(Student("张三",22));
    ds.push_front(Student("李四",24));
    ds.push_front(Student("王武",17));
    ds.push_back(Student("马六",35));
    ds.push_back(Student("田七",29));
    print("添加数据：",ds);
    
    ds.insert(++ds.begin(), Student("琉璃",29)); //增 //在第二个位置增加
    print("在迭代器指向位置添加数据：",ds);
    
    ds.erase(--ds.end());                       //删 //删除倒数第一个数据
    print("删除迭代器指向位置的数据：",ds);
    
    typedef deque<Student>::iterator IT;
    IT it = ds.begin();
    *it = Student("张三丰",20);                  //改
    print("修改迭代器指向位置的数据：",ds);
    
    IT fit = find(ds.begin(), ds.end(), Student("李四",25)); //查找
    if(fit != ds.end())
        cout << "找到了" << endl;
    else
        cout << "没有找到" << endl;
    
    //sort(vs.begin(),vs.end());                            //排序  //从小到大排
    sort(ds.begin(),ds.end(),greater<Student>());//从大到小排
    print("排序：",ds);
    
    //cout << "容量：" << ds.capacity() << endl;
    
    return 0;
}
#endif
