#include "food.h"
#include <iostream>

Food::Food(int x, int y) : destroyed(false) /* 11 : Member Initalization */ ///Stuff behind semicolon ,, The different food's are loaded in the game , check the Other Files.
{
    ;
}

Food::~Food()
{
    std::cout << ("Food deleten\n"); /* 32 : Container Class */
}

QRect Food::getRect()
{
    return rect;
}

void Food::setRect(QRect rct) /* 17 : Setters for member variables */

{
    rect = rct;
}

QImage & Food::getImage() /* 17 : Getter */
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
