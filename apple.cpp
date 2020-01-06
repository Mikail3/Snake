#include "apple.h"

/*Apple::Apple() : Food(0,0)
{
    image.load(":/images/food.png");
    rect = image.rect();
    rect.translate(0, 0);
}
*/

Apple::Apple(int x, int y) : Food(x,y)
{
    image.load(":/images/food.png");
    rect = image.rect();
    rect.translate(x, y);
}

int Apple::eaten(int oldScore) ///Score is given back

{
    return 1; ///Apple = 1 point.
}
