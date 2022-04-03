#include "combodelegate.h"
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
#include "combodelegate.h"
#include <labeldelegate.h>
ComboDelegate::ComboDelegate(QObject *parent):QItemDelegate(parent)
{

}
//型号
int mode=0;
QWidget *ComboDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *editor=new QComboBox(parent);
    if(1==index.column())
    {
        editor->addItem("空气温湿度传感器");
        editor->addItem("光照传感器");
        editor->addItem("PM2.5传感器");
        editor->addItem("土壤温湿度传感器");

        editor->addItem("土壤酸碱度传感器");
        editor->addItem("风速传感器");
        editor->addItem("风向传感器");
        editor->addItem("雨量传感器");

        editor->addItem("驱鸟器");
    }
    else
    {
        switch (mode) {
            case 0:
                editor->addItem("℃");
            break;
            case 1:
                editor->addItem("Lux");
                break;
            case 2:
                editor->addItem("ug/m3");
                break;
            case 3:
                editor->addItem("温度:℃ 湿度：RH");
            break;
            case 4:
                editor->addItem("PH");
            break;
            case 5:
                editor->addItem("m/s");
                break;
            case 6:
                editor->addItem("℃ 北方是零度，度数按顺时针递增");
                break;
            case 7:
                editor->addItem("mm/min");
                break;
           /* default:
                editor->addItem("null");
            break;*/
        }

    }



    editor->installEventFilter(const_cast<ComboDelegate*>(this));
    return editor;
}

void ComboDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString str=index.model()->data(index).toString();

    if(str=="空气温湿度传感器")
    {
        mode=0;
    }
    if(str=="光照传感器")
    {
        mode=1;
    }
    if(str=="PM2.5传感器")
    {
        mode=2;
    }
    if(str=="土壤温湿度传感器")
    {
        mode=3;
    }
    if(str=="土壤酸碱度传感器")
    {
        mode=4;
    }
    if(str=="风速传感器")
    {
        mode=5;
    }
    if(str=="风向传感器")
    {
        mode=6;
    }
    if(str=="雨量传感器")
    {
        mode=7;
    }/*
    else
    {
        mode=-1;
    }*/
    QComboBox *box=static_cast<QComboBox*>(editor);

    int i=box->findText(str);
    box->setCurrentIndex(i);
}

void ComboDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *box=static_cast<QComboBox*>(editor);
    QString str=box->currentText();
    model->setData(index,str);
}

void ComboDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
