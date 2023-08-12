//
//  01_map.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/7.
//

//map适合检索，不适合修改。
/*映射
 定义形式：
    map<键类型，值类型> 映射对象；
 底层实现：
    template<typename Key,typename T,
            typename Compare = less<Key>, //缺省采用递增排序
            typename Alloc = alloc>
    class map{
    };
 头文件：
    map
 逻辑模型：键值对
    template<typename Key,typename T>
    struct pair{
        Key first;
        T second;
        pair(): first(Key()),second(T()){}
        pair(const Key& a, const T& b): first(a),second(b){}
    };
    主要用于信息检索，性能可以达到对数级（O(logN)),类似二分法
    默认用less<key>对元素排序，键不允许有重复数据
物理模型：
    红黑树（平衡有序二叉树）//所谓平衡是高度相差为1
映射的特点：
    1.键唯一
    2.键只读
    3.迭代过程实际上是关于键的中序遍历（L D R）,缺省键的升序
    4.支持“下标”运算，用键作为下标，得到对应的值的引用，如果所给出的键不存在，增加一个节点，返回其值的引用
    5.检索性能好，构建和修改性能较差，适用于结构稳定，但是需要频繁检索的操作

 创建map容器：
    1.创建空的map容器
        map<string,int> m1;
    2.使用初始化列表指定map的初始值
        map<string,int> m2{{"zhangsnag",22},{"lisi",29}};
    3.使用现有的容器或容器的一段元素创建map
        map<string,int> m3{m2};
        map<string,int> m4{++m2.begin(),--m2.end()};
 
 map元素的插入：
    插入一个pair<Key,T>对象
        insert(pair<FIRST,SECOND>(键，值))
    使用make_pair<Key,T>()函数模板插入一个对
        insert(make_pair(键，值))
    初始化列表作为参数
        insert({键，值},{键，值},{键，值},{键，值}......)

 访问map元素：
    使用迭代器访问元素
        begin()/end(),cbegin()/cend(),rbegin()/rend(),crbegin()/crend()
    使用键获取值
        [key]:key存在时返回关联值的引用，不存在时添加新元素
        at(key):key存在时返回关联的对象，不存在时抛出异常out_of_range
 
 map元素的删除：
    earse(key)
        移除键和参数匹配的元素，返回所移除元素的个数
    earse(iterator)
        移除参数迭代器指向的元素，返回迭代器指向 被删除元素的下一个位置。参数必须是容器中的有效迭代器，不能是终止迭代器，如果迭代器参数指向的是容器的最后一个元素，则返回终止迭代器。
 
 map元素查找：
    find(key)
        返回一个元素的迭代器，这个元素的键和参数匹配
        如果没有和参数匹配的元素，find()函数会返回容器的终止迭代器，因此在使用这个迭代器之前，必须先对它进行检查。
 
 */

#if 0
#include<iostream>
#include<map>
#include<stdexcept>
using namespace std;
//映射-map
class Student{
public:
    Student(const string& name=" ",const int& score = 0) : m_name(name),m_score(score){
        
    }
private:
    string m_name;
    int m_score;
    friend ostream& operator<<(ostream& os,const Student& that);
};
ostream& operator<<(ostream& os,const Student& stu){
    return os << stu.m_name << ":" << stu.m_score;
}

void print(map<string,Student>& m){
    typedef map<string,Student>::iterator IT;
    for(IT it = m.begin(); it != m.end(); ++it)
        cout << (*it).first << ":" <<(*it).second << endl;
    cout << "-------------------------------" << endl;
}


int main(){
    //初始化
    //map<string,Student> m; //初始化空的映射
    map<string,Student> m{//-std=c++11，11标准支持
        {"1008",{"李四",80}},{"1003",{"王倩",90}},{"2001",{"宋立",66}}
        
    };
    //插入
    m.insert(pair<string,Student>("1005",Student("张三丰",35)));
    m.insert(make_pair("1002", Student("李小萌",15)));
    m.insert({//-std=c++11，11标准支持
        {"1009",{"李四1",80}},{"1001",{"王倩1",90}}
        
    }); //当键存在---忽略，键不存在----添加
    m["1001" ] = Student("姚玲",86);//当键不存在---添加，当键存在---修改
    print(m);
    
    //获取值
    cout << "使用迭代器获取数据：" << endl;
    typedef map<string,Student>::iterator IT;
    IT it = m.begin();
    cout << it->first << ":" << it->second << endl;
    
    cout << "使用键获取值：" << endl;
    Student s = m["1011"];//键不存在---添加，键存在---获取值 //不建议用这种方式获取值
    cout << "1011:" << s << endl;
    
    try{
        Student ss = m.at("2023");//用at获取数据 更靠谱，推荐使用这个
        cout << "2023:" << ss << endl;
    }
    catch(out_of_range& e){
        cerr << e.what() << endl;//e.what()保存的错误信息
        cout << "没有对应的数据" << endl;
    }
    
    //删除
    if(m.erase("1003"))//根据键删除
        cout << "1003被删除" << endl;
    else
        cout << "1003不存在" << endl;
    print(m);
    
    it = m.erase(++m.begin());//根据迭代器（位置）删除 //删除第二个位置
    if(it == m.end())
        cout << "最后一个元素被删除" << endl;
    else//删除成功
        cout << "位于" << it->first << "前面的元素被删除" << endl;
    print(m);
    
    //查找
    IT fit = m.find("1009");
    if(fit == m.end())
        cout << "1009没有找到" << endl;
    else
        cout << "找到了:" << fit->second << endl;

    return 0;
}
#endif
