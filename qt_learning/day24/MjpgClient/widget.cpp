#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    thread = new QThread(this);
    faceDetect = new FaceDetection; //不能指定父对象
    faceDetect->moveToThread(thread); //将工作对象移动到指定线程
    //连接信号和槽函数
    connect(this,SIGNAL(hasImage(QImage)),faceDetect,SLOT(doFaceDetect(QImage)));
    thread->start();//启动线程

}

Widget::~Widget()
{
    delete manager;
    thread->terminate();
    thread->wait();
    delete thread;
    delete ui;
}

//获取视频
void Widget::on_btnMjpg_clicked()
{
    // 1.准备请求包数据，设置url地址，根据url自动生成请求包
    request.setUrl(QUrl("http://192.168.169.174:8080/?action=stream"));
    // 2.发送请求包，获取视频流数据
    mjpgReply = manager->get(request);
    // 3.当服务器发送来响应数据时，发射readyRead()信号，连接信号和槽函数
    connect(mjpgReply,SIGNAL(readyRead()),this,SLOT(onMjpgReadyRead()));

}


// 接收mjpg视频流格式数据，从中剥离出一张jpeg图片
void Widget::onMjpgReadyRead(){
    //1.接收数据
    mjpgBuffer += mjpgReply->readAll();
    //2.剥离图片帧
    //1>定义变量，保存图片的起始的标记码
    //开始：0xff 0xD8
    //终止：0xff 0xD9
    char startPos[3] = {(char)0xff,(char)0xd8}; //开始的标记码
    char endPos[3] = {(char)0xff,(char)0xd9};   //终止的标记码
    // 2>在发送过来的数据中，查找图片的开始和结束的位置
    int startIndex = mjpgBuffer.indexOf(startPos,0); //从第一个字节开始查找
    if(startIndex == -1){//没有找到对应的位置
        mjpgBuffer.clear();
        return;
    }
    //3>从jpeg图片帧的开始位置（startIndex）向后查找结束标记的位置
    int endIndex = mjpgBuffer.indexOf(endPos,startIndex);
    if(endIndex == -1){
        //找到jpeg图片帧的开始标记，但是没有找到结束标记，说明该图片帧没有接收完毕
        return;
    }

    //4>从视频流数据中截取一张完整图片的数据
    // +2:保存结束标记的两个字节 0xff 0xd9
    QByteArray imgBuff = mjpgBuffer.mid(startIndex,endIndex-startIndex+2);

   //5>将QByteArray的数据加载到图片QImage中，图片的格式为.jpg
    bool res = mjpgImg.loadFromData(imgBuff,"JPG");
    if(!res){//图片加载失败，说明接收到的图片数据不正确
        mjpgBuffer.clear();
        return;
    }else{//3.显示图片，进行人脸识别
        ui->labelMjpg->setPixmap(QPixmap::fromImage(mjpgImg));
        emit hasImage(mjpgImg);//发射信号，进行人脸识别
        mjpgBuffer.clear();
        return;
    }

}


// "获取快照
void Widget::on_btnJpeg_clicked()
{
    // 1.准备请求包数据，设置url地址，根据url自动生成请求包
    request.setUrl(QUrl("http://192.168.169.174:8080/?action=snapshot"));
    // 2.发送请求包，获取视频流数据
    jpegReply = manager->get(request);
    // 3.当服务器发送来响应数据时，发射readyRead()信号，连接信号和槽函数
    connect(jpegReply,SIGNAL(readyRead()),this,SLOT(onJpegReadyRead()));
}
//有快照数据
void Widget::onJpegReadyRead(){
    // 1. 接收数据
    jpegBuffer += jpegReply->readAll();
    // 2. 剥离图片帧
    // 1> 定义变量，保存图片的起始的标记码
    // 开始： 0xff 0xD8
    // 终止： 0xff 0xD9
    char startPos[3] = {(char)0xff,(char)0xd8};  // 开始的标记码
    char endPos[3] = {(char)0xff,(char)0xd9};  // 终止的标记码
    // 2> 在发送过来的数据中，查找图片的开始和结束的位置
    int startIndex = jpegBuffer.indexOf(startPos,0); // 从第一个字节开始查找
    if(startIndex==-1){ // 没有找到对应的位置
        jpegBuffer.clear();
        return;
    }
    // 3> 从jpeg图片帧的开始位置(startIndex)向后查找结束标记的位置
    int endIndex = jpegBuffer.indexOf(endPos,startIndex);
    if(endIndex==-1){ // 找到jpeg图片帧的开始标记，但是没有找到结束标记：说明该图片帧没有接收完毕
        return;
    }
    // 4> 从快照数据中截取一张完整图片的数据
    // +2: 保存结束标记的两个字节 0xff 0xd9
    QByteArray imgBuff = jpegBuffer.mid(startIndex,endIndex-startIndex+2);
    // 5> 将QByteArray的数据加载到图片QImage中，图片格式为.jpg
    bool res = jpegImg.loadFromData(imgBuff,"JPG");
    if(!res){ // 图片加载失败 -- 说明接收到的图片数据不正确
        jpegBuffer.clear();
        return;
    }
    else{ // 3. 显示图片，进行人脸识别
        ui->labelJpeg->setPixmap(QPixmap::fromImage(jpegImg));

        jpegBuffer.clear();
        return;
    }
}
