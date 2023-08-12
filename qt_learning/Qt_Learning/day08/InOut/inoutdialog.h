#ifndef INOUTDIALOG_H
#define INOUTDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class InOutDialog; }
QT_END_NAMESPACE

class InOutDialog : public QDialog
{
    Q_OBJECT

public:
    InOutDialog(QWidget *parent = nullptr);
    ~InOutDialog();

private slots:
    void on_btnCalc_clicked();

    void on_btnDexTothe_clicked();

    void on_btnBinToOthe_clicked();

    void on_btnHexToOthe_clicked();

private:
    Ui::InOutDialog *ui;
};
#endif // INOUTDIALOG_H
