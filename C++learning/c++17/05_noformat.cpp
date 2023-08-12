//
//  05_noformat.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//

//格式化I/O：printf，按照你想要的格式打印输出
//非格式化：一个一个字符打印输出
 

#if 0
#include <iostream>
#include <fstream>
using namespace std;

//C++标准库中 设计的类 ifstream/ofstream类

// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    ofstream ofs("./noformat",ios::out);
    if( !ofs){
        cerr << "osf流对象状态错误-------打开文件失败" << endl;
    }
    
    for(char c = ' '; c <= '_'; c++){
        ofs.put(c);
        ofs.flush();
    }
    ofs.close();
      
    ifstream ifs("./noformat",ios::in);
    if(!ifs){
        cerr << "ifs流对象状态错误-------打开文件失败" << endl;
    }
    char c;
    while(1){
        //单参的get
        ifs.get(c);
        if(!ifs){//读完，遇到文件尾，流状态就不对了
            break;
        }else {//没有读完
            cout << c;
        }
    }
    cout << endl;
    //以上代码执行完，文件指针在文件尾
    
    
    ifs.clear();//先清空流对象的状态
    ifs.seekg(0,ios::beg);//再将指针指向文件头
    
    //先清空流对象的状态，再将指针指向文件头，以下代码就可以读取成功了
    while(1){
        //无参的get  //无参get没有读到数据，是因为受到单参get的影响
        c = ifs.get();//如果流对象不是正常状态，流对象是不工作的。需要先清空流对象状态，再将指针指向文件头
        if(c == EOF){//读完
            break;
        } else {//没有读完
            cout << c;
        }
    }
    cout << endl;
    
    
    ifs.close();
    
    return 0;
}

#endif
