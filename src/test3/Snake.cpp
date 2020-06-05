#include "Snake.h"
#include "GameSettings.h"

Snake::Snake()
{
    curDir = 0;
    length = 3;

    // 뱀 시작위치(정가운데)
    head_pos.x = MAP_X / 2;
    head_pos.y = MAP_Y / 2;
    bodies.emplace_back(Point(10, 10));
    bodies.emplace_back(Point(11, 10));
    bodies.emplace_back(Point(12, 10));
}


void Snake::Update(GameData& game_data, UserData& user_data)
{
    head_pos = next_pos; // 유효성 검사에서 나온 다음 위치를 머리로
    
    int item = game_data.checkItem(head_pos);
    switch(item)
    {
        case -1 :
            // poision item
            break;
        case 0 :
            // 아무 것도 안 먹음
            break;
        case 1 :
            // growth item
            break;
    }
    
    bodies.insert(bodies.begin(), head_pos); // 머리를 앞에 넣고
    bodies.pop_back(); // 맨 뒤를 삭제

    game_data.updateSnakePosition(bodies);

    user_data.setCurrentLength(bodies.size());
}

// 유효성검사할 때 호출, 다음 머리 위치 리턴
// todo: point.moveTo()로 호출할 것
Point Snake::getNextPoint(int curDir)
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
    case DIR_RIGHT : // 오른쪽
        y++;
        break;
    case DIR_LEFT : // 왼쪽
        y--;
        break;
    }

    Point temp(x,y);
    next_pos = temp;
    return temp;
}