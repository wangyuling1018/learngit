#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btnOpenFiles_clicked();

    void on_btnExitDir_clicked();

    void on_btnGetColor_clicked();

    void on_btnGetFont_clicked();

    void on_btnGetText_clicked();

    void on_btnGetInt_clicked();

    void on_btnGetDouble_clicked();

    void on_btnGetItem_clicked();

    void on_btnTextClear_clicked();

    void on_btnInformation_clicked();

    void on_btnWarning_clicked();

    void on_btnCritical_clicked();

    void on_btnAbout_clicked();

    void on_btnQuestion_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
