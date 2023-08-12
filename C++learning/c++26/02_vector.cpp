//
//  02_vector.cpp
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

/*
 迭代器的使用
    增操作：insert
    删操作：erase
    改操作
    查操作：find
    排序操作：sort
 */

#if 0
#include<iostream>
#include <vector>
#include <algorithm> //find /sort
using namespace std;
//向量--vector
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

void print(const string& str,vector<Student>& v){
    cout << str << endl;
    /*
    typedef vector<Student>::iterator IT;
    for(IT it = v.begin();it != v.end(); ++it){//用迭代器遍历
        cout << *it << " ";
    }*/
    
    /*
    for(auto const& s : v) //-std=c++11 //11标准支持
        cout << s << " ";
    */
    for(int i = 0; i < v.size(); i++){//用下标遍历
        cout << v[i] << " ";
    }
    cout << "----------------------------------------" << endl;
}

int main(){
    vector<Student> vs;
    vs.reserve(10);
    vs.push_back(Student("张三",22));
    vs.push_back(Student("李四",24));
    vs.push_back(Student("王武",17));
    vs.push_back(Student("马六",35));
    vs.push_back(Student("田七",29));
    print("添加数据：",vs);
    
    vs.insert(++vs.begin(), Student("琉璃",29)); //增 //在第二个位置增加
    print("在迭代器指向位置添加数据：",vs);
    
    vs.erase(--vs.end());                       //删 //删除倒数第一个数据
    print("删除迭代器指向位置的数据：",vs);
    
    typedef vector<Student>::iterator IT;
    IT it = vs.begin();
    *it = Student("张三丰",20);                  //改
    print("修改迭代器指向位置的数据：",vs);
    
    IT fit = find(vs.begin(), vs.end(), Student("李四",25)); //查找
    if(fit != vs.end())
        cout << "找到了" << endl;
    else
        cout << "没有找到" << endl;
    
    //sort(vs.begin(),vs.end());                            //排序  //从小到大排
    sort(vs.begin(),vs.end(),greater<Student>());//从大到小排
    print("排序：",vs);
    
    return 0;
}
#endif
