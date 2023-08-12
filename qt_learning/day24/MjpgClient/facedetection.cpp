#include "facedetection.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <QMessageBox>
#include <QImage>
#include <QDebug>

using namespace cv;
using namespace std;
FaceDetection::FaceDetection(QObject *parent)
    : QObject{parent}
{

}
//人脸检测
void FaceDetection::doFaceDetect(QImage img){
    //将图像转换为RGB24位色
    QImage image = img.convertToFormat(QImage::Format_RGB888);
    //将QImage格式转换位Mat格式
    Mat matImg = Mat(image.height(),image.width(),CV_8UC3,image.bits(),image.bytesPerLine());
    //灰度处理
    Mat imgGray;
    cvtColor(matImg,imgGray,COLOR_BGR2GRAY);
    //加载分类器
    CascadeClassifier face_detector;//创建人脸识别分类器
    string faceDetectorPath = "/Users/wyl/C++_Projects/qt_learning/day24/MjpgClient/haarcascade_frontalface_default.xml";
    face_detector.load(faceDetectorPath);//加载分类器
    //创建向量，保存检测到的人脸数据
    vector<Rect> faces;
    equalizeHist(imgGray,imgGray);//直方图均衡化（图像增强）
    //多尺寸检测人脸
    face_detector.detectMultiScale(imgGray,faces,1.1,3,CV_HAL_DFT_SCALE,Size(30,30));
    if(!faces.empty()){//检测到人脸
        QString str = "检测到" + QString::number(faces.size()) + "  人进入视频区域";
        qDebug() << str;
    }

}
