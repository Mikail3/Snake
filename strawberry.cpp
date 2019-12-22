#include "strawberry.h"

Strawberry::Strawberry(int x , int y) : Food(x,y)
{

}

int Strawberry::eaten(int oldScore)
{
    return 5;
}
