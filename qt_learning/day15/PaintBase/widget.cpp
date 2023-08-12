#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("基本绘图操作");
    setPalette(QPalette(Qt::white));//设置背景颜色
    setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}

//绘图事件处理函数
void Widget::paintEvent(QPaintEvent* event){
    //
    int w = this->width();
    int h = this->height();
    QRect rect(w/4,h/4,w/2,h/2);

    //创建Qpainter对象
    QPainter painter(this);
    //创建画笔
    QPen pen;
    pen.setColor(Qt::cyan);// 设置颜色
    pen.setWidth(3); // 设置线宽
    pen.setStyle(Qt::SolidLine);// 设置线的样式
    pen.setJoinStyle(Qt::BevelJoin);// 设置线的连接点样式
    //设置画笔
    painter.setPen(pen);

    //创建画刷
    QBrush brush;
    //brush.setColor(Qt::yellow);
    //brush.setStyle(Qt::SolidPattern);
    brush.setStyle(Qt::TexturePattern);
    brush.setTexture(QPixmap(":/1.png"));
    //设置画刷
    painter.setBrush(brush);

    //绘制矩形
    //painter.drawRect(20,30,300,300);// 绘制矩形
   // painter.drawRect(rect);// 绘制矩形
    //painter.drawEllipse(rect);//绘制椭圆
    //painter.drawArc(rect,30*16,120*16);// 绘制弧线
    //painter.drawChord(rect,30*16,120*16); // 绘制弦
    //painter.drawPie(rect,30*16,120*16);// 绘制扇形
    QPoint points[6] = {
        {w/4,h/2},{3*w/8,h/4},{5*w/8,h/4},
        {3*w/4,h/2},{5*w/8,3*h/4},{3*w/8,3*h/4}

    };
    //painter.drawPolygon(points, 6);// 绘制多边形
    painter.drawPolyline(points,6);// 绘制折线





}
