//make clean //清除所有中间文件
//moc CalculatorDialog.h -o moc_CalculatorDialog.cpp  //生成C++文件：moc_CalculatorDialog.cpp


#include "CalculatorDialog.h"
#include <QApplication>
int main(int argc,char** argv)
{
    //创建应用程序
    QApplication app(argc,argv);

    //创建窗口对象
    CalculatorDialog calc;

    //显示窗口
    calc.show();

    //进入主事件循环
    return app.exec();
}
