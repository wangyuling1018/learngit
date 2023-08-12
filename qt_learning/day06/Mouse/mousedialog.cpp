#include "mousedialog.h"
#include "ui_mousedialog.h"

MouseDialog::MouseDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MouseDialog)
{
    ui->setupUi(this);
    m_drag = false;
}

MouseDialog::~MouseDialog()
{
    delete ui;
}

// 鼠标移动事件处理函数
void MouseDialog::mouseMoveEvent(QMouseEvent *event){
    //计算label要移动的位置
    QPoint newPos = event->pos() - m_pos;

    QSize s1 = size();//窗口的大小（宽、高）
    QSize s2 = ui->label->size(); //label的大小

    //限制label只能在窗口中移动，不同拖到窗口外面
    // x:  0 ~ 窗口宽 - label宽
    if(newPos.x() < 0)
        newPos.setX(0);
    else if(newPos.x() > s1.width() - s2.width())
        newPos.setX(s1.width() - s2.width());
    // y:  0 ~ 窗口高 - label高
    if(newPos.y() < 0)
        newPos.setY(0);
    else if(newPos.y() > s1.height() -s2.height())
        newPos.setY(s1.height() - s2.height());

    //移动label
    ui->label->move(newPos);
}

// 鼠标按下事件处理函数
void MouseDialog::mousePressEvent(QMouseEvent *event){
    // 是否是左键
    if(event->button() == Qt::LeftButton){
        // 获取label所在区域
        QRect rect = ui->label->frameRect();
        // 坐标系平移
        rect.translate(ui->label->pos()); // 转换为以父窗口左上角为(0,0)的坐标
        // 判断鼠标是否点击在label内
        if(rect.contains(event->pos())){
            m_drag = true;
            m_pos = event->pos() - ui->label->pos();   // 保存鼠标坐标和label左上角坐标的差值
        }
    }
}

// 鼠标释放事件处理函数
void MouseDialog::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        m_drag = false;
    }
}
