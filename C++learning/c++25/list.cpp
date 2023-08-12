//
//  list.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/4.
//
/*
 迭代器概念：
 1.迭代器就是一个类（迭代类）对象。
 2.通过对这个对象进行操作（例如++/--）可以对链表容易进行某种程度（全局或局部）的遍历
 3.这样可以是用户不必关心链表容器的内部结构。
 
 迭代类分类：
 正向非常迭代类 iterator
 正向常迭代类  const_iterator
 反向非常迭代类  reverse_iterator
 反向常迭代类 const_reverse_iterator

 正向：迭代器的m_start(开始指向)指向链表的头节点，m_end(终止指向)指向链表的尾节点
           ++操作指向m_cur(当前指向)的下一个节点(m_next)，--操作指向m_cur(当前指向)的上一个节点(m_prev)

 反向：迭代器的m_start(开始指向)指向链表的尾节点，m_end(终止指向)指向链表的头节点
           ++操作指向m_cur(当前指向)的上一个节点(m_prev)，--操作指向m_cur(当前指向)的下一个节点(m_next)

 非常：可以对目标进行增删改操作

 常： 不可以对目标进行增删改操作
 */

#if 0

//自定义基本链表容器
#include <cstdlib>
#include <iostream>
#include <stdexcept>//标准异常头文件
using namespace std;
template<typename T>class list{
public:
    //缺省构造
    list():m_head(NULL),m_tail(NULL){}
    //拷贝构造
    list(const list& that):m_head(NULL),m_tail(NULL){
        //拷贝构造就是构造一个新的链表，拿现有的链表中的每一个节点，去构造一个新的节点，然后构造一个新的链表出来。从链表头开始克隆节点，那就是新链表添加尾节点。如果反了会逆序。
        //如果从链表头开始克隆，调用的就是 添加尾节点的功能；如果从链表尾开始克隆，调用的就是 添加头节点的功能
        for(node* pnode = that.m_head; pnode; pnode = pnode->m_next)
            push_back(pnode->m_data);
        /*
        for(node* pnode = that.m_tail; pnode; pnode = pnode->m_prev)
            push_front(pnode->m_data);
         */
         
    }
    //析构函数
    ~list(){
        clear();
    }
    //链表判空
    bool empty(){
        return m_head ==NULL && m_tail ==NULL;
    }
    //添加头节点
    void push_front(T const& data){
        m_head = new node(NULL,data,m_head); //构造一个新节点，并将m_head指向新节点 //新节点的 前指针指向NULL，数据是data，后指针指向m_head //现在新头节点可以用m_head表示了
        if(m_head->m_next){ //原链表不为空，看原头节点是否为NULL  //原来的头节点的前指针 指向 新节点
            m_head->m_next->m_prev = m_head; //（m_head->m_next）新头节点的下一个节点（原头节点）（->m_prev）原头节点的前指针（= m_head）指向新节点
        }else{
            m_tail = m_head;//原链表为空，尾节点 指向 新头节点
        }
        
    }
    //添加尾节点
    void push_back(T const& data){
        m_tail = new node(m_tail,data,NULL);//构造一个新节点，并将m_tail指向新节点 //新节点的 前指针指向m_tail，数据是data，后指针指向NULL //现在新尾节点可以用m_tail表示了
        if(m_tail->m_prev){//原链表不为空，看原尾节点是否为NULL //原来的尾节点的后指针 指向 新节点
            m_tail->m_prev->m_next = m_tail;//（m_tail->m_prev）新节点的前一个节点（原尾节点）（->m_next）原尾节点的后指针（= m_tail）指向新节点
        }else{
            m_head = m_tail;//原链表为空，头节点 指向 新尾节点
        }
    }
    //删除头节点
    void pop_front(){
        if(empty())//链表为NULL
            return;
        node* pnode = m_head->m_next;//备份第二个节点
        delete m_head;//删除头节点
        if(pnode)//如果备份节点不为NULL
            pnode->m_prev = NULL;//备份节点的前指针 指向 NULL
        else//备份节点为NULL，表示链表中只有一个节点
            m_tail = NULL;
        m_head = pnode;//m_head指向备份节点
    }
    //删除尾节点
    void pop_back(){
        if(empty())
            return;
        node* pnode = m_tail->m_prev;//备份尾部第二个节点
        delete m_tail;//删除尾节点
        if(pnode)
            pnode->m_next = NULL;//备份节点的后指针 指向 NULL
        else
            m_head =  NULL;
        m_tail = pnode; //m_tail指向备份节点
    }
    //获取头节点数据
    T& front(){//非常版本
        if(empty())//链表为NULL
            //不能return任何合适的值，只能抛异常
            throw underflow_error("front():NULL list");
        return m_head->m_data;
    }
    T const& front()const{//常版本
        //常版本 和 非常版本的内部代码是一样的，可以直接调用非常版本函数即可。
        //如果想调用非常版本front函数，必须去常，否则是常版本自己调自己。
        return const_cast<list*>(this)->front();
    }
    //获取尾节点数据
    T& back(){
        if(empty())
            throw underflow_error("back():NULL list");
        return m_tail->m_data;
    }
    T const& back()const{
        return const_cast<list*>(this)->back();
    }
    //清空链表
    void clear(){
        while(!empty()){
            pop_front(); // pop_back();
        }
    }
    //获取链表大小
    size_t size(){
        size_t i = 0;
        for(node* pnode = m_head; pnode; pnode = pnode->m_next)
            i++; //++i
        return i;
    }
private:
    /*
     *节点类
     */
    class node{
    public:
        node(node* prev,T data,node* next) : m_prev(prev),m_data(data),m_next(next){}
        node* m_prev;   //前指针，指向前一个节点
        T m_data;       //节点数据
        node* m_next;   //后指针
        
    };
public:
    /*
     *正向非常迭代类
     */
    class iterator{
    public:
        iterator(node* start,node* cur,node* end) : m_start(start),m_cur(cur),m_end(end){}
        T& operator*(){
            if(m_cur == NULL)
                throw underflow_error("operator*:NULL list");
            return m_cur->m_data;
        }
        iterator& operator++(){
            if(m_cur == NULL)
                m_cur = m_start; //实现了循环链表
            else
                m_cur = m_cur->m_next;
            return *this;
        }
        iterator& operator--(){
            if(m_cur == NULL)
                m_cur = m_end;
            else
                m_cur = m_cur->m_prev;
            return *this;
        }
        bool operator==(iterator const& that)const{
            return (m_start == that.m_start) && (m_cur == that.m_cur) && (m_end == that.m_end);
        }
        bool operator!=(iterator const& that)const{
            return !(*this == that);//直接用173行的函数，加一个取反
        }
        
    private:
        node* m_start; //开始指向
        node* m_cur;  //当前指向
        node* m_end;  //终止指向
        friend class list;//list是iterator的好朋友，所以list可以使用iterator的私有成员
    };
    
    //获取起始迭代器：遍历链表
    iterator begin(){
        return iterator(m_head,m_head,m_tail);
    }
    //终止迭代器：遍历结束标志
    iterator end(){
        return iterator(m_head,NULL,m_tail);
    }
    
    //在迭代器指向的位置添加节点
    //新节点添加到现在指向节点的前面
    void insert(iterator const& loc,T const& data){
        if(loc == end()){//当前迭代器指向最后一个节点的下一个位置
            push_back(data);
        }else{
            //构造一个新节点，前指针指向当前节点的前一个节点，后指针指向当前节点
            node* pnode = new node(loc.m_cur->m_prev,data,loc.m_cur); //loc.m_cur 当前节点，loc.m_cur->m_prev 当前节点的前一个节点 //现在当前节点是pnode
            //当前节点的前指针指向新节点
            pnode->m_next->m_prev = pnode;//pnode->m_next插入位置的后面的一个节点 ->m_prev 的前指针  = pnode 指向新节点
            if(pnode->m_prev){ //当前节点的前一个节点不为NULL
                pnode->m_prev->m_next = pnode; //当前节点的前一个节点后指针指向新节点  //pnode->m_prev插入位置的前面一个节点 ->m_next的后指针 = pnode指向新节点
            }else{
                m_head = pnode;
            }
        }
    }
    
    //删除迭代器指向位置的节点
    void erease(iterator const& loc){
        if(loc == end()){//当前节点指向尾部的NULL位置
            return;
        }
        node* pdel = loc.m_cur;
        if(pdel->m_prev){//要删除节点的前一个节点不为NULL
            pdel->m_prev->m_next = pdel->m_next;
            //pdel->m_prev要删除节点的前一个节点 ->m_next的后指针 = pdel->m_next 指向要删除节点的下一个节点
        }else{
            m_head = pdel->m_next; //头节点 变成 要删除节点的后一个节点
        }
        
        if(pdel->m_next){
            pdel->m_next->m_prev = pdel->m_prev;
            //pdel->m_next要删除节点的下一个节点 ->m_prev的前指针 = pdel->m_prev指向要删除节点前一个节点
        }else{
            m_tail = pdel->m_prev;//尾节点 变成 要删除节点的前一个节点
        }
        
        delete pdel;//删除当前节点
    }
    /*
     *正向非常迭代类：不能修改目标
     */
    class const_iterator{
    public:
        const_iterator(iterator const& it) : m_it(it){}
        T const& operator*(){
            return *m_it;//直接用常版本的operator*()函数
        }
        const_iterator& operator++(){
            ++m_it;//直接用常版本的operator++()函数
            return *this;
        }
        const_iterator& operator--(){
            --m_it;//直接用常版本的operator--()函数
            return *this;
        }
        bool operator==(const_iterator const& that)const{
            return m_it == that.m_it;//直接用常版本的operator==()函数
        }
        bool operator!=(const_iterator const& that)const{
            return !(*this == that); //直接用253行的函数，加一个取反
        }
        
    private:
        iterator m_it;
    };
    
    //获取起始迭代器-正向常迭代器
    const_iterator cbegin()const{
        return iterator(m_head,m_head,m_tail);
    }
    //获取终止迭代器-正向常迭代器
    const_iterator cend()const{
        return iterator(m_head,NULL,m_tail);
    }
    
private:
    node* m_head;  //链表头
    node* m_tail;  //链表尾
    
    //friend ostream& operator<<(ostream& os,list<int> const& l);
};

