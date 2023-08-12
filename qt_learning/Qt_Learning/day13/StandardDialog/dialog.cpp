#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>    // 标准文件对话框
#include <QColorDialog>   // 标准颜色对话框
#include <QFontDialog>    // 标准字体对话框
#include <QInputDialog>   // 标准输入对话框
#include <QMessageBox>    // 标准消息对话框

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

//打开多个文件
void Dialog::on_btnOpenFiles_clicked()
{
    QString curPath = QDir::currentPath();
    QStringList strList = QFileDialog::getOpenFileNames(this,"打开多个文件",curPath,"All Files(*.*)");
    if(!strList.isEmpty()){
        for(int i = 0;i < strList.size(); i++){
            ui->plainTextEdit->appendPlainText(strList.at(i));
        }
    }

}

//选择已有目录
void Dialog::on_btnExitDir_clicked()
{
    QString curPath = QDir::currentPath();
    QString existingDir = QFileDialog::getExistingDirectory(this,"选择已有目录",curPath);
    if(!existingDir.isEmpty())
        ui->plainTextEdit->appendPlainText(existingDir);
}

//选择颜色
void Dialog::on_btnGetColor_clicked()
{
    QPalette pal = ui->plainTextEdit->palette();
    QColor color = QColorDialog::getColor(pal.color(QPalette::Text),this,"选择颜色");
    if(color.isValid()){
        pal.setColor(QPalette::Text,color);
        ui->plainTextEdit->setPalette(pal);
    }

}

//选择字体
//macos上运行有问题
void Dialog::on_btnGetFont_clicked()
{
    QFont initFont = ui->plainTextEdit->font();
    bool ok;
    QFont font = QFontDialog::getFont(&ok,initFont,this,"选择字体");
    if(ok)
        ui->plainTextEdit->setFont(font);
}

//输入字符串
void Dialog::on_btnGetText_clicked()
{
    bool ok;
    QString str = QInputDialog::getText(this,"字符串对话框","请输入字符串：",QLineEdit::Normal,"新建一个.txt",&ok);
    if(ok)
        ui->plainTextEdit->appendPlainText(str);

}

//输入整数
void Dialog::on_btnGetInt_clicked()
{
    bool ok;
    int curValue = ui->plainTextEdit->font().pointSize();//获取文件编辑框中的字体号
    int inputValue = QInputDialog::getInt(this,"整数对话框","字体大小设置：",curValue,8,48,1,&ok);
    if(ok){
        QFont font = ui->plainTextEdit->font();
        font.setPointSize(inputValue);
        ui->plainTextEdit->setFont(font);
    }

}

//输入浮点数
void Dialog::on_btnGetDouble_clicked()
{
    bool ok;
    double value = QInputDialog::getDouble(this,"浮点数对话框","请输入一个浮点数：",23.33,1.23,56.78,2,&ok);
    if(ok){
        QString str = QString::asprintf("输入的浮点数为：%.2f",value);
        ui->plainTextEdit->appendPlainText(str);
    }
}

//条目选择输入
void Dialog::on_btnGetItem_clicked()
{
    QStringList strList;
    strList << "c++" << "云计算" << "Java"  << "人工智能";
    bool ok;
    QString text = QInputDialog::getItem(this,"条目选择输入对话框","请选择一个方向：",strList,0,false,&ok);
    if(ok & !text.isEmpty())
        ui->plainTextEdit->appendPlainText("选择的方向是" + text);
}



//清空文本内容
void Dialog::on_btnTextClear_clicked()
{
    ui->plainTextEdit->clear();
}

//information
void Dialog::on_btnInformation_clicked()
{
     QMessageBox::information(this,"information消息框","文件已打开，字体大小已设置");
}

//warning
void Dialog::on_btnWarning_clicked()
{
    QMessageBox::warning(this,"warning消息框","文件已被修改");
}

//critical
void Dialog::on_btnCritical_clicked()
{
    QMessageBox::critical(this,"critical消息框","有不明网络访问程序");
}

//
void Dialog::on_btnAbout_clicked()
{
    QMessageBox::about(this,"about消息框","about嘿嘿～");
}

//question
void Dialog::on_btnQuestion_clicked()
{
    QMessageBox::StandardButton res = QMessageBox::question(this,"question消息框","文件已经被修改是否保存？",
                                                            QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,QMessageBox::NoButton);

    if(res == QMessageBox::Yes)
        ui->plainTextEdit->appendPlainText("Question消息框： Yes被选择");
    else if(res == QMessageBox::No)
        ui->plainTextEdit->appendPlainText("Question消息框：No被选择");
    else if(res == QMessageBox::Cancel)
        ui->plainTextEdit->appendPlainText("Question消息框：Cancel被选择");

}

