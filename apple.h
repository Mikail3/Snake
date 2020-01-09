#ifndef APPLE_H
#define APPLE_H

#include "food.h" /* 23 : Seperated header file */

class Apple : public Food /* 4 : Inheritance , 21 : Namespaces */
{
public:
    Apple(); /* 9 : Defualt Constructor */
    Apple(int, int); /* 10 : Specific Constructor */

    int eaten(int oldScore);
};

#endif // APPLE_H


