#include "Snake.h"
#include "GameSettings.h"

Snake::Snake()
{
    curDir = 0;
    length = 3;

    // 뱀 시작위치(정가운데)
    head_pos.x = MAP_X / 2;
    head_pos.y = MAP_Y / 2;
    bodies.emplace_back(Point{10, 10});
    bodies.emplace_back(Point{11, 10});
    bodies.emplace_back(Point{12, 10});
}

// 키값 입력될때마다 방향 변경해줌
void Snake::UpdateDirection(int key)
{
    switch (key)
    {
    case KB_W : // w
    case KB_UP : // 위
        curDir = DIR_UP;
        break;
    case KB_S : // s
    case KB_DOWN : // 아래
        curDir = DIR_DOWN;
        break;
    case KB_RIGHT : // d
    case KB_D : // 오른
        curDir = DIR_RIGTH;
        break;
    case KB_A :  // a
    case KB_LEFT : // 왼
        curDir = DIR_LEFT;
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

    // 현재 설정되어있는 방향 기준
    switch (curDir)
    {
    case DIR_UP : // 위쪽
        x--;
        break;
    case DIR_DOWN : // 아래쪽
        x++;
        break;
    case DIR_RIGTH : // 오른쪽
        y++;
        break;
    case DIR_LEFT : // 왼쪽
        y--;
        break;
    }

    Point temp{x, y};
    next_pos = temp;
    return temp;
}

// 게임데이터 업데이트 될 때 호출
void Snake::UpdateMoves()
{
    head_pos = next_pos; // 유효성 검사에서 나온 다음 위치를 머리로
    
    bodies.insert(bodies.begin(), head_pos); // 머리를 앞에 넣고
    bodies.pop_back(); // 맨 뒤를 삭제
}