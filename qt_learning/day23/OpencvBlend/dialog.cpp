#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    initWidget();
}

Dialog::~Dialog()
{
    delete ui;
}

//界面初始化
void Dialog::initWidget(){
    QString imgPath = "/Users/wyl/C++_Projects/qt_learning/day23/OpencvBlend/shape01.jpg";
    cv::Mat imgData = cv::imread(imgPath.toLatin1().data());
    cv::cvtColor(imgData,imgData,cv::COLOR_BGR2RGB);
    myImg = imgData;
    myQImg = QImage(imgData.data,imgData.cols,imgData.rows,QImage::Format_RGB888);
    imgShow();
}
//处理图片
void Dialog::imgProc(float alpha){
    cv::Mat imgSrc1 = myImg;
    QString imgPath = "/Users/wyl/C++_Projects/qt_learning/day23/OpencvBlend/shape02.jpg";
    cv::Mat imgSrc2 = cv::imread(imgPath.toLatin1().data());
    cv::cvtColor(imgSrc2,imgSrc2,cv::COLOR_BGR2RGB);

    cv::Mat imgDst;
    //两张图片按照不同的透明度进行叠加
    cv::addWeighted(imgSrc2,alpha,imgSrc1,1-alpha,0,imgDst);
    myQImg = QImage(imgDst.data,imgDst.cols,imgDst.rows,QImage::Format_RGB888);
    imgShow();
}
//显示图片
void Dialog::imgShow(){
    ui->labelview->setPixmap(
                QPixmap::fromImage(myQImg.scaled(ui->labelview->size(),Qt::KeepAspectRatio))
                );
}
//透明度变化时
void Dialog::on_verticalSlider_valueChanged(int value)
{
    imgProc(value/100.0);
}

