#include "labeldelegate.h"
#include <QComboBox>

#include <cstring>
#include "mainwindow.h"

#include <datedelegate.h>
#include <QApplication>

#include <QStandardItemModel>
#include <QTableView>
#include <QFile>
#include <QTextStream>

#include "spindelegate.h"
#include <QSpinBox>

#include <QDateTimeEdit>
labeldelegate::labeldelegate(QObject *parent):QItemDelegate(parent)
{

}
//型号

QWidget *labeldelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *editor=new QComboBox(parent);

        editor->addItem("农场");
        editor->addItem("大棚");



    editor->installEventFilter(const_cast<labeldelegate*>(this));
    return editor;

}

void labeldelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString str=index.model()->data(index).toString();

    QComboBox *box=static_cast<QComboBox*>(editor);

    int i=box->findText(str);
    box->setCurrentIndex(i);
}

void labeldelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *box=static_cast<QComboBox*>(editor);
    QString str=box->currentText();
    model->setData(index,str);
}


void labeldelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
