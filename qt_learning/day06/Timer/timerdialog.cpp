#include "timerdialog.h"
#include "ui_timerdialog.h"

TimerDialog::TimerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TimerDialog)
{
    ui->setupUi(this);
    m_index = 0;
    m_isStarted = false;
    // 设置随机种子
    //qDebug() << "随机数11111:" << QRandomGenerator::global()->bounded(10);
    //qsrand(QTime::currentTime().msec());  //qsrand过时函数,用QRandomGenerator替代;
    // 加载图片
    loadImage("/Users/wyl/C++_Projects/qt_learning/day06/Timer/images");
    //loadImage("../Timer/images");
    qDebug() << "加载图片的数量：" << m_vecImages.size();
}

TimerDialog::~TimerDialog()
{
    delete ui;
}

// 将图片从指定路径加载到向量容器中
void TimerDialog::loadImage(const QString& path){
    QDir dir(path);
    /*
    QStringList list = dir.entryList(QDir::Files);//获取目录下的所有文件的字符串列表
    for(int i = 0; i < list.size(); i++){
        QImage image(path + "/" + list.at(i));
        m_vecImages << image;
    }
    */

    QStringList list;
    QFileInfoList fileInfoList = dir.entryInfoList(QDir::Files);//获取指定目录下的所有子目录的字符串列表
    for(int i = 0;i < fileInfoList.size();i++){
        if(fileInfoList[i].suffix() == "jpg" || fileInfoList[i].suffix() == "png"
                || fileInfoList[i].suffix() == "jpeg"){//过滤，只要图片
            list.append(fileInfoList[i].fileName());
        }
    }

    for(int i = 0; i < list.size(); i++){//使用文件名构造QImage对象，并添加到向量容器中
        QImage image(path + "/" + list.at(i));
        m_vecImages << image;
    }

    //递归遍历指定目录下的子目录
    QStringList list2 = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);//获取指定子目录下事务所有子目录 ，QDir::NoDotAndDotDot不包含"." 和".."
    for(int i = 0; i < list2.size();i++){
        loadImage(path + "/" + list2.at(i));
    }


}

// 绘图事件处理函数
void TimerDialog::paintEvent(QPaintEvent*){
    // 创建画家类对象
    QPainter painter(this);
    // 获取 绘图区域
    QRect rect = ui->frame->frameRect();
    // 坐标系平移
    rect.translate(ui->frame->pos());
    // 绘图图片
    painter.drawImage(rect,m_vecImages[m_index]);

}

// 定时器事件处理函数
void TimerDialog::timerEvent(QTimerEvent*){
    //QRandomGenerator::global()->bounded(10) 获取0-10的随机数
    m_index = QRandomGenerator::global()->bounded(10) % m_vecImages.size();
    update();// 触发绘图事件
}

// "开始/停止"
void TimerDialog::on_m_button_clicked()
{
    if(!m_isStarted){
        m_isStarted = true;
        m_timerID = startTimer(500);// 启动定时器
        ui->m_button->setText("开始");

    }else{
        m_isStarted = false;
        killTimer(m_timerID);// 停止定时器
        ui->m_button->setText("关闭");

    }

}

