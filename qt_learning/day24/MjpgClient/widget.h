#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>
#include <QThread>
#include "facedetection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
signals:
    //自定义信号
    void hasImage(QImage);
private slots:
    //有视频流数据
    void onMjpgReadyRead();
    //有快照数据
    void onJpegReadyRead();



    void on_btnMjpg_clicked();

    void on_btnJpeg_clicked();

private:
    Ui::Widget *ui;
    QNetworkAccessManager* manager; //管理整个通信过程
    QNetworkRequest request;        //根据url生成请求包

    QNetworkReply* mjpgReply;       //获取视频流响应数据包
    QByteArray mjpgBuffer;          //保存发送过来的视频流响应数据
    QImage mjpgImg;                 //保存视频流中的一帧

    QNetworkReply* jpegReply;       //获取快照响应数据包
    QByteArray jpegBuffer;          //保存发送过来的快照响应数据
    QImage jpegImg;                 //保存快照中的图片

    QThread* thread;                //子线程（人脸识别）
    FaceDetection* faceDetect;      //工作对象

};
#endif // WIDGET_H
