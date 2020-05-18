#ifndef _SNAKE_
#define _SNAKE_

#include <vector>

struct Point
{
    int x;
    int y;
};

class Snake
{
public :
    // 0 위 / 1 아래 / 2 오른 / 3 왼
    int curDir;

    Snake();
    void UpdateDirection(int key);
    Point NextHeadPosition();
    void UpdateMoves();

    Point HeadPos(){ return head_pos; }; // 임시 사용 함수
private :
    Point next_pos;
    Point head_pos;
    std::vector<Point> bodies;
};

#endif