#include "comboboxwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ComboBoxWidget w;
    w.show();
    return a.exec();
}
