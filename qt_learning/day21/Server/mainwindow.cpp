#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //状态栏初始化
    labelListen = new QLabel("监听状态：");
    labelListen->setMinimumWidth(150);
    ui->statusbar->addWidget(labelListen);

    labelSocketState = new QLabel("Socket状态：");
    labelSocketState->setMinimumWidth(200);
    ui->statusbar->addWidget(labelSocketState);

    QString localIP = getLocalIP();
    this->setWindowTitle(this->windowTitle()+"---本机IP：" + localIP);
    ui->cmbIP->addItem(localIP);

    tcpServer = new QTcpServer(this);
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(onNewConnection()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

//获取本机IP地址
QString MainWindow::getLocalIP(){
   // QString hostName = QHostInfo::localHostName();
    //QHostInfo hostInfo = QHostInfo::fromName(hostName);

    QString localIP = "";
    //QList<QHostAddress> addrList = hostInfo.addresses();
    QList<QHostAddress> addrList = QNetworkInterface::allAddresses();
    if(!addrList.isEmpty()){
        for(int i = 1;i <addrList.count();i++){
            QHostAddress addr = addrList.at(i);
            if(addr.protocol() == QAbstractSocket::IPv4Protocol){
                localIP = addr.toString();
                break;
            }
        }
    }
    return localIP;
}

//开始监听
void MainWindow::on_actStart_triggered()
{
    QString IP = ui->cmbIP->currentText();
    QHostAddress addr(IP);

    quint16 port = ui->spinPort->value();

    tcpServer->listen(addr,port);

    ui->plainTextEdit->appendPlainText("**开始监听....");
    ui->plainTextEdit->appendPlainText("**服务器地址：" + tcpServer->serverAddress().toString());
    ui->plainTextEdit->appendPlainText("**服务器端口：" + QString::number(tcpServer->serverPort()));

    ui->actStart->setEnabled(false);
    ui->actStop->setEnabled(true);

    labelListen->setText("监听状态：开始监听....");
}

//[signal] void QTcpServer::newConnection()
void MainWindow::onNewConnection(){
    tcpSocket = tcpServer->nextPendingConnection();//获取socket

    //connect(tcpSocket,SIGNAL(connected()),this,SLOT(onConnected()));
    onConnected();

    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));

    connect(tcpSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(onStateChanged(QAbstractSocket::SocketState)));
    onStateChanged(tcpSocket->state());

    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));

}
//[signal] void QAbstractSocket::connected()
void MainWindow::onConnected(){
    ui->plainTextEdit->appendPlainText("**client socket connected");
    ui->plainTextEdit->appendPlainText("**peer address:" + tcpSocket->peerAddress().toString());
    ui->plainTextEdit->appendPlainText("**peer port:" + QString::number(tcpSocket->peerPort()));

}

//[signal] void QAbstractSocket::disconnected()
void MainWindow::onDisconnected(){
    ui->plainTextEdit->appendPlainText("**client socket disconnected");
    tcpSocket->deleteLater();

}

//[signal] void QAbstractSocket::stateChanged(QAbstractSocket::SocketStatesocketState)
void MainWindow::onStateChanged(QAbstractSocket::SocketState socketState){
    switch(socketState){
    case QAbstractSocket::UnconnectedState:
        labelSocketState->setText("Socket状态：UnconnectedState"); break;
    case QAbstractSocket::HostLookupState:
        labelSocketState->setText("Socket状态：HostLookupState"); break;
    case QAbstractSocket::ConnectingState:
        labelSocketState->setText("Socket状态：ConnectingState"); break;
    case QAbstractSocket::ConnectedState:
        labelSocketState->setText("Socket状态：ConnectedState"); break;
    case QAbstractSocket::BoundState:
        labelSocketState->setText("Socket状态：BoundState"); break;
    case QAbstractSocket::ClosingState:
        labelSocketState->setText("Socket状态：ClosingState"); break;
    case QAbstractSocket::ListeningState:
        labelSocketState->setText("Socket状态：ListeningState"); break;
    }
}

// QTcpSocket::readyRead()信号：读取缓冲区行文本
void MainWindow::onReadyRead()
{
    while(tcpSocket->canReadLine())
        ui->plainTextEdit->appendPlainText("[接收] " + tcpSocket->readLine());
}
//停止监听
void MainWindow::on_actStop_triggered()
{
    if(tcpServer->isListening()){
        tcpServer->close();
        ui->actStart->setEnabled(true);
        ui->actStop->setEnabled(false);
        labelListen->setText("监听状态:已停止监听。");
    }
}


void MainWindow::on_actTextClear_triggered()
{
    ui->plainTextEdit->clear();
}

// "发送消息"：发送一行字符串，以换行符结束
void MainWindow::on_btnSend_clicked()
{
    QString msg = ui->editMessage->text();
    ui->plainTextEdit->appendPlainText("[发送]" + msg);
    ui->editMessage->clear();
    ui->editMessage->setFocus();

    QByteArray str = msg.toUtf8();
    str.append("\n");
    tcpSocket->write(str);
}

