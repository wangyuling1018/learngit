#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    initWidget();
}

Widget::~Widget()
{
    delete ui;
}
//界面初始化
void Widget::initWidget(){
    QString imgPath = "/Users/wyl/C++_Projects/qt_learning/day23/OpencvEnhance/girldiver.jpg";
    cv::Mat imgData = cv::imread(imgPath.toLatin1().data());//读取图片数据
    cv::cvtColor(imgData,imgData,cv::COLOR_BGR2RGB);//图片格式转换
    myImg = imgData;
    myQImg = QImage(imgData.data,imgData.cols,imgData.rows,QImage::Format_RGB888);
    imgShow();

}
//处理图片
void Widget::imgProc(float contrast,int brightness){
    cv::Mat imgSrc = myImg;
    cv::Mat imgDst = cv::Mat::zeros(imgSrc.size(),imgSrc.type());//初始化一个零值
    imgSrc.convertTo(imgDst,-1,contrast,brightness);
    myQImg = QImage(imgDst.data,imgDst.cols,imgDst.rows,QImage::Format_RGB888);
    imgShow();
}
//显示图片
void Widget::imgShow(){
    ui->labelView->setPixmap(
                QPixmap::fromImage(myQImg.scaled(ui->labelView->size(),Qt::KeepAspectRatioByExpanding))
                //QPixmap::fromImage(myQImg)
                );

}

//对比度
void Widget::on_verticalSliderContrast_valueChanged(int value)
{
    imgProc(value/33.3,ui->verticalSliderBrightness->value());
}

//亮度
void Widget::on_verticalSliderBrightness_valueChanged(int value)
{
    imgProc(ui->verticalSliderContrast->value()/33.3,value);
}

