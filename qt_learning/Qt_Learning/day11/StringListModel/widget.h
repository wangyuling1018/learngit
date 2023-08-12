#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStringListModel>//字符串列表数据模型

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
    void on_btnListInit_clicked();

    void on_btnItemAppend_clicked();

    void on_btnItemInsert_clicked();

    void on_btnItemDelete_clicked();

    void on_btnItemClear_clicked();

    void on_bntDisplay_clicked();

    void on_btnTextClear_clicked();

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::Widget *ui;
    QStringListModel* model;//数据模型
};
#endif // WIDGET_H
