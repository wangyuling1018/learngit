#ifndef SIZEDIALOG_H
#define SIZEDIALOG_H

#include <QDialog>

namespace Ui {
class SizeDialog;
}

class SizeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SizeDialog(QWidget *parent = nullptr);
    ~SizeDialog();
    //初始化对话框窗口上的两个QSpinBox
    void setRowColumn(int row,int column);
    //返回对话框窗口输入的行数
    int rowCnt();
    //返回对话框窗口输入的列数
    int columnCnt();

private:
    Ui::SizeDialog *ui;
};

#endif // SIZEDIALOG_H
