//
//  qt_01.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/17.
//

/*
 1、C++图形用户界面包括QT 和 MFC
     MFC不能跨平台，只能在windows下使用，是微软的
     QT可以跨平台

 Properties:属性
 Public Functions:公有成员函数
 Reimplemented protected functions:重写保护型成员函数
 Macros:宏
 Inherits:继承
 obsolete members：过时成员
 Static public functions:静态公有成员函数

 .ui文件是接口
 ui将designer产生的.ui文件转换成C++文件
 rcc：编译资源（小图标、图片）的
 moc是编译Qt特有的信号和槽的，变成C++代码
 qtcreator是集成开发工具，包括assistant,qmake,designer,uic,rcc,moc这些都有。
 
 QT += widgets      #需要包含的模块
 TEMPLATE = app    #程序类型
 TARGET = Hello    #生产的目标文件
 INCLUDEPATH += .  #需要包含的目录
 DEFINES += QT_DEPRECATED_WARNINGS  #过时功能会有警告
 SOURCES += main.cpp  #源文件，.cpp文件
 HEADERS +=      # 头文件，.h文件
 LIBS +=        #库文件
 FORMS +=       #其他文件，例如ui文件
 
 创建Qt应用程序的步骤：
 1. 创建项目目录
    mkdir Button
 2. 在项目目录下新建文件
     cd Button
     vi main.cpp
 3. 构建项目，生成项目文件
     qmake -project
     在项目文件中添加构建选项 QT += widgets
 4. 构建生成Makefile文件
     qmake
 5. 编译连接
     make
 6. 运行
     liunx环境下：./Button
     macos环境下：open ./Button.app
 
 什么是信号和槽
    - 信号和槽是QT自行定义的一-种通信机制，实现对象之间的数据交互。
    - 当用户或系统触发了-个动作，导致某个控件的状态发生了改变，该控件就会发射一个信号，即调用其类中一个
        特定的成员函数(信号)， 同时还可能携带有必要的参数
    - 槽和普通的成员函数几乎没有太多区别，可以是公有的、保护的或私有的，可以被重载,也可以被覆盖，其参数可以是任意类型，
        并可以像普通成员函数一样调用
    - 槽函数与普通成员函数的差别并不在于其语法特性，而在于其功能。槽函数更多体现为对某种特定信号的处理，
        可以将槽和其它对象信号建立连接，这样当发射信号时，槽函数将被触发和执行，进而来完成具体功能
 
 
 信号和槽连接的语法要求
     -信号和槽参数要一-致
         QObject:connect(A,SIGNAL(sigfun(int), B,SLOT(slotfun(int));//ok
         QObject:.connect(A,SIGNAL(sigfun(int)), B,SLOT(slotfun(int,int));/eror
     一可以带有缺省参数
        QObject:connect(A,SIGNAL(sigfun(int), B,SLOT (slotfun(int,int= 0))//ok
     -信号函数的参数可以多于槽函数，多余参数将被忽略
        QObject:connect(A,SIGNAL(sigfun(int,int), B,SLOT(slotfun(int))://ok
 
 
 
 
 
 
 */



