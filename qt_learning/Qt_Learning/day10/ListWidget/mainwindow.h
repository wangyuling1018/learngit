#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actListInit_triggered();

    void on_actItemInsert_triggered();

    void on_actItemAppend_triggered();

    void on_actItemDelete_triggered();

    void on_actListClear_triggered();

    void on_actSelAll_triggered();

    void on_actSelNone_triggered();

    void on_actSellnvs_triggered();

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_ckbEditable_clicked(bool checked);

    void on_listWidget_customContextMenuRequested(const QPoint &pos);

    void on_tabWidget_currentChanged(int index);

    void on_toolBox_currentChanged(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
