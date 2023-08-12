#ifndef TIMERDIALOG_H
#define TIMERDIALOG_H

#include <QDialog>
#include <QPainter>
#include <QImage>
#include <QTime>
#include <QDir>
#include <QVector>
#include <QDebug>
#include <QRandomGenerator>


QT_BEGIN_NAMESPACE
namespace Ui { class TimerDialog; }
QT_END_NAMESPACE

class TimerDialog : public QDialog
{
    Q_OBJECT

public:
    TimerDialog(QWidget *parent = nullptr);
    ~TimerDialog();

 protected:
    // 绘图事件处理函数
    void paintEvent(QPaintEvent*);
    // 定时器事件处理函数
    void timerEvent(QTimerEvent*);

private slots:
    void on_m_button_clicked();

private:
    // 将图片加载到容器
    void loadImage(const QString& path);


private:
    Ui::TimerDialog *ui;
    QVector<QImage> m_vecImages; // 保存图片的向量容器
    int m_index;// 图片在容器中的索引
    int m_timerID;// 定时器ID
    int m_isStarted;// 标记    true--启动   false--停止
};
#endif // TIMERDIALOG_H
