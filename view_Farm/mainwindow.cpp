#include "mainwindow.h"

#include "flashitem.h"
#include <startitem.h>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <stdio.h>
#include <string.h>
int i=1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createMenus();

    scene = new QGraphicsScene;
    scene->setSceneRect(-200,-200,400,400);
    initScene();
    QGraphicsView *view=new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400,400);
    view->show();
    setCentralWidget(view);
    resize(550,450);
    setWindowTitle(tr("Graphics Items"));
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
    newAct=new QAction(tr("new"),this);
    clearAct=new QAction(tr("clear"),this);
    exitAct=new QAction(tr("exit"),this);

    addEllipseItemAct=new QAction(tr("add Ellipse"),this);
    addPolygonItemAct=new QAction(tr("add Polygon"),this);
    addTextItemAct=new QAction(tr("add Text"),this);
    addRectItemAct=new QAction(tr("add Rect"),this);

    addAlphaItemAct=new QAction(tr("add Alpha"),this);

    addFlashItemAct=new QAction(tr("add flash"),this);

    addAnimItemAct=new QAction(tr("take Anim"),this);

    connect(addAnimItemAct,SIGNAL(triggered()),this,SLOT(slotAddAnimationItem()));

    connect(addFlashItemAct,SIGNAL(triggered()),this,SLOT(slotAddFlashItem()));

    connect(newAct,SIGNAL(triggered()),this,SLOT(slotNew()));
    connect(clearAct,SIGNAL(triggered()),this,SLOT(slotClear()));
    connect(exitAct,SIGNAL(triggered()),this,SLOT(close()));

    connect(addEllipseItemAct,SIGNAL(triggered()),this,SLOT(slotAddEllipseItem()));

    connect(addTextItemAct,SIGNAL(triggered()),this,SLOT(slotAddTextItem()));
   connect(addPolygonItemAct,SIGNAL(triggered()),this,SLOT(slotAddPolygonItem()));
   connect(addRectItemAct,SIGNAL(triggered()),this,SLOT(slotAddRectItem()));
   connect(addAlphaItemAct,SIGNAL(triggered()),this,SLOT(slotAddAlphaItem()));
}

void MainWindow::createMenus()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("file"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(clearAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
    QMenu *itemsMenu=menuBar()->addMenu(tr("items"));
    itemsMenu->addAction(addEllipseItemAct);
    itemsMenu->addAction(addPolygonItemAct);
    itemsMenu->addAction(addTextItemAct);
    itemsMenu->addAction(addRectItemAct);
    itemsMenu->addAction(addAlphaItemAct);

    itemsMenu->addAction(addFlashItemAct);

    itemsMenu->addAction(addAnimItemAct);
}

void MainWindow::initScene()
{
    int i;
    /*for(i=0;i<3;i++)
    {
        slotAddEllipseItem();
    }

    for(i=0;i<3;i++)
    {
        slotAddPolygonItem();
    }
    for(i=0;i<3;i++)
    {
        slotAddTextItem();
    }
    for(i=0;i<3;i++)
    {
        slotAddRectItem();
    }*/
    for(i=0;i<11;i++)
    {
        slotAddAlphaItem();
    }
/*
    for(i=0;i<3;i++)
    {
        slotAddFlashItem();
    }

    for(i=0;i<3;i++)
    {
        slotAddAnimationItem();
    }*/
}

void MainWindow::slotNew()
{
    slotClear();
    initScene();
    MainWindow *newWin=new MainWindow;
    newWin->show();
}

void MainWindow::slotClear()
{
    QList<QGraphicsItem*> listItem=scene->items();
    while(!listItem.empty())
    {
        scene->removeItem(listItem.at(0));
        listItem.removeAt(0);
    }
}

void MainWindow::slotAddEllipseItem()
{
    QGraphicsEllipseItem *item=new QGraphicsEllipseItem(QRectF(0,0,80,60));
    item->setPen(Qt::NoPen);
    item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,(qrand()%int(scene->sceneRect().height()))-200);

}

void MainWindow::slotAddPolygonItem()
{
    QVector<QPoint> v;
    v<<QPoint(30,-15)<<QPoint(0,30)<<QPoint(-30,-15)<<
       QPoint(-30,15)<<QPoint(0,30)<<QPoint(30,15);

    QGraphicsPolygonItem *item=new QGraphicsPolygonItem(QPolygonF(v));

    item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);

}

void MainWindow::slotAddTextItem()
{
    QFont font("Times",16);
    QGraphicsTextItem *item=new QGraphicsTextItem("双状态控制设备");
    item->setFont(font);
    item->setFlag(QGraphicsItem::ItemIsMovable);

    item->setDefaultTextColor(QColor(qrand()%256,qrand()%256,qrand()%256));
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);

}

void MainWindow::slotAddRectItem()
{


    QGraphicsRectItem *item=new QGraphicsRectItem(QRectF(0,0,60,60));
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setPen(pen);

    item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);

}

void MainWindow::slotAddAlphaItem()
{
    QGraphicsPixmapItem *item;
    switch (i) {
        case 1:item=scene->addPixmap(QPixmap("1.png"));break;
        case 2:item=scene->addPixmap(QPixmap("2.png"));break;
        case 3:item=scene->addPixmap(QPixmap("3.png"));break;
        case 4:item=scene->addPixmap(QPixmap("4.png"));break;
        case 5:item=scene->addPixmap(QPixmap("5.png"));break;
        case 6:item=scene->addPixmap(QPixmap("驱鸟器.png"));break;
        case 7:item=scene->addPixmap(QPixmap("光照.png"));break;
        case 8:item=scene->addPixmap(QPixmap("土壤水分.png"));break;
        case 9:item=scene->addPixmap(QPixmap("土壤酸碱.png"));break;
        case 10:item=scene->addPixmap(QPixmap("空气温湿度.png"));break;
        case 11:item=scene->addPixmap(QPixmap("驱鸟器.png"));break;
    }
    i++;

    item->setFlag(QGraphicsItem::ItemIsMovable);

    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);

}

void MainWindow::slotAddFlashItem()
{
    FlashItem *item=new FlashItem;

    scene->addItem(item);

    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);

}

void MainWindow::slotAddAnimationItem()
{
    StartItem *item=new StartItem;
    QGraphicsItemAnimation *anim= new QGraphicsItemAnimation;
    anim->setItem(item);
    QTimeLine *timeLine=new QTimeLine(4000);
    timeLine->setCurveShape(QTimeLine::SineCurve);
    timeLine->setLoopCount(0);
    anim->setTimeLine(timeLine);

    int y=(qrand()%400)-200;
    for(int i=0;i<400;i++)
    {
        anim->setPosAt(i/400.0,QPoint(i-200,y));

    }
    timeLine->start();

    scene->addItem(item);

}