// 比较查找(==) :  [a,b)
template<typename IT,typename T>
IT Find(IT const&a,IT const& b ,T const& data){ //查找范围[a,b)
    for(IT it = a; it != b; ++it){
        if(*it == data)
            return it;
    }
    return b; //b指向的节点不参与查找，返回它作为没有找到的依据
}

//快速排序（<）: [a,b)
template<typename IT>void Sort(IT const& a,IT const& b){
    IT p = a;
    IT last = b;//b指向的排序范围的最后一个节点的下一个位置
    --last;//指向最后一个
    for(IT i = a,j = last; i != j;){
        while(i != p && *i < *p)//i和p指向的不是一个节点，且i指向的数据小于p指向的数据。不交换
            ++i;
        if( i!= p){ // 需要交换
            swap(*i,*p);
            p = i;
        }
        
        while(j != p && *p < *j)//j和p指向的不是一个节点，且p指向的数据小于j指向的数据。不交换
            --j;
        if( j!= p){ // 需要交换
            swap(*j,*p);
            p = j;
        }
        
    }//循环结束后，p=i=j，指向的数据位置确定，前面的都小于该数据，后面的都大于该数据
    IT it = a;
    ++it;//指向第二个节点
    if(p != a && p != it)//p既没有指向第一个节点，也没有指向第二个节点
        Sort(a,p);
    it = p;
    ++it;//指向p的下一个节点
    if( it != b && it != last)//p既没有指向倒数第一个节点，也没有指向倒数第二个节点
        Sort(it,b);
}
//比较器（类）：<
template<typename T>class less{
public:
    bool operator()(T const& a,T const& b){
        return a<b;
    }
};

