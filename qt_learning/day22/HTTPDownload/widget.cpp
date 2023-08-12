#include "widget.h"
#include "ui_widget.h"
#include <QDir>
#include <QMessageBox>
#include <QUrl>
#include <QFileInfo>
#include <QDesktopServices>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

//缺省路径
void Widget::on_btnDefaultPath_clicked()
{
    QString curPath = QDir::currentPath();
    QDir dir(curPath);
    QString sub = "tmp";
    dir.mkdir(sub);
    ui->editPath->setText(curPath + "/" + sub + "/");

}

//下载
void Widget::on_btnDownload_clicked()
{
    QString urlSpec = ui->editURL->text().trimmed();
    if(urlSpec.isEmpty()){
        QMessageBox::critical(this,"下载","请指定需要下载的URL");
        return;
    }

    QUrl newUrl = QUrl::fromUserInput(urlSpec);
    if(!newUrl.isValid()){
        QMessageBox::critical(this,"下载",QString("无效URL：%1 \n 错误信息：%2").arg(urlSpec).arg(newUrl.errorString()));
        return;
    }
    QString tmpDir = ui->editPath->text().trimmed();
    if(tmpDir.isEmpty()){
        QMessageBox::critical(this,"下载","请指定保存下载文件路径");
        return;
    }

    QString fullFileName = tmpDir + newUrl.fileName();
    if(QFile::exists(fullFileName))
        QFile::remove(fullFileName);

    downloadFile  = new QFile(fullFileName);
    if(!downloadFile->open(QIODevice::WriteOnly)){
        QMessageBox::critical(this,"下载","临时文件打开失败");
        return;
    }

    ui->btnDownload->setEnabled(false);
    reply = networkManager.get(QNetworkRequest(newUrl));//发送网络请求，并获取网络响应
    connect(reply,SIGNAL(finished()),this,SLOT(onFinished()));
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(onDownloadProgress(qint64,qint64)));
    connect(reply,SIGNAL(readyRead()),this,SLOT(onReadyRead()));

}
//读取下载数据，并写入文件
void Widget::onReadyRead(){
    downloadFile->write(reply->readAll());
}
//下载进度
void Widget::onDownloadProgress(qint64 bytesSent, qint64 bytesTotal){
    ui->progressBar->setMaximum(bytesTotal);
    ui->progressBar->setValue(bytesSent);
}

//网络响应结束
void Widget::onFinished(){
    QFileInfo fileInfo;
    fileInfo.setFile(downloadFile->fileName());
    downloadFile->close();

    delete downloadFile;
    downloadFile = Q_NULLPTR;
    reply->deleteLater();
    reply = Q_NULLPTR;

    if(ui->ckbIsOpen->isChecked())//完成后打开
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileInfo.absoluteFilePath()));
    ui->btnDownload->setEnabled(true);
}
