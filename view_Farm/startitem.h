#ifndef STARTITEM_H
#define STARTITEM_H

#include <QPainter>
#include <QGraphicsItem>
class StartItem : public QGraphicsItem
{
public:
    StartItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

private:
    QPixmap pix;
};

#endif // STARTITEM_H
