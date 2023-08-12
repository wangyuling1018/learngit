#include<QApplication>
#include<QPushButton> //下压式按钮（最普通的按钮）
#include<QLabel>
int main(int argc,char** argv){
	QApplication app(argc,argv);

	QPushButton but("hello Qt button !");
	but.show();

	QLabel label("我是标签！");
	label.show();

	return app.exec();
}
