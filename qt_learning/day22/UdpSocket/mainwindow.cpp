#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMetaEnum>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //状态栏
    labelSocketState = new QLabel("Socket状态：");
    labelSocketState->setMinimumWidth(200);
    ui->statusbar->addWidget(labelSocketState);

    //本机IP
    QString localIP = getLocalIP();
    setWindowTitle(windowTitle() + "---本机IP：" + localIP);
    ui->cmbTargetIP->addItem(localIP);

    //socket
    udpSocket = new QUdpSocket(this);

    connect(udpSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(onStateChanged(QAbstractSocket::SocketState)));
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

//获取本机IP地址
QString MainWindow::getLocalIP(){
    //QString hostName = QHostInfo::localHostName();
    //QHostInfo hostInfo = QHostInfo::fromName(hostName);
    QString localIP ="";
    //QList<QHostAddress> addrList = hostInfo.addresses();
    QList<QHostAddress> addrList = QNetworkInterface::allAddresses();
    if(!addrList.isEmpty()){
        for(int i = 1; i < addrList.count(); i++){
            QHostAddress addr = addrList.at(i);
            if(addr.protocol() == QAbstractSocket::IPv4Protocol){
                localIP = addr.toString();
                break;
            }
        }
    }
    return localIP;
}

//sokcet状态发生变换时
void MainWindow::onStateChanged(QAbstractSocket::SocketState socketState){
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    const char* state = metaEnum.valueToKey(socketState);
    labelSocketState->setText("Socket状态：" + QString(state));
}


//绑定端口
void MainWindow::on_actStart_triggered()
{
    quint16 port = ui->spinBindPort->value();
    if(udpSocket->bind(port)){//绑定端口成功
        ui->plainTextEdit->appendPlainText("**已成功绑定");
        ui->plainTextEdit->appendPlainText("**绑定端口：" + QString::number(udpSocket->localPort()));
        ui->actStart->setEnabled(false);
        ui->actStop->setEnabled(true);
    }else
        ui->plainTextEdit->appendPlainText("**绑定失败");
}

//解除绑定
void MainWindow::on_actStop_triggered()
{
    udpSocket->abort();//解除绑定
    ui->actStart->setEnabled(true);
    ui->actStop->setEnabled(false);
    ui->plainTextEdit->appendPlainText("**已解除绑定");

}

//清空文本框
void MainWindow::on_actTextClear_triggered()
{
    ui->plainTextEdit->clear();
}

//退出
void MainWindow::on_actExit_triggered()
{
    this->close();
}

//发送消息
void MainWindow::on_btnSend_clicked()
{
    QString targetIP = ui->cmbTargetIP->currentText();//目标IP
    QHostAddress targetAddr(targetIP);
    quint16 targetPort = ui->spinTargetPort->value();//目标端口
    QString str = ui->editMessage->text();  //发送消息的内容
    QByteArray msg = str.toUtf8();
    udpSocket->writeDatagram(msg,targetAddr,targetPort); //发送数据报
    ui->plainTextEdit->appendPlainText("[发送]" + str);
    ui->editMessage->clear();
    ui->editMessage->setFocus();
}

//广播消息
void MainWindow::on_btnBroadcast_clicked()
{
    quint16 targetPort = ui->spinTargetPort->value();//目标端口
    QString str = ui->editMessage->text();  //发送消息的内容
    QByteArray msg = str.toUtf8();
    udpSocket->writeDatagram(msg,QHostAddress::Broadcast,targetPort); //发送数据报
    ui->plainTextEdit->appendPlainText("[广播]" + str);
    ui->editMessage->clear();
    ui->editMessage->setFocus();
}

//读取socket传入的数据
void MainWindow::onReadyRead(){
    while(udpSocket->hasPendingDatagrams()){
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        QHostAddress peerAddr;
        quint16 peerPort;
        udpSocket->readDatagram(datagram.data(),datagram.size(),&peerAddr,&peerPort);
        QString str = datagram.data();
        QString peer = "From" + peerAddr.toString() + ":" + QString::number(peerPort);
        ui->plainTextEdit->appendPlainText(peer + " " + str);

    }
}
