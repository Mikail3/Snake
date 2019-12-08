#ifndef FOOD_H
#define FOOD_H
#include <QGraphicsPixmapItem> /// voor pixmap


class food:public QGraphicsPixmapItem
{
public:
    food(QGraphicsItem *parent = nullptr,QString name = "");
    int score;
    
    ///int item geeft score toe terug
};

#endif // FOOD_H

