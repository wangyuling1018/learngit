//
//  02_new.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/18.
//

#if 0
//动态（堆）内存分配
//C++的动态内存分配 比 C的动态内存分配 功能更强大 更加方便
//C++：new/delete操作符  C：malloc/free函数  //一个是操作符，一个是函数
//new什么类型，返回值类型就是什么类型的指针
#include <iostream>
#include <cstdlib> //动态内存分配的头文件
using namespace std;


//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    int* pm = (int*)malloc(4);//malloc函数返回的是void*，需要转换int*  //初始值为0，不能指定初始值
    cout << "*pm=" << *pm << endl;
    free(pm);//当这行代码执行结束，pm指向的堆内存已经被释放掉，pm变为野指针
    pm = NULL;//好习惯：free后立即将指针置空
    free(pm);//给free传递的为野指针，释放野指针后果很严重，后果未定义（什么错误都有）。释放空指针是安全的
    
    //int* pi = new int; //初始值为0
    int* pi = new int(100);//可以指定初始值
    cout << "*pi=" << *pi << endl;
    delete pi;//当这行代码执行结束，pi指向的内存已经被释放，pi变为野指针
    pi = NULL;//好习惯：delete后立即将指针置空
    delete pi;//给delete传递的为野指针，delete野指针后果未定义，delete空指针是安全的
    
    //int* parr = new int[4];//以数组方式new永远返回第一个元素的地址，默认初始值是0 //申请16个字节内存
    int* parr = new int[4]{10,20,30,40};//可以指定初始值，
    for(int i=0; i < 4; i++){
        cout << parr[i] << " ";
    }
    cout << endl;
    delete[] parr;//以数组的方式delete
    //new数组的时候，会多申请一块4字节内存，这块内存存的是这个数组元素的个数，parr指向16个字节的首地址
    //  4字节 ｜ parr[0] | parr[1] | parr[2] | parr[3]
    //delete后面加[]的作用就是把告诉编译器parr-4后指向的内存一并释放，就是把多申请的4字节内存也一起释放掉。
    //如果delete parr只是释放了16字节内存，前面的4字节就没有释放，导致内存泄露。
    
    int(*pn)[4] = new int[3][4];//以数组方式new永远返回第一个元素的地址 //返回一维数组的指针
    //int(*pn)[4][5] = new int[3][4][5];//通过new操作符分配N维数组，返回N-1维数组指针
    //不管是几维数组，永远当一维数组看。二维数组的第一个元素是一维数组，所以返回第一个一维数组的指针
    delete[] pn;
    
    return 0;
}
#endif

