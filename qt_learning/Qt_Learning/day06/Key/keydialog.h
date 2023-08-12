#ifndef KEYDIALOG_H
#define KEYDIALOG_H

#include <QDialog>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class KeyDialog; }
QT_END_NAMESPACE

class KeyDialog : public QDialog
{
    Q_OBJECT

public:
    KeyDialog(QWidget *parent = nullptr);
    ~KeyDialog();

protected:
   void keyPressEvent(QKeyEvent *event);

private:
    Ui::KeyDialog *ui;
};
#endif // KEYDIALOG_H
