#include "detail.h"

Detail::Detail(QWidget *parent) : QWidget(parent)
{
    NationalLabel=new QLabel(tr("种植作物: "));
    NationalComboBox=new QComboBox;
    NationalComboBox->insertItem(0,tr("玉米"));
    NationalComboBox->insertItem(1,tr("向日葵"));
    NationalComboBox->insertItem(2,tr("菠菜"));
    ProvinceLabel=new QLabel(tr("种植地点: "));

    ProvinceComboBox=new QComboBox;
    ProvinceComboBox->insertItem(0,tr("大棚"));
    ProvinceComboBox->insertItem(1,tr("农场"));
    ProvinceComboBox->insertItem(2,tr("农场和大棚"));
    CityLabel=new QLabel(tr("种植时间: "));

    CityLineEdit=new QLineEdit;
    IntroductLabel=new QLabel(tr("种植备忘录: "));
    IntroductTextEdit=new QTextEdit;

    NameIconLabely = new QLabel;
    QPixmap icon6("大棚控制器.png");
    NameIconLabely->setPixmap(icon6);

    mainLayout=new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);

    mainLayout->addWidget(NationalLabel,0,0);
    mainLayout->addWidget(NationalComboBox,0,1);

    mainLayout->addWidget(ProvinceLabel,1,0);
    mainLayout->addWidget(ProvinceComboBox,1,1);

    mainLayout->addWidget(CityLabel,2,0);
    mainLayout->addWidget(CityLineEdit,2,1);

    mainLayout->addWidget(IntroductLabel,3,0);
    mainLayout->addWidget(IntroductTextEdit,3,1);

    mainLayout->addWidget(NameIconLabely,4,1);

}
