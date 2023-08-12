#ifndef LOCATEDIALOG_H
#define LOCATEDIALOG_H

#include <QDialog>

namespace Ui {
class LocateDialog;
}

class LocateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LocateDialog(QWidget *parent = nullptr);
    ~LocateDialog();
    void setSpinRange(int rowcnt,int colCnt);

public slots:
    void setSpinValue(int rowNo,int colNo);
signals:
    void changedCellText(int row,int column,QString& text);
    void changeActioneEnabled(bool b);
private slots:
    void on_btnSetText_clicked();

private:
    void showEvent(QShowEvent*);
    void closeEvent(QCloseEvent*);
private:
    Ui::LocateDialog *ui;
};

#endif // LOCATEDIALOG_H
