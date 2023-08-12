#ifndef DATEDIALOG_H
#define DATEDIALOG_H

#include <QDialog>
#include <QMap>
#include <QSqlRecord>

namespace Ui {
class DateDialog;
}

class DateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DateDialog(QWidget *parent = nullptr);
    ~DateDialog();
    //把部门数据加载到cmbDept中
    void setDept(const QMap<int,QString>& dept);
    //插入记录
    void setInsertRecord(QSqlRecord& record);
    //获取要插入的记录：将界面数据保存到m_record中
    QSqlRecord getInsertRecord();
    // 修改记录
    void setUpdateRecord(QSqlRecord& recData);
private:
    Ui::DateDialog *ui;
    QMap<int,QString> m_dept; //保存dept数据
    QSqlRecord m_record;    //保存一条记录


};

#endif // DATEDIALOG_H