/*
//比较器（类）：>
template<typename T>class greater{
public:
    bool operator()(T const& a,T const& b){
        return a>b;
    }
};
 */
//快速排序：比较器
template<typename IT,typename T,template<typename M>typename CMP>
void Sort(IT const& a,IT const& b,CMP<T> cmp){
    IT p = a;
    IT last = b;//b指向的排序范围的最后一个节点的下一个位置
    --last;//指向最后一个
    for(IT i = a,j = last; i != j;){
        while(i != p && cmp(*i,*p))//i和p指向的不是一个节点，且i指向的数据小于p指向的数据。不交换
            ++i;
        if( i!= p){ // 需要交换
            swap(*i,*p);
            p = i;
        }
        
        while(j != p && cmp(*p, *j))//j和p指向的不是一个节点，且p指向的数据小于j指向的数据。不交换
            --j;
        if( j!= p){ // 需要交换
            swap(*j,*p);
            p = j;
        }
        
    }//循环结束后，p=i=j，指向的数据位置确定，前面的都小于该数据，后面的都大于该数据
    IT it = a;
    ++it;//指向第二个节点
    if(p != a && p != it)//p既没有指向第一个节点，也没有指向第二个节点
        Sort(a,p,cmp);
    it = p;
    ++it;//指向p的下一个节点
    if( it != b && it != last)//p既没有指向倒数第一个节点，也没有指向倒数第二个节点
        Sort(it,b,cmp);
}
//链表容器的实现者
//-----------------------------------------
//链表容器的使用者
/*
ostream& operator<<(ostream& os,list<int> const& l){//输出流操作符函数 只能使用者写，因为实现者无法知道你想怎么打印，也无法用模板，太多数据类型和打印格式了...
    for(list<int>::node* pnode = l.m_head; pnode; pnode = pnode->m_next)
        os << pnode->m_data << " ";
    return os;
}
*/

