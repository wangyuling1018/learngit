
#include <QApplication>   // 应用程序类
#include <QLabel>         // 标签控件类

int main(int argc, char** argv){
    // 1. 创建应用程序类对象
    QApplication app(argc,argv);

    // 2. 创建一个标签
    QLabel label("Hello Qt!");

    // 3. 显示标签
    label.show();

    // 4. 进入主事件循环，并等待exit()函数被调用
    return app.exec();
}
