#include "showimagesdialog.h"
#include "ui_showimagesdialog.h"

ShowImagesDialog::ShowImagesDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowImagesDialog)
{
    ui->setupUi(this);
    m_index = 0;
}

ShowImagesDialog::~ShowImagesDialog()
{
    delete ui;
}

//绘图事件处理函数
void ShowImagesDialog::paintEvent(QPaintEvent* event){
    // 1. 创建画家类对象
    QPainter painter(this);
    // 2. 获取绘图区域
    QRect rect = ui->frame->frameRect();
    //qDebug() << "(" << rect.x() << "," << rect.y() << ")";
    // 坐标系平移
    rect.translate(ui->frame->pos());
    //qDebug() << "(" << rect.x() << "," << rect.y() << ")";
    // 3. 构造一个QImage对象
    QImage image(":/images/" + QString::number(m_index) + ".jpg");

    //QImage image("/Users/wyl/C++_Projects/qt_learning/day05/Showimages/images/" + QString::number(m_index) + ".jpg");
    // 4. 使用painter将image绘制出来
    painter.drawImage(rect,image);
    update();

}

void ShowImagesDialog::on_btnPrev_clicked()
{
    if(--m_index < 0)
           m_index = 8;
       //update();
}


void ShowImagesDialog::on_btnNext_clicked()
{
    if(++m_index > 8)
           m_index = 0;
       //update();
}

