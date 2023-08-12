//
//  02_multimap.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/7.
//

/*多重映射-multimap
 1.允许键重复的映射，表示一对多的逻辑关系，不支持下标运算符
 2.定义形式：multimap<键类型，值类型> 映射对象；
 3.头文件：map
 */

#if 0
#include<iostream>
#include<map>
using namespace std;
//多重映射-multimap
int main(){
    multimap<string, int> mm{{"zhangsnag",22},{"lisi",29}};
    mm.insert(pair<string,int>("wangwu",27));
    mm.insert(make_pair("sunling", 99));
    mm.insert(make_pair("sunling", 34));
    mm.insert(make_pair("sunling", 67));
    
    /*
    typedef multimap<string,int>::iterator IT;  //正向迭代器
    for(IT it = mm.begin(); it != mm.end(); ++it)
        cout << it->first << ":" << it->second << endl;
     cout << endl;
     */
    
    /*
    for(auto const& p : mm) //11标准支持
        cout << p.first << ":" << p.second << endl;
    cout << endl;
    */
    
    typedef multimap<string,int>::reverse_iterator IT; //反向迭代器
    for(IT it = mm.rbegin(); it != mm.rend(); ++it)
        cout << it->first << ":" << it->second << endl;
    cout << endl;
    return 0;
}
#endif
