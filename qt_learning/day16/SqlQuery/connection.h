#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>  //错误信息
#include <QMessageBox>

static bool createConn(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");//驱动
    db.setHostName("localhost");     // 主机名或IP地址
    db.setUserName("root");          // 登录名
    db.setPassword("root123");         // 密码
    db.setDatabaseName("emp");       // 数据库名
    db.setPort(3306);                // 端口号，默认 3306
    if(!db.open()){
        QMessageBox::critical(0,"数据库连接","打开数据库失败\n" + db.lastError().text());
        return false;
    }
    return true;
}



#endif // CONNECTION_H
