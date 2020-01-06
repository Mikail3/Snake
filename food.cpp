#include "food.h"
#include <iostream>

Food::Food(int x, int y) : destroyed(false) /// Stuff behind semicolon ,, The different food's are loaded in the game , check the Other Files.
{
    ;
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
