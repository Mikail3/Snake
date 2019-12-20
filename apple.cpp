#include "apple.h"

Apple::Apple(int x, int y) : Food(x,y)
{

}

int Apple::eaten(int oldScore)
{
    return 1;
}
