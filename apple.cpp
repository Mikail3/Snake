#include "apple.h"

Apple::Apple(int x, int y) : Food(x,y)
{

}

int Apple::eaten(int oldScore) ///Score is given back

{
    return 1; ///Apple = 1 point.
}
