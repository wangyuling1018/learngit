#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSpinBox>
#include <QFontComboBox> //字体组合框（下拉列表）

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
    void on_actFontBold_toggled(bool arg1);

    void on_actFontBold_triggered(bool checked);

    void on_actFontItalic_triggered(bool checked);

    void on_actFontUnderline_triggered(bool checked);

    void on_textEdit_selectionChanged();

    void on_textEdit_copyAvailable(bool b);

    //自定义槽函数
    //设置字体大小
    void on_spinFontSize_valueChanged(int fontSize);
    //选择字体类型
    void on_fontCmb_currentIndexChanged(const QString& fontFamily);
    void on_actToolbarLab_triggered(bool checked);

private:
    void initUi();//代码方式初始化界面
private:
    Ui::MainWindow *ui;
    QLabel* labelCurFile;  //状态栏中显示当前文件的label
    QSpinBox* spinFontSize; //工具栏上选择字体大小的选值框
    QFontComboBox* fontCmb; //工具栏上选择字体类型的下拉列表
};
#endif // MAINWINDOW_H
