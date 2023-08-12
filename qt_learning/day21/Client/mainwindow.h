#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
protected:
    void closeEvent(QCloseEvent *event);
private:
    QString getLocalIP();  // 获取本机IP地址
private slots:
    // 自定义槽函数
    // void QAbstractSocket::connected()
    void onConnected();
    // void QAbstractSocket::disconnected()
    void onDisconnected();
    // void QAbstractSocket::stateChanged(QAbstractSocket::SocketState socketState)
    void onStateChanged(QAbstractSocket::SocketState socketState);
    // void QIODevice::readyRead()
    void onReadyRead();
    void on_actConn_triggered();

    void on_actDisconn_triggered();

    void on_actTextClear_triggered();

    void on_actExit_triggered();

    void on_btnSend_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket* tcpClient;   // TCP通信用的socket
    QLabel* labelSocketState; // 状态栏显示 Socket状态

};
#endif // MAINWINDOW_H
