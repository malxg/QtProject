#ifndef FLASHITEM_H
#define FLASHITEM_H

#include <QObject>

#include <QPainter>
#include <QGraphicsItem>
class FlashItem : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit FlashItem(QObject *parent = nullptr);
    void timerEvent(QTimerEvent *);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
private:
    bool flash;
    QTimer *timer;
signals:
public slots:

};

#endif // FLASHITEM_H
