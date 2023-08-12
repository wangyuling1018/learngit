//
//  04_iostate.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//
/*
 // 今天这里仅仅是模拟ifstream类的内部实现，和真正标准的实现不同，但是道理是一样的
 class ifstream {
 public：
       ifstream( const char* path, ... ) {
             m_f = open( path, ... );
             if( m_f == -1 )
                  m_state = ios::failbit; // 4
             else
                  m_state = ios::goodbit; // 0
       }
       operator bool( ) const {
             return m_state==ios::goodbit; // 0
       }
       ifstream& operator>>(int/double/float/short/char/string  data) { // 有大量 operator>>函数，形参都不同（重载关系）
              if( m_state == 4 ... ) {
                    return ...;
              }
           int ret = read( m_f, .... );
              if( ret == -1 )
                    m_state = 2;
              else
                    m_state = 0;
       }
       bool good( ) {  return m_state==0;  }
       bool bad()   {  return m_state&1;  }
       bool eof()  {   reutrn m_state&2; }
       bool fail()   {   reutrn m_state&4;  }
       int rdstate() {   return m_state; }
       void clear( ) {  m_state=0; }
 private:
       int m_f; // 保存文件描述符
       int m_state; // 保存 流对象的 状态值***************************
 };
 // 以上代码模拟 ifstream类的内部实现
 // -------------------------------------
 // 以下代码模拟用户

 int main( ) {
      ifstream ifs2("./file", ios::ate);
      if( !ifs2 ) { // ! ifs2.operator bool()
          cerr << "ifs2流对象状态错误 -- 打开文件失败" << endl;
      }
       int ii; double dd;  string ss1,ss2;
       ifs2 >> ii >> dd >> ss1 >> ss2; // ifs2.operator>>(ii).operator>>(dd).operator>>(ss1).operator>>(ss2)
       if( !ifs2 ) { // ! ifs2.operator bool()
           cerr << "ifs2流对象状态错误 -- 读文件失败" << endl;
       }
 }

 */

//如果流对象不是正常状态，流对象是不工作的。需要先清空流对象状态，再将指针指向文件头

#if 0
#include <iostream>
#include <fstream>
using namespace std;

//C++标准库中 设计的类 ifstream类

// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    ifstream ifs2("./file",ios::ate);
    if( !ifs2 ){// ! ifs2.operator bool()
        cerr << "ifs2流对象状态错误---打开文件失败" << endl;
    }
    
    cout << "---------------------第一次读取数据-------------------------" << endl;
    int ii; double dd; string ss1,ss2;
    ifs2 >> ii >> dd >> ss1 >> ss2;
    if( !ifs2 ){// ! ifs2.operator bool()
        cerr << "ifs2流对象状态错误---读文件失败" << endl;
        cerr << "ifs2是0状态吗？" << ifs2.good() << " ,ifs2是1状态吗?" << ifs2.bad() << " ,ifs2是2状态吗?" << ifs2.eof() << " ,ifs2是4状态吗?" << ifs2.fail() << endl;  // 2,4
        cerr << "ifs2具体的状态值：" << ifs2.rdstate() << endl;// 2+4 = 6
    }// 2+4 = 6
    cout << ii << " " << dd << ' ' << ss1 << ' ' << ss2 << endl;
    //以上代码执行完，ifs2指针指向文件尾
    
    cout << "---------------------第二次读取数据-------------------------" << endl;
    ifs2.clear();//先将流对象的状态清成0状态，再将文件指针设置到文件头，否则出现4状态存在，接着读文件无法读取的情况
    ifs2.seekg(0, ios::beg); //设置文件指针的位置，将文件读指针设置到文件头
    ifs2 >> ii >> dd >> ss1 >> ss2;
    if( !ifs2 ){// ! ifs2.operator bool()
        cerr << "ifs2流对象状态错误---读文件失败" << endl;
        cerr << "ifs2是0状态吗？" << ifs2.good() << " ,ifs2是1状态吗?" << ifs2.bad() << " ,ifs2是2状态吗?" << ifs2.eof() << " ,ifs2是4状态吗?" << ifs2.fail() << endl;
        cerr << "ifs2具体的状态值：" << ifs2.rdstate() << endl;
    }
    cout << ii << " " << dd << ' ' << ss1 << ' ' << ss2 << endl;
    
    ifs2.close();
    return 0;
}

#endif
