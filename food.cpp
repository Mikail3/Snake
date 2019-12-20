#include "food.h"
#include <iostream>


/*

///#include "food.h"

#include <QBrush>


food::food(QGraphicsItem *parent,QString name):QGraphicsPixmapItem(parent)
{
    if(name == "APPLE"){ ///puntenverdeling voor de verschillende voedsels
        setPixmap(QPixmap(":/images/food.png").scaled(40,40));
        score = 1;
    }
    else{
        setPixmap(QPixmap(":/images/food2.png").scaled(40,40,Qt::KeepAspectRatio));
        score = 5;
    }
*/


Food::Food(int x, int y) {
    image.load(":/images/food.png");
    destroyed = false;
    rect = image.rect(); ///verwijzing naar de X , Y
    rect.translate(x, y);
}

Food::~Food()
{
    std::cout << ("Food deleten\n");
}

QRect Food::getRect()
{
    return rect;
}

void Food::setRect(QRect rct)
{
    rect = rct;
}

QImage & Food::getImage()
{
    return image;
}

bool Food::isDestroyed()
{
    return destroyed;
}

void Food::setDestroyed(bool destr)
{
    destroyed = destr;
}
