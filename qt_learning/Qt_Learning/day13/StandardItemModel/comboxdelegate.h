#ifndef COMBOXDELEGATE_H
#define COMBOXDELEGATE_H

#include <QStyledItemDelegate>

class ComboxDelegate : public QStyledItemDelegate
{
public:
    ComboxDelegate();
    // 自定义代理类必须重写以下4个函数
    // 创建代理编辑控件
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    // 设置代理编辑控件的数据
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    // 设置数据模型的数据
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    // 设置代理编辑控件的大小
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};

#endif // COMBOXDELEGATE_H
