#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "headerdialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void setCellText(int row,int column,QString& text);
    void setActLocateEnabled(bool en);
signals:
    void cellIndexChanged(int rowNo,int colNo);

private slots:
    void on_actSetSize_triggered();

    void on_actSetHeader_triggered();

    void on_actLocate_triggered();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QStandardItemModel* model;
    QItemSelectionModel* selection;
    HeaderDialog* dlgSetHeaders = nullptr;

};
#endif // MAINWINDOW_H
