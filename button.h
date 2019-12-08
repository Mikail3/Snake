#ifndef BUTTON_H
#define BUTTON_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>


class Button:public QObject, public QGraphicsRectItem
{
    Q_OBJECT ///this is the basclass
public:

    Button(QString name, QGraphicsItem * parent = nullptr);

    //public methods

    //events
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    bool clicked();
private:
    QGraphicsTextItem *text;
};
#endif // BUTTON_H
