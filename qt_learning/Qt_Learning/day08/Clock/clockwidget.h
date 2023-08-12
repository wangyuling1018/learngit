#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include <QWidget>
#include <QTimer> //定时器类

QT_BEGIN_NAMESPACE
namespace Ui { class ClockWidget; }
QT_END_NAMESPACE

class ClockWidget : public QWidget
{
    Q_OBJECT

public:
    ClockWidget(QWidget *parent = nullptr);
    ~ClockWidget();
private slots:
    //定时器超时的槽函数
    void onTimerTimeout();

private:
    Ui::ClockWidget *ui;
    QTimer* m_timer; //定时器
};
#endif // CLOCKWIDGET_H
