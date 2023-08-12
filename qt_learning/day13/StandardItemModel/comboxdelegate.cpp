#include "comboxdelegate.h"
#include <QComboBox>

ComboxDelegate::ComboxDelegate()
{

}

//创建代理编辑控件
QWidget* ComboxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const{
   QComboBox* editor = new QComboBox(parent);
   Q_UNUSED(option)
   Q_UNUSED(index)
   editor->addItem("男");
   editor->addItem("女");
   return editor;
}

//从数据模型获取数据，显示到代理控件中
void ComboxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const{
    QComboBox* cmbBox = static_cast<QComboBox*>(editor);
    QString str = index.model()->data(index,Qt::EditRole).toString();
    cmbBox->setCurrentText(str);

}
//将代理空的数据保存到数据模型中
void ComboxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const{
    QComboBox* cmbBox = static_cast<QComboBox*>(editor);
    QString str = cmbBox->currentText();
    model->setData(index,str,Qt::EditRole);
}
//设置代理控件的大小
void ComboxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    Q_UNUSED(index)
    editor->setGeometry(option.rect);
}
