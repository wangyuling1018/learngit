#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "workthread.h"
#define MAXSIZE 2

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnStart_clicked();

    void on_btnStop_clicked();

private:
    Ui::Widget *ui;
    WorkThread* workThread[MAXSIZE];

};
#endif // WIDGET_H
