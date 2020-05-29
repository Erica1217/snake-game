#include "Point.h"
#include "GameSettings.h"

bool operator==(const Point& x, const Point& y)
{
    return (x.x == y.x) && (x.y == y.y);
}

bool Point::isValid()
{
    return (*this).x>=0 && (*this).y>=0 && (*this).x < MAP_X && (*this).y < MAP_Y;
}

