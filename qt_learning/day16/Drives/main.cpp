#include <QCoreApplication>
#include <QSqlDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList driverList = QSqlDatabase::drivers();//获取驱动
    foreach(QString str ,driverList)
        qDebug() << str;

    return a.exec();
}
