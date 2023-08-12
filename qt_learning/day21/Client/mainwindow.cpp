#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    labelSocketState = new QLabel("Socket状态：");
    labelSocketState->setMinimumWidth(150);
    ui->statusbar->addWidget(labelSocketState);

    QString localIP = getLocalIP();
    this->setWindowTitle(this->windowTitle() + "---本机IP：" + localIP);
    ui->cmbIP->addItem(localIP);

    tcpClient = new QTcpSocket(this);
    connect(tcpClient,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(tcpClient,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(tcpClient,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(onStateChanged(QAbstractSocket::SocketState)));
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
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
// "连接到服务器"
void MainWindow::on_actConn_triggered()
{
    QString addr = ui->cmbIP->currentText();
    quint16 port = ui->spinPort->value();
    tcpClient->connectToHost(addr,port);
}

// "断开连接"
void MainWindow::on_actDisconn_triggered()
{
    if(tcpClient->state() == QAbstractSocket::ConnectedState)
        tcpClient->disconnectFromHost();
}


void MainWindow::on_actTextClear_triggered()
{
    ui->plainTextEdit->clear();
}


void MainWindow::on_actExit_triggered()
{
    this->close();
}

// QTcpSocket::connected()信号
void MainWindow::onConnected(){
    ui->plainTextEdit->appendPlainText("++已连接到服务器");
    ui->plainTextEdit->appendPlainText("++peer address:" + tcpClient->peerAddress().toString());
    ui->plainTextEdit->appendPlainText("++peer port:" + QString::number(tcpClient->peerPort()));
    ui->actConn->setEnabled(false);
    ui->actDisconn->setEnabled(true);
}

void MainWindow::onDisconnected(){
    ui->plainTextEdit->appendPlainText("++已断开和服务器的连接");
    ui->actConn->setEnabled(true);
    ui->actDisconn->setEnabled(false);
}

// QTcpSocket::stateChanged(...): Socket状态发生变化时
void MainWindow::onStateChanged(QAbstractSocket::SocketState socketState)
{
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

//发送消息
void MainWindow::on_btnSend_clicked()
{
    QString msg = ui->editMessage->text();
    ui->plainTextEdit->appendPlainText("[发送]" + msg);
    ui->editMessage->clear();
    ui->editMessage->setFocus();

    QByteArray str = msg.toUtf8();
    str.append("\n");
    tcpClient->write(str);
}

void MainWindow::onReadyRead(){
    while(tcpClient->canReadLine()){
        ui->plainTextEdit->appendPlainText("[接收]" + tcpClient->readLine());
    }
}

//窗口关闭事件
void MainWindow::closeEvent(QCloseEvent* event){
    if(tcpClient->state() == QAbstractSocket::ConnectedState){
        tcpClient->disconnectFromHost();
    }
    event->accept();
}
