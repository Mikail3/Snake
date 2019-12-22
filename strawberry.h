#ifndef STRAWBERRY_H
#define STRAWBERRY_H
#include "food.h"


class Strawberry : public Food
{
public:
    Strawberry(int, int);
    int eaten(int oldScore);
};
#endif // STRAWBERRY_H
