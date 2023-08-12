#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUi();
    //信号和槽函数的连接
    connect(spinFontSize,SIGNAL(valueChanged(int)),this,SLOT(on_spinFontSize_valueChanged(int)));
    connect(fontCmb,SIGNAL(currentIndexChanged(int)),this,SLOT(on_fontCmb_currentIndexChanged(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//代码方式初始化界面
void MainWindow::initUi(){
    //状态栏上添加控件
    labelCurFile = new QLabel;
    labelCurFile->setText("当前文件：");
    labelCurFile->setMinimumWidth(300);
    ui->statusbar->addWidget(labelCurFile); //添加到状态栏

    //工具栏上添加控件
    ui->toolBar->addWidget(new QLabel("   字体大小："));

    spinFontSize = new QSpinBox;
    spinFontSize->setMinimumWidth(50);
    spinFontSize->setRange(8,48);
    spinFontSize->setValue(ui->textEdit->font().pointSize());//将textEidt的字体大小作为spinFontSize的当前值
    ui->toolBar->addWidget(spinFontSize);

    ui->toolBar->addWidget(new QLabel("   字体："));

    fontCmb = new QFontComboBox;
    fontCmb->setMinimumWidth(150);
    ui->toolBar->addWidget(fontCmb);

    //设置中心控件
    setCentralWidget(ui->textEdit);
}


void MainWindow::on_actFontBold_toggled(bool arg1)
{
}


//粗体
void MainWindow::on_actFontBold_triggered(bool checked)
{
    QTextCharFormat fmt;
    if(checked){
        fmt.setFontWeight(QFont::Bold);
    }else{
        fmt.setFontWeight(QFont::Normal);
    }
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

//斜体
void MainWindow::on_actFontItalic_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt.setFontItalic(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

//下划线
void MainWindow::on_actFontUnderline_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

//更新粗体、斜体、下划线 三个QAction的checked的属性
void MainWindow::on_textEdit_selectionChanged()
{
    //粗体、斜体、下划线 三个按钮选中状态，随着选择的翁
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();//获取当前选中文本的格式
    ui->actFontBold->setChecked(fmt.font().bold());//当前选中文本的格式，如果是粗体，就设置按钮是选中状态；如果不是粗体，按钮就不是选中状态
    ui->actFontItalic->setChecked(fmt.fontItalic());
    ui->actFontUnderline->setChecked(fmt.fontUnderline());
}

//更新剪切、复制、粘贴的enabled的属性
void MainWindow::on_textEdit_copyAvailable(bool b)
{
    //要选中文本，才能剪切、复制、粘贴
    ui->actCut->setEnabled(b);
    ui->actCopy->setEnabled(b);
    ui->actPaste->setEnabled(ui->textEdit->canPaste());
}

//设置字体大小
void MainWindow::on_spinFontSize_valueChanged(int fontSize){
    QTextCharFormat fmt;
    fmt.setFontPointSize(fontSize);
    ui->textEdit->mergeCurrentCharFormat(fmt);

}
//选择字体类型
void MainWindow::on_fontCmb_currentIndexChanged(const QString& fontFamily){
    QTextCharFormat fmt;
    fmt.setFontFamily(fontFamily);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

//显示工具栏文字标签
//方式一：可以通过代码方式。方式二：通过ui设置工具栏的属性toolButtonStyle
void MainWindow::on_actToolbarLab_triggered(bool checked)
{
    if(checked)
        ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    else
        ui->toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);

}

