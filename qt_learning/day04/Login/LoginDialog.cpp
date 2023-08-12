#include "LoginDialog.h"

// 构造函数
LoginDialog::LoginDialog(void):ui(new Ui::LoginDialog){
    //界面初始化
    ui->setupUi(this);
}

//析构函数
LoginDialog::~LoginDialog(void){
    delete ui;
    ui = nullptr;
}
//点击ok按钮时，发射accepted信号
void LoginDialog::on_btnBox_accepted(void){
    //假设 账户/密码：tarena/123456
    if(ui->editUserName->text() == "tarena" && ui->editPassword->text() == "123456"){
       qDebug() << "登录成功";
       this->close();
    }else{
        QMessageBox::critical(
                    this,   //父窗口
                    "登录",  //标题栏文本
                    "用户名或密码错误，请重新输入"  //提示信息
                    );
    }

}
//点击cancel按钮时，发射rejected信号
void LoginDialog::on_btnBox_rejected(void){
    QMessageBox::StandardButton res = QMessageBox::question(this,"登录","确定要退出登录吗？",
                                                            QMessageBox:: Yes | QMessageBox::No);
    if(res == QMessageBox::Yes)
        this->close();
}
