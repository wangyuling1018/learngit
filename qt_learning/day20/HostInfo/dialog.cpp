#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>


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

//QHostInfo获取本机主机名和IP地址
void Dialog::on_btnGetLocal_clicked()
{
    QString localName = QHostInfo::localHostName();   // 本地主机名
    ui->plainTextEdit->appendPlainText("本地主机名：" + localName + "\n");

    QHostInfo hostInfo = QHostInfo::fromName(localName); // 主机信息对象
    QList<QHostAddress> addrList =  hostInfo.addresses();  // IP地址列表

    for(int i=0; i < addrList.count(); i++){
        QHostAddress addr = addrList.at(i);
        bool isChecked = ui->ckbIPv4Only->isChecked();
        bool isShow = true;
        if(isChecked)
            isShow = (addr.protocol() == QAbstractSocket::IPv4Protocol);
        if(isShow){
            ui->plainTextEdit->appendPlainText("协议：" + protocolName(addr.protocol()));
            ui->plainTextEdit->appendPlainText("本机IP地址" + addr.toString());
            ui->plainTextEdit->appendPlainText("");
        }
    }


}
//根据协议类型返回字符串格式的协议名称
QString Dialog::protocolName(QAbstractSocket::NetworkLayerProtocol protocol){
    switch(protocol){
    case QAbstractSocket::IPv4Protocol:
        return "IPv4Protocol";
    case QAbstractSocket::IPv6Protocol:
        return "IPv6Protocol";
    case QAbstractSocket::AnyIPProtocol:
        return "AnyIPProtocol";
    case QAbstractSocket::UnknownNetworkLayerProtocol:
        return "UnknownNetworkLayerProtocol";
    }
}

//查找主机之后的操作
void Dialog::lookedUp(const QHostInfo &hostInfo){
    QList<QHostAddress> addrList = hostInfo.addresses();//IP地址列表
    for(int i=0; i < addrList.count(); i++){
        QHostAddress addr = addrList.at(i);
        bool isChecked = ui->ckbIPv4Only->isChecked();
        bool isShow = true;
        if(isChecked)
            isShow = (addr.protocol() == QAbstractSocket::IPv4Protocol);
        if(isShow){
            ui->plainTextEdit->appendPlainText("协议：" + protocolName(addr.protocol()));
            ui->plainTextEdit->appendPlainText("本机IP地址" + addr.toString());
            ui->plainTextEdit->appendPlainText("");
        }
    }
}
//QHostInfo查找域名的IP地址
void Dialog::on_btnLookup_clicked()
{
    QString hostName = ui->editLookup->text();
    ui->plainTextEdit->appendPlainText("正在查找主机信息：" + hostName);
    QHostInfo::lookupHost(hostName,this,SLOT(lookedUp(QHostInfo)));
}

//QNetWorkInterface::Addresses
void Dialog::on_btnAllAddresses_clicked()
{
    QList<QHostAddress> addrList = QNetworkInterface::allAddresses();
    if(addrList.isEmpty())
        return;
    for(int i=0; i < addrList.count(); i++){
        QHostAddress addr = addrList.at(i);
        bool isChecked = ui->ckbIPv4Only->isChecked();
        bool isShow = true;
        if(isChecked)
            isShow = (addr.protocol() == QAbstractSocket::IPv4Protocol);
        if(isShow){
            ui->plainTextEdit->appendPlainText("协议：" + protocolName(addr.protocol()));
            ui->plainTextEdit->appendPlainText("本机IP地址" + addr.toString());
            ui->plainTextEdit->appendPlainText("");
        }
    }
}

//QNextWorkInterface::allInterface
void Dialog::on_btnAllInterfaces_clicked()
{
    QList<QNetworkInterface> interList = QNetworkInterface::allInterfaces();//网络接口列表
    for(int i= 0;i < interList.count();i++){
        QNetworkInterface interface = interList.at(i);
        if(!interface.isValid())
            continue;
        ui->plainTextEdit->appendPlainText("设备名称：" + interface.humanReadableName());
        ui->plainTextEdit->appendPlainText("硬件地址："+ interface.hardwareAddress());
        QList<QNetworkAddressEntry> entryList = interface.addressEntries();
        for(int j =0; j < entryList.count();j++){
            QNetworkAddressEntry entry = entryList.at(j);
            ui->plainTextEdit->appendPlainText("   IP地址：" + entry.ip().toString());
            ui->plainTextEdit->appendPlainText("   子网掩码：" + entry.netmask().toString());
            ui->plainTextEdit->appendPlainText("   广播地址：" + entry.broadcast().toString());
            ui->plainTextEdit->appendPlainText("");
        }
        ui->plainTextEdit->appendPlainText("\n");
    }
}



//清空文本
void Dialog::on_btnTextClear_clicked()
{
    ui->plainTextEdit->clear();
}

