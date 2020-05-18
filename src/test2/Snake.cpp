#include "Snake.h"
#include "GameSettings.h"

Snake::Snake()
{
    curDir = 0;

    head_pos.x = MAP_X / 2;
    head_pos.y = MAP_Y / 2;
}

void Snake::UpdateDirection(int key)
{
    switch (key)
    {
    case 119 : // w
        curDir = 0;
        break;
    case 115 : // s
        curDir = 1;
        break;
    case 100 : // d
        curDir = 2;
        break;
    case 97 :  // a
        curDir = 3;
        break;
    default:
        break;
    }
}

// 유효성검사할 때 호출, 다음 머리 위치 리턴
Point Snake::NextHeadPosition()
{
    int x = head_pos.x;
    int y = head_pos.y;

    switch (curDir)
    {
    case 0 : // 위쪽
        x--;
        break;
    case 1 : // 아래쪽
        x++;
        break;
    case 2 : // 오른쪽
        y++;
        break;
    case 3 : // 왼쪽
        y--;
        break;
    }

    Point temp{x, y};
    next_pos = temp;
    return temp;
}

void Snake::UpdateMoves()
{
    head_pos = next_pos;
}