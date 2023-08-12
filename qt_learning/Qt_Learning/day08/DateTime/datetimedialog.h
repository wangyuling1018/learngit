#ifndef DATETIMEDIALOG_H
#define DATETIMEDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class DateTimeDialog; }
QT_END_NAMESPACE

class DateTimeDialog : public QDialog
{
    Q_OBJECT

public:
    DateTimeDialog(QWidget *parent = nullptr);
    ~DateTimeDialog();

private slots:
    void on_pushButton_clicked();

    void on_btnSetTime_clicked();

    void on_btnSetDate_clicked();

    void on_btnSetDateTim_clicked();

    void on_calendarWidget_selectionChanged();

private:
    Ui::DateTimeDialog *ui;
};
#endif // DATETIMEDIALOG_H
