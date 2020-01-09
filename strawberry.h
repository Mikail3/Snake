#ifndef STRAWBERRY_H
#define STRAWBERRY_H

#include "food.h"


class Strawberry : public Food
{
public:
    Strawberry(); /* 9 : Default Constructor */
    Strawberry(int, int); /* 10 : Specific Constructor */
    
    int eaten(int oldScore);
};
#endif // STRAWBERRY_H
