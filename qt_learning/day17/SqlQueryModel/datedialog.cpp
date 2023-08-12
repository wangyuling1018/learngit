#include "datedialog.h"
#include "ui_datedialog.h"

DateDialog::DateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DateDialog)
{
    ui->setupUi(this);
}

DateDialog::~DateDialog()
{
    delete ui;
}
//把部门数据加载到cmbDept中
void DateDialog::setDept(const QMap<int,QString>& dept){
   m_dept = dept;
   foreach(int i,dept.keys())
       ui->cmbDept->addItem(dept.value(i),i);
}
//插入记录
void DateDialog::setInsertRecord(QSqlRecord& record){
    m_record = record;
    ui->editEmpNo->setReadOnly(false);//设置可编辑
    setWindowTitle("插入记录");
}

//获取要插入的记录：将界面数据保存到m_record中
QSqlRecord DateDialog::getInsertRecord(){
    m_record.setValue("empNo",ui->editEmpNo->text());
    m_record.setValue("empName",ui->editEmpName->text());
    m_record.setValue("gender",ui->cmbGender->currentText());
    m_record.setValue("deptId",ui->cmbDept->currentData());
    m_record.setValue("salary",ui->spinBoxSalary->value());
    return m_record;

}
// 修改记录
void DateDialog::setUpdateRecord(QSqlRecord& recData){
    m_record = recData;
    ui->editEmpNo->setReadOnly(true);//设置不可编辑
    setWindowTitle("编辑记录");
    //根据recData更新界面
    ui->editEmpNo->setText(recData.value("empNo").toString());
    ui->editEmpName->setText(recData.value("empName").toString());
    ui->cmbGender->setCurrentText(recData.value("gender").toString());
    ui->cmbDept->setCurrentText(m_dept.value(recData.value("deptId").toInt()));
    ui->spinBoxSalary->setValue(recData.value("salary").toDouble());

}

