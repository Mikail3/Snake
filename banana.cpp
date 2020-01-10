#include "banana.h"

Banana::Banana(int x, int y) : Food(x,y)
{
    image.load(":/images/food2.png");
    rect = image.rect();
    rect.translate(x, y);
}

int Banana::eaten(int oldScore)

{
    return 3;
}
