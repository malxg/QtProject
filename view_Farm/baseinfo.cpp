#include "baseinfo.h"
#include "mainwindow.h"
BaseInfo::BaseInfo(QWidget *parent) : QWidget(parent)
{
    /*左侧*/
    //UserNameLabel = new QLabel(tr("室外空气温湿度: "));
    UserNameLineEdit = new QLineEdit;
    UserNameIconLabel = new QLabel;
    QPixmap icon1("1.png");
    UserNameIconLabel->setPixmap(icon1);
    UserNameIconLabel->resize(icon1.width(),icon1.height());

    NameLabel=new QLabel(tr("室外土壤温湿度: "));
    //NameLineEdit = new QLineEdit;
    NameIconLabel = new QLabel;
    QPixmap icon2("2.png");
    NameIconLabel->setPixmap(icon2);

    NameIconLabel1 = new QLabel;
    QPixmap icon6("驱鸟器.png");
    NameIconLabel1->setPixmap(icon6);

    NameIconLabel2 = new QLabel;
    QPixmap icon7("光照.png");
    NameIconLabel2->setPixmap(icon7);

    NameIconLabel3 = new QLabel;
    QPixmap icon8("土壤水份.png");
    NameIconLabel3->setPixmap(icon8);

    NameIconLabel4 = new QLabel;
    QPixmap icon9("土壤酸碱.png");
    NameIconLabel4->setPixmap(icon9);

    NameIconLabel5 = new QLabel;
    QPixmap icon10("空气温湿度.png");
    NameIconLabel5->setPixmap(icon10);
/*
    SexLabel = new QLabel(tr("sex: "));
    SexComboBox = new QComboBox;
    SexComboBox->addItem(tr("female"));
    SexComboBox->addItem(tr("male"));

    DepartmentLabel = new QLabel(tr("department: "));
    DepartmentTextEdit = new QTextEdit;

    AgeLabel = new QLabel(tr("age: "));
    AgeLineEdit = new QLineEdit;

    OtherLabel= new QLabel(tr("remark: "));
    OtherLabel->setFrameStyle(QFrame::Panel|QFrame::Sunken);
*/
    LeftLayout = new QGridLayout();

  //  LeftLayout->addWidget(UserNameLabel,0,3);
    LeftLayout->addWidget(UserNameIconLabel,0,4);
   // LeftLayout->addWidget(NameLabel,1,3);
    LeftLayout->addWidget(NameIconLabel,1,4);

    LeftLayout->addWidget(NameIconLabel1,0,3);
    LeftLayout->addWidget(NameIconLabel2,1,3);
    LeftLayout->addWidget(NameIconLabel3,2,3);
    LeftLayout->addWidget(NameIconLabel4,3,3);


    /*LeftLayout->addWidget(SexLabel,2,0);
    LeftLayout->addWidget(SexComboBox,2,1);
    LeftLayout->addWidget(DepartmentLabel,3,0);
    LeftLayout->addWidget(DepartmentTextEdit,3,1);

    LeftLayout->addWidget(AgeLabel,4,0);
    LeftLayout->addWidget(AgeLineEdit,4,1);
    LeftLayout->addWidget(OtherLabel,5,0,1,2);*/
    LeftLayout->setColumnStretch(0,1);

    //LeftLayout->addWidget(UserNameLabel,1,3);

    /*Right*/
   // HeadLabel = new QLabel(tr("锦城智能物联农场实时监控: "));
    HeadIconLabel = new QLabel;
    QPixmap icon("4.png");
    HeadIconLabel->setPixmap(icon);
    HeadIconLabel->resize(icon.width(),icon.height());
    //UpdateHeadBtn = new QPushButton(tr("Update: "));

    HeadIconLabel2 = new QLabel;
    QPixmap icon5("5.png");
    HeadIconLabel2->setPixmap(icon5);
    HeadIconLabel2->resize(icon5.width(),icon5.height());

    TopRightLyout= new QHBoxLayout();
    //TopRightLyout->setSpacing(20);
    //TopRightLyout->addWidget(HeadLabel);
    TopRightLyout->addWidget(HeadIconLabel);
    TopRightLyout->addWidget(HeadIconLabel2);

    IntroductionLabel = new QLabel(tr("传感器： "));
    //IntroductionTextEdit = new QTextEdit;
    IntroductionIconLabel = new QLabel;
    QPixmap icon3("3.png");
    IntroductionIconLabel->setPixmap(icon3);
    IntroductionIconLabel->resize(icon3.width(),icon3.height());
    UpdateHeadBtn = new QPushButton(tr("Update: "));

    RightLayout=new QVBoxLayout();
    //RightLayout->setMargin(10);
    RightLayout->addLayout(TopRightLyout);
    RightLayout->addWidget(IntroductionLabel);
    //RightLayout->addWidget(IntroductionTextEdit);
    RightLayout->addWidget(IntroductionIconLabel);

    /************************************************/
    QGridLayout *mainLayout = new QGridLayout(this);
    //mainLayout->setMargin(15);
    //mainLayout->setSpacing(10);
    mainLayout->addLayout(LeftLayout,0,0);
    mainLayout->addLayout(RightLayout,0,1);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);



}
