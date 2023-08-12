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

void Widget::initWidget(){
    QString imgPath = "/Users/wyl/C++_Projects/qt_learning/day24/OpencvFace/baby.jpg";
    Mat imgData = imread(imgPath.toLatin1().data());
    cvtColor(imgData,imgData,COLOR_BGR2RGB);//图片格式转换
    myImg = imgData;// 保存本地变量
    myQImg = QImage(imgData.data,imgData.cols,imgData.rows,QImage::Format_RGB888);
    imgShow();
}

void Widget::imgShow(){
   ui->labelview->setPixmap(QPixmap::fromImage(myQImg.scaled(ui->labelview->size(),Qt::KeepAspectRatio)));
}
//图片处理：人脸，人眼的检测
void Widget::imgProc(){
    CascadeClassifier face_detector; //定义人脸识别分类器
    CascadeClassifier eyes_detector; //定义人眼识别分类器
    string faceDetectorPath = "/Users/wyl/C++_Projects/qt_learning/day24/OpencvFace/haarcascade_frontalface_alt.xml";
    face_detector.load(faceDetectorPath);// 加载人脸识别
    string eyesDetectorPath = "/Users/wyl/C++_Projects/qt_learning/day24/OpencvFace/haarcascade_eye_tree_eyeglasses.xml";
    eyes_detector.load(eyesDetectorPath);// 加载人眼识别

    vector<Rect> faces;
    Mat imgSrc = myImg;
    Mat imgGray;
    cvtColor(imgSrc,imgGray,COLOR_RGB2GRAY); // 图片格式转换  -->灰度图片
    equalizeHist(imgGray,imgGray);

    //多尺寸人脸检测
    face_detector.detectMultiScale(imgGray,faces,1.1,2,CV_HAL_DFT_SCALE,Size(30,30));
    for(unsigned int i = 0; i< faces.size(); i++){
        Point f_center(faces[i].x+faces[i].width*0.5,faces[i].y+faces[i].height*0.5);
        ellipse(imgSrc,f_center,Size(faces[i].width*0.5,faces[i].height*0.5),0,0,360,Scalar(255,0,255),4,8,0);
        Mat faceROI = imgGray(faces[i]);
        vector<Rect> eyes;
        eyes_detector.detectMultiScale(faceROI,eyes,1.1,2,CV_HAL_DFT_SCALE,Size(30,30));
        for(unsigned int j = 0;j < eyes.size();j++){
            Point e_center(faces[i].x+eyes[j].x+eyes[j].width*0.5,faces[i].y+eyes[j].y+eyes[j].height*0.5);
            int radius = cvRound((eyes[j].width+eyes[j].height)*0.25);
            circle(imgSrc,e_center,radius,Scalar(255,0,0),4,8,0);
        }
        Mat imgDst = imgSrc;
        myQImg = QImage(imgDst.data,imgDst.cols,imgDst.rows,QImage::Format_RGB888);
        imgShow();
    }




}

void Widget::on_btnDelect_clicked()
{
    imgProc();
}

