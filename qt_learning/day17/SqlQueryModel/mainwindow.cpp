#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "datedialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->tableView);
    ui->actInsert->setEnabled(false);
    ui->actDelete->setEnabled(false);
    ui->actUpdate->setEnabled(false);
    ui->actOpenDb->setEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//查询emp表中的数据
void MainWindow::readEmp(){
   queryModel = new QSqlQueryModel(this);
   selection = new QItemSelectionModel(queryModel);

   //执行查询操作
   queryModel->setQuery("select * from emp order by empNo");
   if(queryModel->lastError().isValid()){
       QMessageBox::critical(this,"查询emp","查询emp表失败\n" + queryModel->lastError().text());
       return;
   }
   //设置表头
   queryModel->setHeaderData(0,Qt::Horizontal,"工号");
   queryModel->setHeaderData(1,Qt::Horizontal,"姓名");
   queryModel->setHeaderData(2,Qt::Horizontal,"性别");
   queryModel->setHeaderData(3,Qt::Horizontal,"部门");
   queryModel->setHeaderData(4,Qt::Horizontal,"工资");

  ui->tableView->setModel(queryModel);
  ui->tableView->setSelectionModel(selection);
  //设置工具栏按钮使能状态
  ui->actInsert->setEnabled(true);
  ui->actDelete->setEnabled(true);
  ui->actUpdate->setEnabled(true);
  ui->actOpenDb->setEnabled(false);

}
//查询dept表中的数据
void MainWindow::readDept(){
    QSqlQuery query;
    query.exec("select deptId,deptName from dept");
    while(query.next()){
        m_map.insert(query.value("deptId").toInt(),query.value("deptName").toString());
    }
}
//打开数据库
void MainWindow::on_actOpenDb_triggered()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("!QAZ2wsx3edc");
    db.setDatabaseName("emp");
    if(!db.open()){
        QMessageBox::critical(this,"打开数据库","打开数据库失败\n" + db.lastError().text());
        return;
    }
    readEmp();
    readDept();


}

//插入记录
void MainWindow::on_actInsert_triggered()
{
    QSqlQuery query;
    query.exec("select * from emp where empNo=-1");
    QSqlRecord curRec = query.record();//获取一条空记录
    //动态创建对话框
    DateDialog* dlgDialog = new DateDialog(this);
    dlgDialog->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);//设置固定大小
    dlgDialog->setDept(m_map); //传递dept信息
    dlgDialog->setInsertRecord(curRec); //传递空记录
    int ret = dlgDialog->exec();
    if(ret == QDialog::Accepted){
        QSqlRecord rec = dlgDialog->getInsertRecord();//获取要插入的数据
        query.prepare("insert into emp values(?,?,?,?,?)");
        query.addBindValue(rec.value("empNo"));
        query.addBindValue(rec.value("empName"));
        query.addBindValue(rec.value("gender"));
        query.addBindValue(rec.value("deptId"));
        query.addBindValue(rec.value("salary"));
        if(!query.exec())
            QMessageBox::critical(this,"插入","插入数据失败\n" + query.lastError().text());
        else
            queryModel->setQuery(
                        "select empNo,empName,gender,deptName,salary from dept,emp where dept.deptId=emp.deptId");


    }
    delete dlgDialog;
}
//更新一条记录
void MainWindow::updateRecord(int rowNo){
    QSqlRecord curRec = queryModel->record(rowNo);
    int empNo = curRec.value("empNo").toInt();
    QSqlQuery query;
    query.prepare("select * from emp where empNo=:no");
    query.bindValue(0,empNo);
    query.exec();
    query.first();
    if(!query.isValid())
        return;
    curRec = query.record();

    DateDialog* dlgDialog = new DateDialog(this);
    dlgDialog->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    dlgDialog->setDept(m_map);
    dlgDialog->setUpdateRecord(curRec);
    int ret = dlgDialog->exec();
    if(ret == QDialog::Accepted){
        QSqlRecord rec = dlgDialog->getInsertRecord();
        query.prepare("update emp set empName=:name,gender=:gender,deptId=:id,salary=:sal where empNo=:no");
        query.bindValue(":no",rec.value("empNo"));
        query.bindValue(":name",rec.value("empName"));
        query.bindValue(":gender",rec.value("gender"));
        query.bindValue(":id",rec.value("deptId"));
        query.bindValue(":sal",rec.value("salary"));
        if(!query.exec())
            QMessageBox::critical(this,"更新","更新数据失败\n" + query.lastError().text());
        else
            queryModel->setQuery("select empNo,empName,gender,deptName,salary from dept,emp where dept.deptId=emp.deptId");

    }
    delete dlgDialog;
}


//编辑记录
void MainWindow::on_actUpdate_triggered()
{
    int rowNo = selection->currentIndex().row();
    updateRecord(rowNo);
}
//双击tableView时
void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    updateRecord(index.row());
}

//删除记录
void MainWindow::on_actDelete_triggered()
{
    int rowNo = selection->currentIndex().row();
    QSqlRecord curRec = queryModel->record(rowNo);
    if(curRec.isEmpty())
        return;
    int empNo = curRec.value("empNo").toInt();
    QSqlQuery query;
    query.prepare("delete from emp where empNo=:no");
    query.bindValue(":no",empNo);
    if(!query.exec())
        QMessageBox::critical(this,"删除记录","删除记录失败\n" + query.lastError().text());
    else
         queryModel->setQuery("select empNo,empName,gender,deptName,salary from dept,emp where dept.deptId=emp.deptId");
}




void MainWindow::on_actExit_triggered()
{

}

