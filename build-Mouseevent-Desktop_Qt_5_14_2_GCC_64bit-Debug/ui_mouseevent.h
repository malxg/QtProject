/********************************************************************************
** Form generated from reading UI file 'mouseevent.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOUSEEVENT_H
#define UI_MOUSEEVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mouseevent
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Mouseevent)
    {
        if (Mouseevent->objectName().isEmpty())
            Mouseevent->setObjectName(QString::fromUtf8("Mouseevent"));
        Mouseevent->resize(800, 600);
        centralwidget = new QWidget(Mouseevent);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 90, 67, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(300, 120, 67, 17));
        Mouseevent->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Mouseevent);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Mouseevent->setMenuBar(menubar);
        statusbar = new QStatusBar(Mouseevent);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Mouseevent->setStatusBar(statusbar);

        retranslateUi(Mouseevent);

        QMetaObject::connectSlotsByName(Mouseevent);
    } // setupUi

    void retranslateUi(QMainWindow *Mouseevent)
    {
        Mouseevent->setWindowTitle(QCoreApplication::translate("Mouseevent", "Mouseevent", nullptr));
        label->setText(QCoreApplication::translate("Mouseevent", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Mouseevent", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mouseevent: public Ui_Mouseevent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOUSEEVENT_H