void print(string const& str,list<int>& l){
    cout << str << endl;
    /*
    typedef list<int>::iterator IT;
    for(IT it =  l.begin(); it != l.end(); ++it)
        cout << *it << " ";
     */
    for(int i:l) //-std=c++11 //从l中每次拿一个数据给i //底层依赖于迭代器，如果链表没有封装迭代器，则不能这样用
        cout << i << " ";
    cout << endl << "-------------------------------" << endl;
}

int main(){
    list<int> ls;
    for(int i = 0; i< 5; i++)
        ls.push_front(10+i); //14 13 12 11 10
    for(int i = 0; i < 5; i++)
        ls.push_back(100+i);//14 13 12 11 10 100 101 102 103 104
    //cout << ls << endl;
    print("添加首尾节点后：",ls);
    
    ls.insert(++ls.begin(), 1000);//增，在第二个位置增加节点
    print("在迭代器指向的位置增加节点：",ls);
    
    ls.erease(--ls.end());//删，删除最后一个节点
    print("删除迭代器指向的位置节点：",ls);
    
    typedef list<int>::iterator IT;
    IT it = ls.begin();
    *it = 6666;          //改
    print("修改迭代器指向的位置节点的数据：",ls);
    
    const list<int> cls(ls);
    typedef list<int>::const_iterator CIT;
    for(CIT cit = cls.cbegin();cit != cls.cend(); ++cit){
        cout << *cit << " ";
    }
    cout << endl << "------------------------" << endl;
    
    //IT fit = Find<IT,int>(ls.begin(),ls.end(),103);  //查，[第一个，尾部NULL]，全范围
    IT fit = Find<IT,int>(++ls.begin(),--ls.end(),13); //查，[第二个,倒数第二个）
    //IT fit = Find(ls.begin(), ls.end(), 103);
    //if(fit != ls.end()){//查，[第一个，尾部NULL]，全范围
    if(fit != --ls.end()){//查，[第二个,倒数第二个）
        cout << "找到了" << endl;
        ls.erease(fit);
    }
    print("查找后并删除后：",ls);
    
    Sort(ls.begin(), ls.end());
    print("利用<排序后：",ls);
    
    //标准库中也有greater类模板，less类模板，加“：：”表示调用自己的，匿名调用自己的greater<int>() //greater<int>后加（）是实例化
    Sort(ls.begin(),ls.end(),greater<int>());//使用比较器排序 ----调用模板库的
    print("使用比较器(>)排序后：",ls);
    
    Sort(ls.begin(),ls.end(),::less<int>());//使用比较器排序-----调自己的
    print("使用比较器(<)排序后：",ls);
    
    /*
    cout << "大小：" << ls.size() << endl;
    cout << "头节点：" << ls.front() << endl;
    cout << "尾节点：" << ls.back() << endl;
    
    ls.pop_front();
    cout << "删除头节点：" << ls << endl;
    
    ls.pop_back();
    cout << "删除尾节点" << ls << endl;
    
    const list<int> cls(ls);
    cout << "头节点：" << cls.front() << endl;
    cout << "尾节点：" << cls.back() << endl;
     */
    
    return 0;
}


#endif

