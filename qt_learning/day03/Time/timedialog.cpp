#include "timedialog.h"
#include <QFont> // 字体类
//构造函数
TimeDialog::TimeDialog()
{
    //界面初始化
    setWindowTitle("时间");
    // label
    m_label = new QLabel(this);
    // 设置边框效果
    //m_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    m_label->setAlignment(Qt::AlignCenter);
    m_label->setFrameStyle(QFrame::Plain | QFrame::Sunken);

    // 设置字体大小
    QFont font;
    font.setPointSize(16);
    m_label->setFont(font);

    // button
    m_button = new QPushButton("获取系统时间",this);
    m_button->setFont(font);

    // 布局
    // 创建垂直布局器
    QVBoxLayout* layout = new QVBoxLayout(this);
    // 自上而下添加控件
    layout->addWidget(m_label);
    layout->addWidget(m_button);

    // 设置为窗口的布局器
    setLayout(layout);

    // 信号和槽函数的连接
    connect(m_button,SIGNAL(clicked()),this,SLOT(getTime()));
    connect(this,SIGNAL(mySignals(QString)),m_label,SLOT(setText(QString)));//代替55行代码，自定义信号函数


}

//点击按钮，获取系统时间
void TimeDialog::getTime(void){
    /*
     大写H 和 小写h 的区别：
        h：如果写了上午下午，就按照12小时制显示，如果没有写上午下午，就按照24小时制显示
        H：不管有没有写上午下午，都按照24小时制显示
     h,hh：没有前置0，范围是0到23
     H,HH：有前置0，范围00到23，小时是一位的时候补0
     m,mm：分钟
     s，ss：秒
    */

    QTime curTime = QTime::currentTime();
    QString strTime = curTime.toString("hh:mm:ss");
   // m_label->setText(strTime);

    // 发射信号   emit:Qt中发射信号的关键字
    emit mySignals(strTime); //代替55行代码，自定义信号函数




}
