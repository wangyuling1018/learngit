#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QHostInfo>
#include <QNetworkInterface>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    //查找主机之后的操作
    void lookedUp(const QHostInfo &hostInfo);
    void on_btnGetLocal_clicked();

    void on_btnAllAddresses_clicked();

    void on_btnAllInterfaces_clicked();

    void on_btnLookup_clicked();

    void on_btnTextClear_clicked();
private:
    QString protocolName(QAbstractSocket::NetworkLayerProtocol protocol);

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
