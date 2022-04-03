#ifndef BASEINFO_H
#define BASEINFO_H
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QTextEdit>
#include<QGridLayout>
#include<QPushButton>

#include <QWidget>

class BaseInfo : public QWidget
{
    Q_OBJECT
public:
    explicit BaseInfo(QWidget *parent = nullptr);

signals:

public slots:
private:
    //Left
    QLabel *UserNameLabel;
    QLabel *UserNameIconLabel;

    QLabel *NameLabel;
    QLabel *NameIconLabel;

    QLabel *NameLabel1;
    QLabel *NameIconLabel1;

    QLabel *NameLabel2;
    QLabel *NameIconLabel2;

    QLabel *NameLabel3;
    QLabel *NameIconLabel3;

    QLabel *NameLabel4;
    QLabel *NameIconLabel4;

    QLabel *NameLabel5;
    QLabel *NameIconLabel5;

    QLabel *SexLabel;
    QLabel *DepartmentLabel;
    QLabel *AgeLabel;
    QLabel *OtherLabel;
    QLineEdit *UserNameLineEdit;
    QLineEdit *NameLineEdit;
    QComboBox *SexComboBox;
    QTextEdit *DepartmentTextEdit;
    QLineEdit *AgeLineEdit;
    QGridLayout *LeftLayout;
    //right
    QLabel *HeadLabel;
    QLabel *HeadIconLabel;
    QLabel *HeadIconLabel2;
    QPushButton *UpdateHeadBtn;
    QHBoxLayout *TopRightLyout;
    QLabel *IntroductionLabel;
    QLabel *IntroductionIconLabel;
    QTextEdit *IntroductionTextEdit;
    QVBoxLayout *RightLayout;
};

#endif // BASEINFO_H
