#ifndef CALCULATORDIALOG_H
#define CALCULATORDIALOG_H

#include <QDialog>
//#include "ui_calculatordialog.h" //低版本直接加这个头文件会报错，因为新创建的项目还没有这个h文件
QT_BEGIN_NAMESPACE
//短式声明（前置声明）
namespace Ui { class CalculatorDialog; } //对名字空间中的类进行短式声明，替代头文件#include "ui_calculatordialog.h"
QT_END_NAMESPACE

class CalculatorDialog : public QDialog
{
    Q_OBJECT

public:
    CalculatorDialog(QWidget *parent = nullptr);
    ~CalculatorDialog();

private slots:
    void on_m_button_clicked();

    void on_m_editOperator_textChanged(const QString &arg1);

private:
    Ui::CalculatorDialog *ui; //组合方式
};
#endif // CALCULATORDIALOG_H
