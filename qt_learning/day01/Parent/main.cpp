/*QT父窗口
QWidget及其子类的对象可以做为其他控件的父窗口
常用的父窗口类有如下三个：
    QWidget
    QMainwindow(主窗口)  //QWidget的直接子类
    QDiolog(对话框) //QWidget的直接子类
 */


#include<QApplication>
#include<QPushButton> //下压式按钮（最普通的按钮）
#include<QLabel>
#include<QWidget>
#include<QMainWindow>
#include<QDialog>

//QT父窗口
int main(int argc,char** argv){
	QApplication app(argc,argv);
	
	//创建父窗口
    //QWidget parent;
    //QMainWindow parent;
    QDialog parent;
	//设置父窗口的位置和大小
	parent.move(500,350);
	parent.resize(300,300);
	
    QLabel label("我是快乐的子窗口：）",&parent);
    label.move(100,30);
	label.resize(180,30);

    QPushButton but("退出",&parent);
    but.move(100,100);
    but.resize(40,40);

    QPushButton* pButton = new QPushButton("取消",&parent); //可以不显示的执行delete操作
    pButton->move(200,100);
    pButton->resize(40,40);
	//显示
    parent.show();//所有子窗口对象会一起显示

	return app.exec();
}
