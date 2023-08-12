#include "keydialog.h"
#include "ui_keydialog.h"

KeyDialog::KeyDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::KeyDialog)
{
    ui->setupUi(this);
}

KeyDialog::~KeyDialog()
{
    delete ui;
}

void KeyDialog::keyPressEvent(QKeyEvent *event){
    int x = ui->label->pos().x();
    int y = ui->label->pos().y();

    switch(event->key()){
        case Qt::Key_Left:
            x -= 10; break;
        case Qt::Key_Up:
            y -= 10; break;
        case Qt::Key_Right:
            x += 10; break;
        case Qt::Key_Down:
            y += 10; break;
    }

    //不用记录label的相对位置，因为跟鼠标没有关系
    QSize s1 = size();
    QSize s2 = ui->label->size();
    if(x < 0)
        x = 0;
    else if(x > s1.width() - s2.width())
        y = s1.width() - s2.width();

    if(y < 0)
        y = 0;
    else if(y > s1.height() - s2.height())
        y = s1.height() - s2.height();


    ui->label->move(x,y);

}
