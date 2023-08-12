#include "dialog.h"
#include "ui_dialog.h"
#include <QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlError>
#include<QDebug>
#include<QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //QT的数据库驱动
    qDebug()<<"驱动:" << QSqlDatabase::drivers();
    //获取数据库对象
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("!QAZ2wsx3edc");
    db.setDatabaseName("choose");
    if(db.open()==false)
    {
        QMessageBox::warning(this,"失败",db.lastError().text());
        return;
    }
    else {
        ui->label->setText("MYSQL数据库连接上了");
    }

}

Dialog::~Dialog()
{
    delete ui;
}

