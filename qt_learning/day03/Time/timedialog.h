#ifndef TIMEDIALOG_H
#define TIMEDIALOG_H
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QTime> //时间类
#include <QVBoxLayout> //垂直布局

class TimeDialog:public QDialog
{
    Q_OBJECT //moc
public:
    TimeDialog();
public slots:
    //点击按钮，获取系统时间
    void getTime(void);
signals:
    // 自定义信号函数：只需声明，不能定义
    void mySignals(const QString &);
private:
    QLabel* m_label; //显示时间
    QPushButton* m_button; //获取系统时间
};

#endif // TIMEDIALOG_H
