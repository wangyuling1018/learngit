#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sizedialog.h"
#include "locatedialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->tableView);

    model = new QStandardItemModel(5,4,this);
    selection = new QItemSelectionModel(model);
    ui->tableView->setModel(model);
    ui->tableView->setSelectionModel(selection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//设置行数列数
void MainWindow::on_actSetSize_triggered()
{
    //动态创建对话框
    SizeDialog* dlgSetSize = new SizeDialog(this);
    dlgSetSize->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);//设置固定大小
    //传递数据给对话框
    dlgSetSize->setRowColumn(model->rowCount(),model->columnCount());
    //模态方式显示对话框
    int ret = dlgSetSize->exec();
    if(ret == QDialog::Accepted){//"确定"按钮被按下
        //接收对话框返回的数据
        int row = dlgSetSize->rowCnt();
        int cols = dlgSetSize->columnCnt();
        model->setRowCount(row);
        model->setColumnCount(cols);

    }

    //删除
    delete dlgSetSize;
    dlgSetSize = nullptr;
}



//设置表头标题
void MainWindow::on_actSetHeader_triggered()
{
    //父窗口存续期间只创建一次
    if(dlgSetHeaders == nullptr)
        dlgSetHeaders = new HeaderDialog(this);
    //数据传递给HeaderDialog对话框
    if(dlgSetHeaders->HeaderList().count() != model->columnCount()){
        QStringList list;
        for(int i = 0; i < model->columnCount(); i++){
            list.append(model->headerData(i,Qt::Horizontal).toString());
        }
        dlgSetHeaders->setHeaderList(list);
    }
    //模态方式显示对话框
    int ret = dlgSetHeaders->exec();
    if(ret == QDialog::Accepted){
        QStringList strList = dlgSetHeaders->HeaderList();
        model->setHorizontalHeaderLabels(strList);

    }

}
// 设置指定单元格文字
void MainWindow::setCellText(int row,int column,QString& text){
    QModelIndex index = model->index(row,column);
    selection->clearSelection();
    selection->setCurrentIndex(index,QItemSelectionModel::Select);
    model->setData(index,text,Qt::DisplayRole);
}

// 设置QAction actLocate的enabled属性
void MainWindow::setActLocateEnabled(bool en){
    ui->actLocate->setEnabled(en);
}

// "定位单元格"
void MainWindow::on_actLocate_triggered()
{
    //动态创建
    LocateDialog* dlgLocate = new LocateDialog(this);
    //关闭时自动删除
    dlgLocate->setAttribute(Qt::WA_DeleteOnClose);
    //StayOnTop
    Qt::WindowFlags flags = dlgLocate->windowFlags();
    dlgLocate->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowStaysOnTopHint);
    dlgLocate->setSpinRange(model->rowCount(),model->columnCount());// 设置对话框中spinBox的最大值
    QModelIndex index = selection->currentIndex();
    if(index.isValid())
        dlgLocate->setSpinValue(index.row(),index.column());
    //信号和槽函数的连接
    // 对话框窗口发射信号，设定单元格文字
    connect(dlgLocate,SIGNAL(changedCellText(int,int,QString&)),this,SLOT(setCellText(int,int,QString&)));
    // 对话框发射信号，设置actLocate的enabled属性
    connect(dlgLocate,SIGNAL(changeActioneEnabled(bool)),this,SLOT(setActLocateEnabled(bool)));
    // 主窗口发射信号，设置对话框中spinBox的值
    connect(this,SIGNAL(cellIndexChanged(int,int)),dlgLocate,SLOT(setSpinValue(int,int)));

    //非模态方式显示对话框
    dlgLocate->show();

}

// 点击tableView时，发射信号 cellIndexChanged(int rowNo,int colNo);
void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    emit cellIndexChanged(index.row(),index.column());
}

