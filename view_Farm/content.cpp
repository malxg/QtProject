#include "content.h"


Content::Content(QWidget *parent) : QFrame(parent)

{
    stack=new QStackedWidget(this);
    stack->setFrameStyle(QFrame::Panel|QFrame::Raised);
    /*3个页面*/
    baseInfo = new BaseInfo();
    contact = new Contact();
    detail = new Detail();

    stack->addWidget(baseInfo);
    stack->addWidget(contact);
    stack->addWidget(detail);
    //stack->addWidget(mainwindow);
    /*2个按钮*/
    AmendBtn =new QPushButton(tr("amend"));
    CloseBtn =new QPushButton(tr("close"));
    QHBoxLayout *BtnLayout =new QHBoxLayout;

    BtnLayout->addStretch(1);
    BtnLayout->addWidget(AmendBtn);
    BtnLayout->addWidget(CloseBtn);
    /*整体布局*/
    QVBoxLayout *RightLayout =new QVBoxLayout(this);

   // RightLayout->setMargin(10);
    //RightLayout->setSpacing(6);
    RightLayout->addWidget(stack);
    RightLayout->addLayout(BtnLayout);
}

Content::~Content()
{

}
