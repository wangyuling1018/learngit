//
//  list.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/4.
//

#if 0
//自定义基本链表容器
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
            return m_start == that.m_start && m_cur = that.m_cur && m_end == that.m_end;
        }
        bool operator!=(iterator const& that)const{
            return !(*this == that);
        }
        
    private:
        node* m_start; //开始指向
        node* m_cur;  //当前指向
        node* m_end;  //终止指向
    };
    
private:
    node* m_head;  //链表头
    node* m_tail;  //链表尾
    
    friend ostream& operator<<(ostream& os,list<int> const& l);
};



//链表容器的实现者
//-----------------------------------------
//链表容器的使用者
ostream& operator<<(ostream& os,list<int> const& l){//输出流操作符函数 只能使用者写，因为实现者无法知道你想怎么打印，也无法用模板，太多数据类型和打印格式了...
    for(list<int>::node* pnode = l.m_head; pnode; pnode = pnode->m_next)
        os << pnode->m_data << " ";
    return os;
}

int main(){
    list<int> ls;
    for(int i = 0; i< 5; i++)
        ls.push_front(10+i); //14 13 12 11 10
    for(int i = 0; i < 5; i++)
        ls.push_back(100+i);//14 13 12 11 10 100 101 102 103 104
    cout << ls << endl;
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

