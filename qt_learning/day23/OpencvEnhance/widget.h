#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_verticalSliderContrast_valueChanged(int value);

    void on_verticalSliderBrightness_valueChanged(int value);

private:
    //界面初始化
    void initWidget();
    //处理图片
    void imgProc(float contrast,int brightness);
    //显示图片
    void imgShow();

private:
    Ui::Widget *ui;
    cv::Mat myImg; //缓存图片  //Mat是点阵结构
    QImage myQImg; //保存图片
};
#endif // WIDGET_H
