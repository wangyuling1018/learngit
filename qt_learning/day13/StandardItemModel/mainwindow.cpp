#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog> //文件对话框
#include <QTextStream>
#include <QDebug>
#include <QRegularExpression>>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->splitter);
    init();
    model = new QStandardItemModel(this);
    selection = new QItemSelectionModel(model);
    ui->tableView->setModel(model);
    ui->tableView->setSelectionModel(selection);
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);

    connect(selection,SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(onSelectionCurrentChanged(QModelIndex,QModelIndex)));

    ui->tableView->setItemDelegateForColumn(3,&cmbDelegate);//为性别设置下拉选项
}

MainWindow::~MainWindow()
{
    delete ui;
}

//初始化界面
void MainWindow::init(void){
    labelCurFile = new QLabel("当前文件：");
    labelCurFile->setMinimumWidth(350);
    ui->statusbar->addWidget(labelCurFile);

    labelCurCell = new QLabel("当前单元格：");
    labelCurCell->setMidLineWidth(200);
    ui->statusbar->addWidget(labelCurCell);

    labelCurText = new QLabel("单元格内容：");
    labelCurText->setMinimumWidth(200);
    ui->statusbar->addWidget(labelCurText);

}

// 当选择单元格发生变化时,QItemSelecitonModel::currentChanged(...)
void MainWindow::onSelectionCurrentChanged(const QModelIndex &current, const QModelIndex &previous){
    Q_UNUSED(previous);
    if(current.isValid()){
        labelCurCell->setText(QString("当前单元格：%2行，%2列").arg(current.row()).arg(current.column()));
        QStandardItem* item = model->itemFromIndex(current); // 获取当前项
        labelCurText->setText(QString("当前单元格内容:" + item->text()));

        QFont font = item->font();
        ui->actFontBold->setChecked(font.bold());
    }



}

//打开文件
void MainWindow::on_actOpen_triggered()
{
    QString curPath = QCoreApplication::applicationDirPath();
    QString fileName = QFileDialog::getOpenFileName(this,"打开文件",curPath,"All Files(*.*)");
    if(fileName.isEmpty())
        return;
    QStringList fileContent;
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){// 打开文件
        QTextStream stream(&file);//用文本流读取文件
        ui->plainTextEdit->clear();
        while(!stream.atEnd()){
            QString str = stream.readLine();
            ui->plainTextEdit->appendPlainText(str);
            fileContent.append(str);
        }
        file.close();
        labelCurFile->setText("当前文件：" + fileName);
        initModelFromStringList(fileContent);


    }
}

// 将数据从字符串列表加载到数据模型
void MainWindow::initModelFromStringList(QStringList &fileContent){
    int rowCount = fileContent.count();
    model->setRowCount(rowCount-1);
    //设置表头
    QString header = fileContent.at(0);
    //{"学号","姓名","出生日期","性别","联系方式"}
    QStringList headerList = header.split(QRegularExpression("\\s+"),Qt::SkipEmptyParts);
    model->setHorizontalHeaderLabels(headerList);//设置文字表头
    //设置数据区数据
    QStandardItem* item;
    QStringList tmpList;
    for(int i = 1; i < rowCount; i++){
        QString lineText = fileContent.at(i);
        tmpList = lineText.split(QRegularExpression("\\s+"),Qt::SkipEmptyParts);
        for(int j = 0; j < COLUMNCOUNT; j++){
            item = new QStandardItem(tmpList.at(j));
            model->setItem(i-1,j,item);//设置Item为模型的指定某个指定的行列位置
        }
    }


}

//ui中设置QPlainTextEdit的属性lineWrapMode为noWrap，一行显示不下不换行，就会出现滚动条

//添加行
void MainWindow::on_actAppend_triggered()
{
        QList<QStandardItem*> itemList;// 标准项的列表
        QStandardItem* item;
        for(int i= 0; i <COLUMNCOUNT; i++){
            item = new QStandardItem("");
            itemList << item;
        }

        model->insertRow(model->rowCount(),itemList);// 在尾部插入一行
        QModelIndex curIndex = model->index(model->rowCount()-1,0);
        selection->clearSelection();
        selection->setCurrentIndex(curIndex,QItemSelectionModel::Select);

}


