#ifndef _POINT_
#define _POINT_

class Point
{
public:
    int x;
    int y;
    Point() : x(0),y(0) { };
    Point(int x, int y) : x(x), y(y) { };
    friend bool operator==(const Point& x, const Point& y);
    bool isValid();
    Point moveTo(int curDir);
};

#endif