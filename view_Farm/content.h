#ifndef CONTENT_H
#define CONTENT_H
#include<QStackedWidget>
#include<QPushButton>
#include <QDialog>
#include "baseinfo.h"
#include "contact.h"
#include "detail.h"
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Content; }
QT_END_NAMESPACE

class Content : public QFrame
{
    Q_OBJECT

public:
    Content(QWidget *parent = nullptr);
    ~Content();
    QStackedWidget *stack;
    QPushButton *AmendBtn;
    QPushButton *CloseBtn;
    BaseInfo *baseInfo;
    Contact *contact;
    Detail *detail;
    MainWindow *mainwindow;

private:
    Ui::Content *ui;
};
#endif // CONTENT_H
