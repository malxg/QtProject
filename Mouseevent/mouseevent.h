#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include <QMainWindow>
#include <QLabel>
#include <QStatusBar>
#include <QMouseEvent>
QT_BEGIN_NAMESPACE
//namespace Ui { class Mouseevent; }
QT_END_NAMESPACE

class Mouseevent : public QMainWindow
{
    Q_OBJECT

public:
    Mouseevent(QWidget *parent = nullptr);
    ~Mouseevent();
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMoveEvent *e);
    void mouseDoubleClickEvent(Mouseevent *e);
private:
   // Ui::Mouseevent *ui;
    QLabel *statusLabel;
    QLabel *MousePosLabel;
};
#endif // MOUSEEVENT_H
