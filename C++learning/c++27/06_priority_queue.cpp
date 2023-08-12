//
//  06_priority_queue.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/7.
//

#if 0
#include<iostream>
#include<queue> //queue / priority_queue
using namespace std;
//自定义对象 作为优先队列的参数

class Student{
public:
    Student(string const& name = "",int age = 0) : m_name(name),m_age(age){
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


int main(){
    //priority_queue<Student> pq; //缺省，默认从小到大排序，大的在尾端，优先队列从尾端出
    priority_queue<Student,vector<Student>,greater<Student> > pq; //从大到小
    pq.push(Student("张三",23));
    pq.push(Student("李四",18));
    pq.push(Student("王五",20));
    pq.push(Student("马六",19));
    pq.push(Student("田七",26));
    pq.push(Student("李玲",21));
    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }
    
    return 0;
}
#endif


