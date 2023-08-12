#include "widget.h"
#include "ui_widget.h"
#include <cmath>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("坐标系统和坐标变换");
    setAutoFillBackground(true);
    resize(600,300);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent*){
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);// 抗锯齿
    //生成五角星的五个顶点坐标
    qreal r = 100; //半径
    const qreal pi = 3.14;// π
    qreal deg = pi*72/180;// 弧度(72°)
    QPointF points[5] = {
        {r,0},{r*cos(deg),-r*sin(deg)},{r*cos(2*deg),-r*sin(2*deg)},
        {r*cos(3*deg),-r*sin(3*deg)},{r*cos(4*deg),-r*sin(4*deg)}
    };

    //设置画笔
    QPen pen;
    //pen.setWidth(2);
    pen.setColor(Qt::blue);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    //设置字体
    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    painter.setFont(font);
    //设置画刷
    QBrush brush;
    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    //设计五角星的painterPath
    QPainterPath starPath;
    starPath.moveTo(points[0]);// 移动当前点到第一个点
    starPath.lineTo(points[3]);
    starPath.lineTo(points[1]);
    starPath.lineTo(points[4]);
    starPath.lineTo(points[2]);
    starPath.closeSubpath();// 闭合路径
    //显示顶点编号
    for(int i = 0;i < 5; i++)
        starPath.addText(points[i],font,QString::number(i));
    //绘图
    painter.save();// 保存坐标状态
    painter.translate(100,150); // 平移
    painter.drawPath(starPath); // 绘制路径(五角星)
    painter.drawText(0,0,"S1");
    painter.restore();          // 恢复坐标状态

    painter.translate(295,150);// 平移
    painter.scale(0.8,0.8);    // 缩放（缩小）
    painter.rotate(90);        // 顺时针旋转90°
    painter.drawPath(starPath);
    painter.drawText(0,0,"S2");

    painter.resetTransform();  // 复位所有变换,到最初的原始状态
    painter.translate(490,150);
    painter.rotate(-144);      // 逆时针旋转144°
    painter.drawPath(starPath);
    painter.drawText(0,0,"S3");
    //绘图
}
