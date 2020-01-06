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


Food::Food(int x, int y) ///The different food's are loaded in the game , check the Other Files.
{
    image.load(":/images/food.png");
    image.load(":/images/food1.png");
    destroyed = false;
    rect = image.rect();
    rect.translate(x, y);
}

Food::~Food()
{
    std::cout << ("Food deleten\n");
}

QRect Food::getRect()  ///The QRect class defines a rectangle in the plane using integer precision.
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
