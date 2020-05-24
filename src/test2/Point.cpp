#include "Point.h"

bool operator==(const Point& x, const Point& y)
{
    return (x.x == y.x) && (x.y == y.y);
}