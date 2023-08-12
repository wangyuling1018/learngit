#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QUdpSocket>
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
    //获取本机IP
    QString getLocalIP();

private slots:
    //自定义槽函数
    void onStateChanged(QAbstractSocket::SocketState socketState);
    void onReadyRead();

    void on_actStart_triggered();

    void on_actStop_triggered();

    void on_actTextClear_triggered();

    void on_actExit_triggered();

    void on_btnSend_clicked();

    void on_btnBroadcast_clicked();

private:
    Ui::MainWindow *ui;
    QUdpSocket* udpSocket; //udp通信用的socket
    QLabel* labelSocketState; //状态栏显示 Socket状态
};
#endif // MAINWINDOW_H
