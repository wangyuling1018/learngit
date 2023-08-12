#include "datetimedialog.h"
#include "ui_datetimedialog.h"
#include <QMessageBox>

DateTimeDialog::DateTimeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DateTimeDialog)
{
    ui->setupUi(this);
}

DateTimeDialog::~DateTimeDialog()
{
    delete ui;
}

//读取当前日期时间
void DateTimeDialog::on_pushButton_clicked()
{
    QDateTime curDateTime = QDateTime::currentDateTime();// 获取系统当前日期时间
    QDate curDate = curDateTime.date();// 提取当前日期
    QTime curTime = curDateTime.time();// 提取当前时间
    ui->timeEdit->setTime(curTime);  // 将当前时间显示到QTimeEdit控件中
    ui->dateEdit->setDate(curDate);  // 将当前日期显示到QDateTime控件中
    ui->dateTimeEdit->setDateTime(curDateTime); // 将当前日期时间显示到QDateTimeEdit控件中

    // 以字符串方式显示到对应的单行编辑框中
    ui->lineEditTime->setText(curTime.toString("HH:mm:ss"));
    ui->lineEditDate->setText(curDate.toString("yyyy年MM月dd日"));
    ui->lineEditDateTime->setText(curDateTime.toString("yyyy/MM/dd HH:mm:ss"));
}

//设置时间
void DateTimeDialog::on_btnSetTime_clicked()
{
    QString str = ui->lineEditTime->text().trimmed();
    if(str.isEmpty()){
        QMessageBox::warning(this,"设置时间","请输入时间");
        return;
    }
    QTime time = QTime::fromString(str,"hh:mm:ss");
    if(!time.isValid()){
        QMessageBox::warning(this,"设置时间","输入时间格式错误<hh:mm:ss>");
        return;
    }
    ui->timeEdit->setTime(time);
}

//设置日期
void DateTimeDialog::on_btnSetDate_clicked()
{
    QString str = ui->lineEditDate->text().trimmed();
    if(str.isEmpty()){
        QMessageBox::warning(this,"设置日期","请输入日期");
        return;
    }
    QDate date = QDate::fromString(str,"yyyy-MM-dd");
    if(!date.isValid()){
        QMessageBox::warning(this,"设置日期","输入日期格式错误<yyyy-MM-dd>");
        return;
    }
    ui->dateEdit->setDate(date);
}

//设置日期时间
void DateTimeDialog::on_btnSetDateTim_clicked()
{
    QString str = ui->lineEditDateTime->text().trimmed();
    if(str.isEmpty()){
        QMessageBox::warning(this,"设置日期时间","请输入日期时间");
        return;
    }
    QDateTime dateTime = QDateTime::fromString(str,"yyyy-MM-dd hh:mm:ss");
    if(!dateTime.isValid()){
        QMessageBox::warning(this,"设置日期","输入日期格式错误<yyyy-MM-dd hh:mm:ss>");
        return;
    }
    ui->dateTimeEdit->setDateTime(dateTime);
}

//当选择的日期发生改变时
void DateTimeDialog::on_calendarWidget_selectionChanged()
{
    QDate date = ui->calendarWidget->selectedDate();
    QString strDate = date.toString("yyyy年MM月dd日");
    ui->lineEditSelDate->setText(strDate);
}

