#include "Snake.h"
#include "GameSettings.h"
#include <iostream>

Snake::Snake()
{
    // 뱀 시작위치(정가운데)
    head_pos.x = 17;
    head_pos.y = 10;
    bodies.emplace_back(Point(17, 10));
    bodies.emplace_back(Point(18, 10));
    bodies.emplace_back(Point(19, 10));
}

// 유효성검사할 때 호출, 다음 머리 위치 리턴
Point Snake::getNextPoint(const int curDir)
{   
    //Point nextPos(head_pos.x, head_pos.y);
    next_pos = head_pos.moveTo(curDir);
    return next_pos;
    //return head_pos.moveTo(curDir);
}

void Snake::update(GameData& game_data, UserData& user_data)
{
    head_pos = next_pos; // 유효성 검사에서 나온 다음 위치를 머리로
    
    // 아이템 처리
    //int item = game_data.checkItem(head_pos);
    switch(game_data.checkItem(head_pos))
    {
        case -1 :
            // poison item
            if(bodies.size() > 0) bodies.pop_back();
            break;
        case 0 :
            // 아무 것도 안 먹음
            break;
        case 1 :
            // growth item
            if(bodies.size() > 0) bodies.push_back(bodies.back());
            break;
    }

    // 최종 결과물
    bodies.insert(bodies.begin(), head_pos); // 머리를 앞에 넣고
    bodies.pop_back(); // 맨 뒤를 삭제
    
    // 게이트를 통과했을 경우
    for(int i=0 ; i<2 ; i++)
    {
        if(game_data.getGatePositions().size()==2 &&  bodies[0] == game_data.getGatePositions()[i])
        {
            int nextDir = game_data.getGateDirections()[game_data.getCurrrentDirection()][1-i];
            bodies[0] = game_data.getGatePositions()[1-i].moveTo(nextDir);
            game_data.setCurrentDirection(nextDir);
            head_pos = bodies[0];
            break;
        }
    }

    game_data.updateSnakePosition(bodies); // 게임데이터에 스네이크 위치 넣어줌

    user_data.setCurrentLength(bodies.size()); // 유저데이터에 스네이크 길이 넣어줌
}