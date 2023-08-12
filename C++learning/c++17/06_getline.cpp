//
//  06_getline.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//
/*
 
 
 streamsize num:期望读取的字符个数。
 char delim：定界符，读取字符到我设定的定界符为止，然后存入buffer中，定界符一般设置为‘\n',但也可以设置成其他的
 
 
 
 */


#if 0
#include <iostream>
#include <fstream>
using namespace std;

//C++标准库中国 设计的类 ifstream 类

// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    ifstream ifs("./getline",ios::in);
    if( !ifs ){
        cerr << "ifs流对象状态错误----打开文件失败" << endl;
    }
    /*
    char buf[2];
    ifs.getline(buf,2,'\n');
    cout << buf << endl;
    cout << "ifs流对象的状态值：" << ifs.rdstate() << endl;
    */
    char buf[256];
    while(1){
        ifs.getline(buf,256,'\n');
        if(!ifs){
            break;
        }else{
            cout << buf << endl;
            cout << "ifs流对象的状态值：" << ifs.rdstate() << endl;
        }
        
        
    }
    //以上代码执行完后，指针指向文件尾
    
    ifs.getline(buf,256,'\n');
    cout << buf << endl;
    cout << "ifs流对象的状态值：" << ifs.rdstate() << endl;//再次读取，流对象状态是6=2+4
    
    ifs.close();
    return 0;
}

#endif
