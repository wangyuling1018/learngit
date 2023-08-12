#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStandardItemModel> //标准项数据模型
#include <QItemSelectionModel> //项选择模型
#include "comboxdelegate.h" // 自定义代理类

#define COLUMNCOUNT 5 //列数

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
    // 当选择单元格发生变化时,QItemSelecitonModel::currentChanged(...)
    void onSelectionCurrentChanged(const QModelIndex &current, const QModelIndex &previous);
    void on_actOpen_triggered();

    void on_actAppend_triggered();

    void on_actInsert_triggered();

    void on_actDelete_triggered();

    void on_actAlignLeft_triggered();

    void on_actAlignCenter_triggered();

    void on_actAlignRight_triggered();

    void on_actFontBold_triggered(bool checked);

    void on_actSave_triggered();

    void on_actModelData_triggered();

private:
    void init(void);//初始化界面
    // 将数据从字符串列表加载到数据模型
    void initModelFromStringList(QStringList &fileContent);


private:
    Ui::MainWindow *ui;
    QStandardItemModel* model; //数据模型
    QItemSelectionModel* selection; //选择模型
    QLabel* labelCurFile; //当前文件
    QLabel* labelCurCell; //当前单元格行列号
    QLabel* labelCurText; //当前单元格内容
    ComboxDelegate cmbDelegate; // 下拉列表代理控件
};
#endif // MAINWINDOW_H
