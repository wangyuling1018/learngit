#include<QApplication>
#include<QDialog>
#include <QSlider>  //滑块
#include <QSpinBox> //整型选值框

//QSlider、QSpinBox
int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    QDialog parent;
    parent.move(500,350);
    parent.resize(300,100);

    //创建滑块控件，并设置位置和大小
    QSlider slider(Qt::Horizontal,&parent);
    slider.move(35,35);
    slider.resize(140,30);
    slider.setRange(0,100);

    //创建选值框件，并设置位置和大小
    QSpinBox spinBox(&parent);
    spinBox.move(195,35);
    spinBox.resize(70,30);
    spinBox.setRange(0,100);

    parent.show();

    //信号和槽函数的连接
    //QSlider::valueChanged(int) -----> QSpinBox::setValue(int)
    //QObject::connect(&slider,SIGNAL(valueChanged(int)),&spinBox,SLOT(setValue(int)));
    //connect的重载版本中的一种写法，这种写法：要求信号函数和槽函数都不能有重载，如下
    QObject::connect(&slider,&QSlider::valueChanged,&spinBox,&QSpinBox::setValue); //ok，信号函数和槽函数都没有重载版本


    //QSpinBox::valueChanged(int) -----> QSlider::setValue(int)
    QObject::connect(&spinBox,SIGNAL(valueChanged(int)),&slider,SLOT(setValue(int)));

    //这个版本的connect，信号函数和槽函数的形参只能写形参类型，不能带形参名
    //QObject::connect(&spinBox,SIGNAL(valueChanged(int v)),&slider,SLOT(setValue(int v))); //error

    //error,QSpinBox中的信号函数valueChanged有重载，无法推断调用哪一个重载函数
    //使用这个重载的connect函数时，要求信号函数和槽函数都不能有重载
    //QObject::connect(&spinBox,&QSpinBox::valueChanged,&slider,&QSlider::setValue);  //error，信号函数有重载版本



    return app.exec();
}
