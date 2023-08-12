#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QLabel>
#include <QHostInfo>
#include <QNetworkInterface>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QString getLocalIP();//获取本机IP地址
private slots:
    //自定义槽函数
    //[signal] void QTcpServer::newConnection()
    void onNewConnection();

    //[signal] void QAbstractSocket::connected()
    void onConnected();

    //[signal] void QAbstractSocket::disconnected()
    void onDisconnected();

    //[signal] void QAbstractSocket::stateChanged(QAbstractSocket::SocketStatesocketState)
    void onStateChanged(QAbstractSocket::SocketState socketState);

    //[signal] void QIODevice::readyRead()
    void onReadyRead();

    void on_actStart_triggered();

    void on_actStop_triggered();

    void on_actTextClear_triggered();

    void on_btnSend_clicked();

private : Ui::MainWindow *ui;

    QTcpServer* tcpServer;//TCP服务器
    QTcpSocket* tcpSocket;//TCP通信用的socket

    QLabel* labelListen;//状态栏显示 监听状态
    QLabel* labelSocketState;//状态栏显示 Sokcet状态
};
#endif // MAINWINDOW_H
