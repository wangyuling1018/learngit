#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QItemSelectionModel>
#include <QMessageBox>
#include <QMap>


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
    void on_actOpenDb_triggered();

    void on_actInsert_triggered();

    void on_actUpdate_triggered();

    void on_actDelete_triggered();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_actExit_triggered();

private:
    void readEmp();//查询emp表中的数据
    void readDept();//查询dept表中的数据
    void updateRecord(int rowNo);//更新一条记录

private:
    Ui::MainWindow *ui;
    QSqlQueryModel* queryModel; //数据模型
    QItemSelectionModel* selection; //选择模型
    QSqlDatabase db; //数据库

    QMap<int,QString> m_map; //保存部门的信息
};
#endif // MAINWINDOW_H
