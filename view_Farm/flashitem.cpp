#include "flashitem.h"

FlashItem::FlashItem(QObject *parent) : QObject(parent)
{
    flash = true;
    setFlag(ItemIsMovable);
    startTimer(100);
}

QRectF FlashItem::boundingRect() const
{
    qreal adjust=2;
    return QRectF(-10-adjust,-10-adjust,
                  43+adjust,43+adjust);

}

void FlashItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setPen(Qt::NoPen);
    painter->setPen(Qt::NoPen);
    painter->setPen(Qt::NoPen);

    painter->setBrush(flash?(Qt::red):(Qt::yellow));
    painter->drawEllipse(-10,-10,40,40);
}

void FlashItem::timerEvent(QTimerEvent *)
{
    flash=!flash;
    update();
}
