#include "widget.h"
#include "ui_widget.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlError>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    loadDept();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnSelect_clicked()
{
    QSqlQuery query;
    query.exec("select * from emp;");
    while(query.next()){
        qDebug() << query.value(0).toInt() << '\t'
                 << query.value(1).toString() << '\t'
                 << query.value(2).toString() << '\t'
                 << query.value(3).toInt() << '\t'
                 << query.value(4).toDouble();
    }
    /*
    qDebug() << "------------------执行first()，定位到第一行-------------------" ;
    if(query.first()){
        //获取query执向的记录的行号
        int rowNo = query.at();
        //获取每条记录的列数（字段数）
        int colNum = query.record().count();
        //获取“empNo”字段在记录中的列号
        int filedNo = query.record().indexOf("empNo");
        //根据字段的列号获取字段的值
        int empNo = query.value(filedNo).toInt();
        //同样的方式，获取其他字段的值
        filedNo = query.record().indexOf("empName");
        QString empName = query.value(filedNo).toString();
        filedNo = query.record().indexOf("gender");
        QString gender = query.value(filedNo).toString();
        filedNo = query.record().indexOf("deptId");
        int deptId = query.value(filedNo).toInt();
        filedNo = query.record().indexOf("salary");
        double salary = query.value(filedNo).toDouble();
        //输出
        qDebug() << "行号：" << rowNo;
        qDebug() << "列数：" << colNum;
        qDebug() << "工号：" << empNo;
        qDebug() << "姓名：" << empName;
        qDebug() << "性别：" << gender;
        qDebug() << "部门：" << deptId;
        qDebug() << "工资：" << salary;
    }

    qDebug() << "------------------执行seek(3)，定位到第四行-------------------" ;
    if(query.seek(3)){
        qDebug() << "行号：" << query.at();
        qDebug() << "工号：" << query.value("empNo").toInt();
        qDebug() << "姓名：" << query.value("empName").toString();
        qDebug() << "性别：" << query.value("gender").toString();
        qDebug() << "部门：" << query.value("deptId").toInt();
        qDebug() << "工资：" << query.value("salary").toDouble();
      }

    qDebug() << "------------------执行last()，定位到最后一行-------------------" ;
    if(query.last()){
        qDebug() << "行号：" << query.at();
        qDebug() << "工号：" << query.value(0).toInt();
        qDebug() << "姓名：" << query.value(1).toString();
        qDebug() << "性别：" << query.value(2).toString();
        qDebug() << "部门：" << query.value(3).toInt();
        qDebug() << "工资：" << query.value(4).toDouble();
    }
    */
}

//查询dept表，并将数据加载到cmbDept控件中
void Widget::loadDept(){
    QSqlQuery query;
    query.exec("select deptId,deptName from dept");
    while(query.next()){
        ui->cmbDeptId->addItem(query.value("deptName").toString(),query.value("deptId"));
    }
}

//插入
void Widget::on_btnInsert_clicked()
{
    QSqlQuery query;
    QString empNo = ui->editEmpNo->text().trimmed();
    if(empNo.isEmpty()){
        QMessageBox::information(this,"插入","工号不允许为空");
        return;
    }
    QString empName = ui->editEmpName->text().trimmed();
    if(empName.isEmpty()){
        QMessageBox::information(this,"插入","姓名不允许为空");
        return;
    }
    QString gender = ui->cmbGender->currentText();
    int deptId = ui->cmbDeptId->currentData().toInt();//combox可以隐藏数据，currentData获取隐藏的数据
    double salary = ui->spinBoxSalary->value();

    //常用prepare方式对数据库进行操作
    query.prepare("insert into emp values(?,?,?,?,?)");
    query.addBindValue(empNo);
    query.addBindValue(empName);
    query.addBindValue(gender);
    query.addBindValue(deptId);
    query.addBindValue(salary);
    if(query.exec())
        QMessageBox::information(this,"插入","插入成功");
    else
        QMessageBox::critical(this,"插入","插入失败\n" + query.lastError().text());

    //以下这种方式不建议用
   /*
    QString sqlStr = QString("insert into emp values(%1,'%2','%3',%4,%5)")
            .arg(empNo.toInt()).arg(empName).arg(gender).arg(deptId).arg(salary);
    //qDebug() << sqlStr;

    if(query.exec(sqlStr))
        QMessageBox::information(this,"插入","插入成功");
    else
        QMessageBox::critical(this,"插入","插入失败\n" + query.lastError().text());
    */

}

//修改
void Widget::on_btnUpdate_clicked()
{
    QString empNo = ui->editEmpNo->text().trimmed();
    if(empNo.isEmpty()){
        QMessageBox::information(this,"修改","工号不允许为空");
        return;
    }
    QString empName = ui->editEmpName->text().trimmed();
    if(empName.isEmpty()){
        QMessageBox::information(this,"修改","姓名不允许为空");
        return;
    }
    QString gender = ui->cmbGender->currentText();
    int deptId = ui->cmbDeptId->currentData().toInt();//combox可以隐藏数据，currentData获取隐藏的数据
    double salary = ui->spinBoxSalary->value();

    QSqlQuery query;
    query.prepare(
                "update emp set empName=:empName,gender=:gender,deptId=:detpId,salary=:sal where empNo=:empNo");
    query.bindValue(":empName",empName);
    query.bindValue(":gender",gender);
    query.bindValue(":deptId",deptId);
    query.bindValue(":sal",salary);
    query.bindValue(":empNo",empNo);
    if(query.exec()){
        if(query.numRowsAffected() == 0)
            QMessageBox::information(this,"修改","没有匹配的数据");
        else
            QMessageBox::information(this,"修改","修改数据成功");
    }else{
        QMessageBox::critical(this,"修改","修改数据失败\n" + query.lastError().text());
    }

}

//删除
void Widget::on_btnDelete_clicked()
{
    QString empNo = ui->editEmpNo->text().trimmed();
    if(empNo.isEmpty()){
        QMessageBox::information(this,"删除","工号不允许为空");
        return;
    }
    QSqlQuery query;
    query.prepare("delete from emp where empNo=?");
    //query.addBindValue(empNo);
    query.bindValue(0,empNo);
    if(query.exec()){
        if(query.numRowsAffected() == 0)
            QMessageBox::information(this,"删除","没有匹配的数据");
        else
            QMessageBox::information(this,"删除","删除数据成功");
    }else{
        QMessageBox::critical(this,"删除","删除数据失败\n" + query.lastError().text());
    }


}

