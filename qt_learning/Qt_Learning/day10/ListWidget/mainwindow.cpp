#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->splitter);

    //QToolButton和QAction的关联
    ui->tBtnListInit->setDefaultAction(ui->actListInit);
    ui->tBtnListClear->setDefaultAction(ui->actListClear);
    ui->tBtnListInsert->setDefaultAction(ui->actItemInsert);
    ui->tBtnListAppend->setDefaultAction(ui->actItemAppend);
    ui->tBtnListDelete->setDefaultAction(ui->actItemDelete);
    ui->tBtnSelAll->setDefaultAction(ui->actSelAll);
    ui->tBtnSelNone->setDefaultAction(ui->actSelNone);
    ui->tBtnSelInvs->setDefaultAction(ui->actSellnvs);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//初始化列表
void MainWindow::on_actListInit_triggered()
{
    QIcon icon(":/icons/check.ico"); //图标
    bool isEditable = ui->ckbEditable->isChecked(); //是否可编辑
    QListWidgetItem* item;
    for(int i = 0; i < 10; i++){
        item = new QListWidgetItem(icon,QString("Item %1").arg(i));
        if(isEditable) //可编辑
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsEditable);
        else
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled );

        ui->listWidget->addItem(item);
    }
}

//插入项
void MainWindow::on_actItemInsert_triggered()
{
    QIcon icon(":/icons/check.ico"); //图标
    bool isEditable = ui->ckbEditable->isChecked(); //是否可编辑
    QListWidgetItem* item = new QListWidgetItem(icon,"New Insert Item");
    if(isEditable) //可编辑
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsEditable);
    else
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled );

    ui->listWidget->insertItem(ui->listWidget->currentRow(),item);

}

//添加项
void MainWindow::on_actItemAppend_triggered()
{
    QIcon icon(":/icons/check.ico"); //图标
    bool isEditable = ui->ckbEditable->isChecked(); //是否可编辑
    QListWidgetItem* item = new QListWidgetItem(icon,"New Insert Item");
    if(isEditable) //可编辑
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsEditable);
    else
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled );

    ui->listWidget->addItem(item);
}

//删除当前项
void MainWindow::on_actItemDelete_triggered()
{
    QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());//删除控件中的item
    delete item;//删除内存中的item
}

//清除列表
void MainWindow::on_actListClear_triggered()
{
    ui->listWidget->clear();
}

//全选
void MainWindow::on_actSelAll_triggered()
{
    int cnt = ui->listWidget->count();
    QListWidgetItem* item;
    for(int i = 0; i < cnt; i++){
        item = ui->listWidget->item(i);//获取一个item
        item->setCheckState(Qt::Checked);//设置为选中项
    }
}

//全不选
void MainWindow::on_actSelNone_triggered()
{
    int cnt = ui->listWidget->count();//项的数量
    QListWidgetItem* item;
    for(int i = 0; i < cnt; i++){
        item = ui->listWidget->item(i);//获取一个item
        item->setCheckState(Qt::Unchecked);//取消选中项
    }
}

//反选
void MainWindow::on_actSellnvs_triggered()
{
    int cnt = ui->listWidget->count();
    QListWidgetItem* item;
    for(int i = 0; i < cnt; i++){
        item = ui->listWidget->item(i);//获取一个item
        if(item->checkState() == Qt::Checked)
            item->setCheckState(Qt::Unchecked);
        else
            item->setCheckState(Qt::Checked);
    }
}

//QListWidget当前项发生变化时
void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    QString str;
    if(current != NULL){
        if(previous == NULL)
            str = "当前项：" + current->text();
        else
            str = "前一项：" + previous->text() + ", 当前项：" + current->text();
    }
    ui->editCurItem->setText(str);
}

//可编辑
void MainWindow::on_ckbEditable_clicked(bool checked)
{
    QListWidgetItem* item;
    int cnt = ui->listWidget->count();//获取项的数量
    for(int i = 0; i < cnt; i++){
        item = ui->listWidget->item(i); //获取一个项
        if(checked)
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsEditable);
         else
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled );
    }

}

//创建并显示右键菜单
void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    //先改ui中的QListWidge的属性ContextMenuPolicy属性为customContextMenu
    //创建菜单
    QMenu*  menu = new QMenu;
    //添加菜单项
    menu->addAction(ui->actListInit);
    menu->addAction(ui->actListClear);
    menu->addSeparator();
    menu->addAction(ui->actItemInsert);
    menu->addAction(ui->actItemAppend);
    menu->addAction(ui->actItemDelete);
    menu->addSeparator();
    menu->addAction(ui->actSelAll);
    menu->addAction(ui->actSelNone);
    menu->addAction(ui->actSellnvs);
    menu->addSeparator();
    //显示菜单
    menu->exec(QCursor::pos());

    delete menu;

}

//实现QTabWidget和QToolBox的联动
//QTabWidget::currentChanged(int)信号
void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->toolBox->setCurrentIndex(index);
}

//QToolBox::currentChanged(int)信号
void MainWindow::on_toolBox_currentChanged(int index)
{
    ui->tabWidget->setCurrentIndex(index);
}

