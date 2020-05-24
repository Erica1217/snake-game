#ifndef _SNAKE_
#define _SNAKE_

#include <vector>
#include "Point.h"
/*
struct Point
{
    int x;
    int y;
};
*/

class Snake
{
public :
    // 0 위 / 1 아래 / 2 오른 / 3 왼
    int curDir;
    int length;

    Snake();
    void UpdateDirection(int key);
    Point NextHeadPosition();
    void UpdateMoves();

    std::vector<Point> HeadPos() { return bodies; };
private :
    Point next_pos;
    Point head_pos;
    std::vector<Point> bodies;

    void UpdateStatus() { length = bodies.size(); };
};

#endif