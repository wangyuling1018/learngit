//
//  05_unordered_map.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/7.
//

//无序映射检索性能略低于映射，添加删除性能优于映射

/*
哈希定义：
    哈希是给定范围的基本类型的数据项，或者类似string这样的对象，生成整数值的过程
    哈希产生的值叫做哈希值 或者 哈希码，通常在容器中 用来确定表中对象的位置
    理想情况下，每个对象产生的哈希值是唯一的，但实际是可能产生重复的。重复的哈希值称为哈希碰撞。
 
哈希函数：
    hash<key>
        template<typename Key>struct has{};
    成员函数
        size_t  operator()(Key k){}
 */

/*无序映射
 定义形式：
    unordered_map<键的类型，值的类型,[哈希器类型],[判等器类型]> 对象；
 底层实现：
    template<class Key,
            class T,
            class HashFcn = hash<Key>,
            class EqualKey = equal_to(Key),
            class Alloc = alloc()>
    class unordered_map{
       .....
    };
            
 
 */

#if 0
#include<iostream>
#include<unordered_map>
using namespace std;
//无序容器---无序映射
class Name{
public:
    Name(const string& xing,const string& ming) : m_xing(xing),m_ming(ming) {}
    bool operator==(const Name& that)const{ //一种是在类中实现等于运算
        return m_xing == that.m_xing && m_ming == that.m_ming;
    }
    
    
private:
    string m_xing;
    string m_ming;
    friend ostream& operator<<(ostream& os,Name const& name);
    friend class NameHash;
    friend class NameEqual;
};
ostream& operator<<(ostream& os,Name const& name){
    return os << name.m_xing << name.m_ming;
}
//哈希类
class NameHash{
public:
    size_t operator()(const Name& name)const{
        hash<string> hs;
        return hs(name.m_xing)^(hs(name.m_ming)<<1);//ming的哈希值 左移，然后做异或运算
    }
};

//判等类
class NameEqual{
public:
    bool operator()(Name const& a,const Name& b)const{
        return a.m_xing == b.m_xing && a.m_ming == b.m_ming;
    }
};

int main(){
    /*
     //哈希函数支持基本类型
    unordered_map<string, int> um{
        {"zhangsan",39},{"lisi",98},{"wangwu",67},{"maliu",79},{"tianqi",55}
    };
    cout << um["lisi"] << endl;
    
    hash<string> hs;
    for(auto const& p : um)
        cout << p.first << '(' << hs(p.first) << ')' << ":" << p.second << endl;//hs(p.first) 哈希值，按照哈希值的顺序排序的
     */
    
    
    //哈希函数不支持 自定义类型，需要自己加hash类
    //unordered_map<Name,int,NameHash> um;//初始化为空的时候，需要加 hash类
    
    //加数据的时候，需要加 判等类，有2种实现方式，一种是在类中实现等于运算，一种是增加判等类
    //unordered_map<Name,int,NameHash,NameEqual> um{ //-----增加判等类
    unordered_map<Name,int,NameHash> um{//在Name类中实现等于运算
        {{"zhang","san"},88},{{"li","si"},70},{{"wang","wu"},66},
        {{"ma","liu"},90},{{"tian","qi"},85}
    };
    for(auto const& p : um)
        cout << p.first << ':' << p.second << endl;
    return 0;
}
#endif
/*哈希函数支持基本类型
 98
 tianqi(10749177057920557798):55
 maliu(14814858603424586924):79
 wangwu(3453504343006445041):67
 lisi(6350557783674738397):98
 zhangsan(2661117444495310627):39
 */

/*哈希函数不支持 自定义类型，需要自己加hash类
 tianqi:85
 maliu:90
 wangwu:66
 lisi:70
 zhangsan:88
 */