//插入行
void MainWindow::on_actInsert_triggered()
{

    QList<QStandardItem*> itemList;// 标准项的列表
    QStandardItem* item;
    for(int i= 0; i <COLUMNCOUNT; i++){
        item = new QStandardItem("");
        itemList << item;
    }
    QModelIndex curIndex = selection->currentIndex(); // 获取当前选中项的模型索引
    model->insertRow(curIndex.row(),itemList);// 在当前模型索引 所在行插入一行
    selection->clearCurrentIndex();
    selection->setCurrentIndex(curIndex,QItemSelectionModel::Select);

}

//删除行
void MainWindow::on_actDelete_triggered()
{
     QModelIndex curIndex = selection->currentIndex();
     if(curIndex.row() == model->rowCount()-1){// 最后一行
         model->removeRow(curIndex.row());
     }else{
         model->removeRow(curIndex.row());
         selection->setCurrentIndex(curIndex,QItemSelectionModel::Select);
     }
}

//居左
void MainWindow::on_actAlignLeft_triggered()
{
    if(!selection->hasSelection())
        return;

    QModelIndexList selectionIndexs = selection->selectedIndexes();
    for(int i = 0; i < selectionIndexs.count(); i++){
        QModelIndex index = selectionIndexs.at(i);
        QStandardItem* item = model->itemFromIndex(index);
        item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    }
}

//剧中
void MainWindow::on_actAlignCenter_triggered()
{
    if(!selection->hasSelection())
        return;

    // 获取选中项的模型索引(可以多选)
    QModelIndexList selectionIndexs = selection->selectedIndexes();
    for(int i = 0; i < selectionIndexs.count(); i++){
        QModelIndex index = selectionIndexs.at(i);
        QStandardItem* item = model->itemFromIndex(index);
        item->setTextAlignment(Qt::AlignCenter);
    }
}

//居右
void MainWindow::on_actAlignRight_triggered()
{
    if(!selection->hasSelection())
        return;

    // 获取选中项的模型索引(可以多选)
    QModelIndexList selectionIndexs = selection->selectedIndexes();
    for(int i = 0; i < selectionIndexs.count(); i++){
        QModelIndex index = selectionIndexs.at(i);
        QStandardItem* item = model->itemFromIndex(index);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }
}

//粗体
void MainWindow::on_actFontBold_triggered(bool checked)
{
    if(!selection->hasSelection())
        return;
    // 获取选中项的模型索引(可以多选)
    QModelIndexList selectionIndexs = selection->selectedIndexes();
    for(int i = 0; i < selectionIndexs.count(); i++){
        QModelIndex index = selectionIndexs.at(i);
        QStandardItem* item = model->itemFromIndex(index);
        QFont font = item->font();
        font.setBold(checked);
        item->setFont(font);
    }
}

//另存文件
void MainWindow::on_actSave_triggered()
{
    QString curPath = QDir::currentPath();
    QString fileName = QFileDialog::getSaveFileName(this,"另存文件",curPath,"All Files(*.*)");
    if(fileName.isEmpty())
        return;
    QFile file(fileName);
    if(!(file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate)))
        return;
    QTextStream stream(&file);
    QStandardItem *item;
    QString str;
    ui->plainTextEdit->clear();
    //获取表头文本
    for(int i = 0; i < COLUMNCOUNT; i++){
        item = model->horizontalHeaderItem(i);
        str = str + item->text() + "\t";
    }
    stream << str << "\n";
    ui->plainTextEdit->appendPlainText(str);

    //获取数据区数据
    for(int i = 0; i < model->rowCount(); i++){
        str = "";
        for(int j = 0; j < COLUMNCOUNT; j++){
            item = model->item(i,j);
            str = str + item->text() + '\t';
        }
        stream << str << "\n";
        ui->plainTextEdit->appendPlainText(str);
    }
    file.close();

}

//数据模型预览
void MainWindow::on_actModelData_triggered()
{

    QStandardItem *item;
    QString str;
    ui->plainTextEdit->clear();
    //获取表头文本
    for(int i = 0; i < COLUMNCOUNT; i++){
        item = model->horizontalHeaderItem(i);
        str = str + item->text() + "\t";
    }
    ui->plainTextEdit->appendPlainText(str);

    //获取数据区数据
    for(int i = 0; i < model->rowCount(); i++){
        str = "";
        for(int j = 0; j < COLUMNCOUNT; j++){
            item = model->item(i,j);
            str = str + item->text() + '\t';
        }
        ui->plainTextEdit->appendPlainText(str);
    }

}

