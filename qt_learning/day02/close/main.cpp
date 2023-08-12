//信号函数参数的个数 >= 槽函数参数的个数
//信号函数将参数传递给槽函数，信号函数将参数传递给槽函数，槽函数可以不用，所以信号函数参数的个数 >= 槽函数参数的个数


#include<QApplication>
#include<QPushButton> //下压式按钮（最普通的按钮）
#include<QLabel>
#include<QDialog>
//信号和槽函数
int main(int argc,char** argv)
{/*
   QApplication app(argc,argv);
   QLabel label("点击关闭按钮干掉我！");
   label.show();

   QPushButton button("关闭");
   button.show();


   QPushButton button2("退出");
   button2.show();

   //信号和槽函数
   //信号和槽函数的参数：一致   ok
   //信号和槽函数：多对一
   //QObject::connect(&button,SIGNAL(clicked(void)),&label,SLOT(close(void)));
   //QObject::connect(&button2,SIGNAL(clicked()),&label,SLOT(close()));

    //信号和槽函数的参数：信号的参数多于槽函数的参数  ok
    //QObject::connect(&button,SIGNAL(clicked(bool)),&label,SLOT(close(void))); //ok

    //信号和槽函数的参数：信号的参数少于槽函数的参数 error
    //QObject::connect(&button,SIGNAL(clicked()),&label,SLOT(setText(QString))); //error

    //信号和槽函数：一对多
    //QObject::connect(&button,SIGNAL(clicked()),&button2,SLOT(close()));
    //QObject::connect(&button,SIGNAL(clicked()),&button,SLOT(close()));

    QObject::connect(&button2,SIGNAL(clicked()),&app,SLOT(closeAllWindows()));//关闭所有窗口

    return app.exec();
    */


    QApplication app(argc,argv);

    QDialog parent;
    parent.move(500,350);
    parent.resize(300,200);

    QLabel label("点击关闭按钮干掉我！",&parent);
    label.move(50,30);
    //label.resize(150,30);

    QPushButton button("关闭",&parent);
    button.move(35,90);
    button.resize(100,30);

    QPushButton button2("退出",&parent);
    button2.move(165,90);
    button2.resize(100,30);

    parent.show();

    //信号和槽函数
    //信号和槽函数的参数：一致   ok
    //信号和槽函数：多对一
    //QObject::connect(&button,SIGNAL(clicked(void)),&label,SLOT(close(void)));
    //QObject::connect(&button2,SIGNAL(clicked()),&label,SLOT(close()));

    //信号和槽函数的参数：信号的参数多于槽函数的参数  ok
    //QObject::connect(&button,SIGNAL(clicked(bool)),&label,SLOT(close(void))); //ok

    //信号和槽函数的参数：信号的参数少于槽函数的参数 error
    //QObject::connect(&button,SIGNAL(clicked()),&label,SLOT(setText(QString))); //error

    //信号和槽函数：一对多
    //QObject::connect(&button,SIGNAL(clicked()),&button2,SLOT(close()));
    //QObject::connect(&button,SIGNAL(clicked()),&button,SLOT(close()));

    //以下2行代码实现的功能一样（将所有的窗口关闭）
    // QObject::connect(&button2,SIGNAL(clicked()),&app,SLOT(closeAllWindows()));
     QObject::connect(&button2,SIGNAL(clicked()),&parent,SLOT(close()));

     return app.exec();

}
