
#include "LoginDialog.h"
#include <QApplication>
int main(int argc,char** argv)
{
    //创建应用程序
    QApplication app(argc,argv);

    //创建窗口对象
    LoginDialog td;

    //显示窗口
    td.show();

    //进入主事件循环
    return app.exec();
}

