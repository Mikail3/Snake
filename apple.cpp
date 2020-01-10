#include "apple.h"

/*Apple::Apple() : Food(0,0) /// 15 : default values in function definition
{
    image.load(":/images/food.png");
    rect = image.rect();
    rect.translate(0, 0);


}
*/

Apple::Apple(int x, int y) : Food(x,y) /* 15 : default values in function definition */
{
    image.load(":/images/food.png");
    rect = image.rect();
    rect.translate(x, y);
}

int Apple::eaten(int oldScore)

{
    return 1;
}
