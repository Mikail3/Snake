#ifndef APPLE_H
#define APPLE_H

#include "food.h" ///Apple.h is used for polymorphism

class Apple : public Food
{
public:
    Apple(int, int);

    int eaten(int oldScore);
};

#endif // APPLE_H
