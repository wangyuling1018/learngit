#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include "ui_LoginDialog.h"
#include <QMessageBox>
#include <QDebug>

class LoginDialog: public QDialog{
    Q_OBJECT
public:
    //构造函数
    LoginDialog(void);
    //析构函数
    ~LoginDialog(void);
public slots:
    //点击ok按钮时，发射accepted信号
    void on_btnBox_accepted(void);
    //点击cancel按钮时，发射rejected信号
    void on_btnBox_rejected(void);
private:
    Ui::LoginDialog* ui;

};




#endif //LOGINDIALOG_H
