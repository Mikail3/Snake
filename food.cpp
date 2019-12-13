#include "food.h"
#include <iostream>

Food::Food(int x, int y) {
    image.load(":/images/food.png");
    destroyed = false;
    rect = image.rect();
    rect.translate(x, y);
}

Food::~Food() {
    std::cout << ("Food deleted\n");
}

QRect Food::getRect() {
    return rect;
}

void Food::setRect(QRect rct) {
    rect = rct;
}

QImage & Food::getImage() {
    return image;
}

bool Food::isDestroyed() {
    return destroyed;
}

void Food::setDestroyed(bool destr) {
    destroyed = destr;
}
