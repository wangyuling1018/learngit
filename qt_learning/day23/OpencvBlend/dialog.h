#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QImage>
#include <opencv2/opencv.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private slots:
    void on_verticalSlider_valueChanged(int value);

private:
    //界面初始化
    void initWidget();
    //处理图片
    void imgProc(float alpha);
    //显示图片
    void imgShow();

private:
    Ui::Dialog *ui;
    cv::Mat myImg; //缓存图片  //Mat是点阵结构
    QImage myQImg; //保存图片
};
#endif // DIALOG_H
