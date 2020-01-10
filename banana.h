#ifndef BANANA_H
#define BANANA_H
#include "food.h"

class Banana : public Food
{
public:
    Banana(); /* 9 : Default Constructor */
    Banana(int, int);

    int eaten(int oldScore);
};
#endif // BANANA_H
