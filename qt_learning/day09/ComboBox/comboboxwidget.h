#ifndef COMBOBOXWIDGET_H
#define COMBOBOXWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ComboBoxWidget; }
QT_END_NAMESPACE

class ComboBoxWidget : public QWidget
{
    Q_OBJECT

public:
    ComboBoxWidget(QWidget *parent = nullptr);
    ~ComboBoxWidget();

private slots:
    void on_btnListInit_clicked();

    void on_btnCityZon_clicked();

    void on_cmbSimple_currentTextChanged(const QString &arg1);

    void on_cmbWithUserData_currentTextChanged(const QString &arg1);

    void on_ckbEditable_clicked(bool checked);

    void on_btnListClear_clicked();

    void on_btnTocmb_clicked();

    void on_btnTextClear_clicked(bool checked);

    void on_ckbReadOnly_clicked(bool checked);

    void on_btnTextClear_clicked();

    void on_plainTextEdit_customContextMenuRequested(const QPoint &pos);

private:
    Ui::ComboBoxWidget *ui;
};
#endif // COMBOBOXWIDGET_H
