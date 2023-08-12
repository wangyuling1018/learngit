#ifndef HEADERDIALOG_H
#define HEADERDIALOG_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class HeaderDialog;
}

class HeaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HeaderDialog(QWidget *parent = nullptr);
    ~HeaderDialog();
    //使用主窗口的model的表头初始化对话框的headerModel
    void setHeaderList(QStringList& headers);
    //返回对话框窗口修改后的字符串列表
    QStringList HeaderList();


private:
    Ui::HeaderDialog *ui;
    QStringListModel* headerModel;
};

#endif // HEADERDIALOG_H
