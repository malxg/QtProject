#include "mouseevent.h"
#include "ui_mouseevent.h"

Mouseevent::Mouseevent(QWidget *parent)
    : QMainWindow(parent)
   // , ui(new Ui::Mouseevent)
{
    //ui->setupUi(this);
    setWindowTitle(tr("mouse event"));
    statusLabel = new QLabel;
    statusLabel->setText(tr("current location"));
    statusLabel->setFixedWidth(100);
    MousePosLabel=new QLabel;
    MousePosLabel->setText(tr(""));
    MousePosLabel->setFixedWidth(100);
    statusBar()->addPermanentWidget(statusLabel);
    statusBar()->addPermanentWidget(MousePosLabel);
    this->setMouseTracking(true);
    resize(400,200);
}

void Mouseevent::mousePressEvent(QMouseEvent *e)
{
    QString str="("+QString::number(e->x())+","+QString::number(e->y()) +")";
    if(e->button()==Qt::LeftButton)
    {
        statusBar()->showMessage(tr("left")+str);

    }
    else if(e->button()==Qt::RightButton)
    {
        statusBar()->showMessage(tr("right")+str);
    }
    else if(e->button()==Qt::MidButton)
    {
        statusBar()->showMessage(tr("mid")+str);
    }
}
void Mouseevent::mouseMoveEvent(QMouseEvent *e)
{
    MousePosLabel->setText("("+QString::number(e->x())+","+QString::number(e->y())+")");
}
void Mouseevent::mouseReleaseEvent(QMoveEvent *e)
{
    QString str="("+QString::number(e->x())+","+QString::number(e->y())+")");
    statusBar()->showMessage(tr("release in:")+str,3000);

}
void Mouseevent::mouseDoubleClickEvent(Mouseevent */*e*/){}
Mouseevent::~Mouseevent()
{
  //  delete ui;
}

