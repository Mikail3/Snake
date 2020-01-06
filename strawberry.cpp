#include "strawberry.h"

Strawberry::Strawberry(int x , int y) : Food(x,y)
{

}

int Strawberry::eaten(int oldScore) ///The score is given back
{
    return 5; ///Strawberry = 5 points.
}
