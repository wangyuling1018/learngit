#ifndef MOUSEDIALOG_H
#define MOUSEDIALOG_H

#include <QDialog>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MouseDialog; }
QT_END_NAMESPACE

class MouseDialog : public QDialog
{
    Q_OBJECT

public:
    MouseDialog(QWidget *parent = nullptr);
    ~MouseDialog();
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::MouseDialog *ui;
    QPoint m_pos;     // 记录label左上角坐标和鼠标坐标的差值
    bool m_drag;      // 是否可以拖拽
};
#endif // MOUSEDIALOG_H
