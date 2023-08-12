/*
添加右键菜单的步骤：
1. 设置控件的contextMenuPolicy属性的值为Qt::CustomContextMenu
2. 添加各个菜单项对应的QAction，以及QAction关联的槽函数
3. 添加处理信号customContextMenuRequested(const QPoint &pos)的槽函数
    在槽函数中：
     1) 创建菜单  QMenu
     2) 添加QAction   QMenu::addAction()
     3) 显示右键菜单  QMenu::exec()

*/

#include "comboboxwidget.h"
#include "ui_comboboxwidget.h"
#include <QMap>
#include <QTextBlock>
#include <QMenu>
#include <QCursor>

//QPlainTextEdit是纯文本控件，不能给文字加粗等
ComboBoxWidget::ComboBoxWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ComboBoxWidget)
{
    ui->setupUi(this);
}

ComboBoxWidget::~ComboBoxWidget()
{
    delete ui;
}

//初始化列表
void ComboBoxWidget::on_btnListInit_clicked()
{
    ui->cmbSimple->clear();//清除列表项
    QIcon icon(":/icons/unit.ico");
    /*
    //一次添加一个item
    for(int i= 0; i <20; i++){
        ui->cmbSimple->addItem(icon,QString::asprintf("Item %d",i));//有图标
        //ui->cmbSimple->addItem(QString("Item %1").arg(i)); //没有图标
    }
    */

    //一次添加多个item，但是无法添加图标和用户数据
    QStringList strList;
    strList << "北京市" << "上海市" << "天津市" << "重庆市";
    ui->cmbSimple->addItems(strList);

}

//初始化城市+区号
void ComboBoxWidget::on_btnCityZon_clicked()
{
    QMap<QString,int> city_zone;
    city_zone.insert("北京",10);
    city_zone.insert("广州",20);
    city_zone.insert("上海",21);
    city_zone.insert("天津",22);
    city_zone.insert("重庆",23);
    city_zone.insert("沈阳",24);
    city_zone.insert("南京",25);
    city_zone.insert("武汉",27);
    city_zone.insert("成都",28);
    city_zone.insert("西安",29);
    ui->cmbWithUserData->clear();
    for(const QString str : city_zone.keys())
    //foreach (const QString& str, city_zone.keys())
        ui->cmbWithUserData->addItem(str,city_zone.value(str));

}

//简单下拉列表 选项改变时
void ComboBoxWidget::on_cmbSimple_currentTextChanged(const QString &arg1)
{
    ui->plainTextEdit->appendPlainText(arg1);
}

//带有用户数据的下拉列表 选项改变时
void ComboBoxWidget::on_cmbWithUserData_currentTextChanged(const QString &arg1)
{
    QString zone = ui->cmbWithUserData->currentData().toString();//当前项关联的用户数据，QMap<QString,int>中的int
    ui->plainTextEdit->appendPlainText(arg1 + ":" + zone);
}

//可编辑
void ComboBoxWidget::on_ckbEditable_clicked(bool checked)
{
    ui->cmbSimple->setEditable(checked);
}

//清除列表
void ComboBoxWidget::on_btnListClear_clicked()
{
    ui->cmbSimple->clear();
}

//文本框内容添加到ComboBox
void ComboBoxWidget::on_btnTocmb_clicked()
{
    QTextDocument* doc = ui->plainTextEdit->document();//文本文档对象
    int bCnt = doc->blockCount();//获取段落数(回车符就是一个block)
    QIcon icon;
    icon.addFile(":/icons/aim.ico");
    ui->cmbSimple->clear();
    for(int i = 0; i < bCnt; i++){
        QTextBlock textLine = doc->findBlockByNumber(i);//文本中的一段
        QString str = textLine.text();
        ui->cmbSimple->addItem(icon,str);
    }
}


void ComboBoxWidget::on_btnTextClear_clicked(bool checked)
{

}

//清除文本
void ComboBoxWidget::on_btnTextClear_clicked()
{
    ui->plainTextEdit->clear();
}

//Read Only
void ComboBoxWidget::on_ckbReadOnly_clicked(bool checked)
{
    ui->plainTextEdit->setReadOnly(checked);
}

//ContextMenu:右键菜单
//创建并显示右键菜单
void ComboBoxWidget::on_plainTextEdit_customContextMenuRequested(const QPoint &pos)
{
    //创建菜单
    QMenu* menu = new QMenu();
    //添加菜单项
    menu->addAction(ui->actUndo);
    menu->addAction(ui->actRedo);
    menu->addSeparator(); //分割线
    menu->addAction(ui->actCut);
    menu->addAction(ui->actCopy);
    menu->addAction(ui->actPaste);
    menu->addAction(ui->actDelete);
    menu->addSeparator();
    menu->addAction(ui->actSelectAll);


    //显示右键菜单
    menu->exec(QCursor::pos());//不用形参pos，因为这个pos是全局坐标，要用QCursor::pos是鼠标坐标，是当前选中控件的相对位置坐标
    //另外要在ui的中设置plainTextEdit控件的contextMenuPolicy属性，为CustomContextMenu

}



