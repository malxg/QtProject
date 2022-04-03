#ifndef LABELDELEGATE_H
#define LABELDELEGATE_H

#include <QItemDelegate>
class labeldelegate:public QItemDelegate
{
    Q_OBJECT;
public:
    labeldelegate(QObject *parent=0);
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QWidget * createEditor2(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
#endif // LABELDELEGATE_H
