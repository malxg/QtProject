#include "mainwindow.h"
#include<QPainter>
#include<QMouseEvent>
#include <datedelegate.h>
#include <QApplication>

#include <QStandardItemModel>
#include <QTableView>
#include <QFile>
#include <QTextStream>

#include "spindelegate.h"
#include "combodelegate.h"
#include <labeldelegate.h>
#include "mytableview.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QStandardItemModel model(9,7);
    QTableView tableView;
    tableView.setModel(&model);//////////////

    SpinDelegate spinDelegate2;
    tableView.setItemDelegateForColumn(0,&spinDelegate2);//从 0下标开始


    ComboDelegate comboDelegate;
    tableView.setItemDelegateForColumn(1,&comboDelegate);

    labeldelegate labeldelegate;
    tableView.setItemDelegateForColumn(3,&labeldelegate);

    tableView.setItemDelegateForColumn(4,&comboDelegate);

    DateDelegate dateDelegate;
    tableView.setItemDelegateForColumn(5,&dateDelegate);

    MyItemDelegate myItemDelegate;
    tableView.setItemDelegateForColumn(6,&myItemDelegate);

    model.setHeaderData(0,Qt::Horizontal,QObject::tr("序号"));//从 0 下标开始
    model.setHeaderData(1,Qt::Horizontal,QObject::tr("型号"));
    model.setHeaderData(2,Qt::Horizontal,QObject::tr("ID"));
    model.setHeaderData(3,Qt::Horizontal,QObject::tr("安装位置"));
    model.setHeaderData(4,Qt::Horizontal,QObject::tr("单位"));
    model.setHeaderData(5,Qt::Horizontal,QObject::tr("安装时间"));
    model.setHeaderData(6,Qt::Horizontal,QObject::tr("传感器图片"));

    QFile file("text.txt");
    if(file.open(QFile::ReadOnly|QFile::Text))
    {
        QTextStream stream(&file);
        QString line;
        model.removeRows(0,model.rowCount(QModelIndex()),QModelIndex());
        int row=0;
        do
        {
            line=stream.readLine();
            if(!line.isEmpty())
            {
                model.insertRows(row,1,QModelIndex());
                QStringList pieces=line.split(",",QString::SkipEmptyParts);
                model.setData(model.index(row,0,QModelIndex()),pieces.value(0));
                model.setData(model.index(row,1,QModelIndex()),pieces.value(1));
                model.setData(model.index(row,2,QModelIndex()),pieces.value(2));
                model.setData(model.index(row,3,QModelIndex()),pieces.value(3));
                row++;
            }
        }while(!line.isEmpty());
        file.close();
    }
    tableView.setWindowTitle(QObject::tr("农场传感器页面"));

    tableView.show();

    MyTableView table;
    table.show();
    return app.exec();
}
