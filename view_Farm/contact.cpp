#include "contact.h"
#include "baseinfo.h"
#include "mainwindow.h"
Contact::Contact(QWidget *parent) : QWidget(parent)
{
    EmailLabel=new QLabel(tr("空气温湿度传感器（2）: "));
    EmailLineEdit=new QLineEdit;


    AddrLabel = new QLabel(tr("光照传感器（2）: "));
    AddrLineEdit = new QLineEdit;


    CodeLabel=new QLabel(tr("PM2.5传感器（1）: "));
    CodeLineEdit= new QLineEdit;


    MoviTelLabel=new QLabel(tr("土壤温湿度传感器（10）: "));
    MoviTelLineEdit=new QLineEdit;
    MoviTelCheckBook=new QCheckBox(tr("全选"));

    ProTelLabel=new QLabel(tr("驱鸟器（2）： "));
    ProTelLineEdit=new QLineEdit;


    mainLayout=new QGridLayout(this);
   // mainLayout->setMargin(15);
    //mainLayout->setSpacing(10);

    NameIconLabelx = new QLabel;
    QPixmap icon6("监控.png");
    NameIconLabelx->setPixmap(icon6);

    mainLayout->addWidget(NameIconLabelx,9,1);



    mainLayout->addWidget(EmailLabel,0,0);
    mainLayout->addWidget(EmailLineEdit,0,1);

    mainLayout->addWidget(AddrLabel,1,0);
    mainLayout->addWidget(AddrLineEdit,1,1);

    mainLayout->addWidget(CodeLabel,2,0);
    mainLayout->addWidget(CodeLineEdit,2,1);

    mainLayout->addWidget(MoviTelLabel,3,0);
    mainLayout->addWidget(MoviTelLineEdit,3,1);
    mainLayout->addWidget(MoviTelCheckBook,3,2);

    mainLayout->addWidget(ProTelLabel,4,0);
    mainLayout->addWidget(ProTelLineEdit,4,1);

    mainLayout->addWidget(ProTelLabel,5,0);
    mainLayout->addWidget(ProTelLineEdit,5,1);

    mainLayout->addWidget(ProTelLabel,6,0);
    mainLayout->addWidget(ProTelLineEdit,6,1);

    mainLayout->addWidget(ProTelLabel,7,0);
    mainLayout->addWidget(ProTelLineEdit,7,1);

    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

}
