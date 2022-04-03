#include "content.h"
#include<QTextCodec>
#include<QSplitter>
#include<QListWidget>
#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFont font("AR PL KaitiM GB",12);
    a.setFont(font);
    QSplitter *splitterMain=new QSplitter(Qt::Horizontal,0);
    splitterMain->setOpaqueResize(true);

    QListWidget *list=new QListWidget(splitterMain);

    list->insertItem(0,QObject::tr("监控系统"));
    list->insertItem(1,QObject::tr("控制参数(uint16_t)"));
    list->insertItem(2,QObject::tr("大棚控制器"));
    list->insertItem(3,QObject::tr("1驱鸟器"));
    list->insertItem(4,QObject::tr("2光照传感器"));
    list->insertItem(5,QObject::tr("3土壤水份"));
    list->insertItem(6,QObject::tr("4空气温湿度"));
    list->insertItem(7,QObject::tr("5土壤酸碱"));

    Content *content=new Content(splitterMain);

    QObject::connect(list,SIGNAL(currentRowChanged(int)),content->stack,
                     SLOT(setCurrentIndex(int)));
    splitterMain->setWindowTitle(QObject::tr("锦城智能物联农场实时监控"));

    splitterMain->setMinimumSize(splitterMain->minimumSize());

    splitterMain->setMaximumSize(splitterMain->maximumSize());

    splitterMain->show();

    MainWindow w;
    w.show();

    return a.exec();
}
