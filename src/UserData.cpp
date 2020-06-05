#include "UserData.h"
#include "GameSettings.h"

UserData::UserData()
{
    current_length = 3;
    max_length = 3;
    growth_item_count = 0;
    poison_item_count = 0;
    used_gate_count = 0;

    window = newwin((MAP_Y + 1) / 2, MAP_X, 1, 22);
}

int UserData::getCurrentLength() {//현재 길이 반환
    return current_length;
}
void UserData::setCurrentLength(int current_length) { //현재 길이 설정
    this->current_length = current_length;
    UserData::setMaxLength(current_length);
}
int UserData::getMaxLength() { //최대 길이 반환
    return max_length;
}
void UserData::setMaxLength(int current_length) { //최대 길이 설정
    if (current_length > this->max_length) this->max_length = current_length;
}

int UserData::getGrowthItemCount() { //성장아이템 먹은 횟수 반환
    return growth_item_count;
}
void UserData::setGrowthItemCount(int growth_item_count) { //성장아이템 먹은 횟수 설정
    this->growth_item_count = growth_item_count;
}


int UserData::getPoisonItemCount() { //감소아이템 먹은 횟수 반환
    return poison_item_count;
}
void UserData::setPoisonItemCount(int poison_item_count) { //감소아이템 먹은 횟수 설정
    this->poison_item_count = poison_item_count;

}

void UserData::GrowthItemIncrease() { //성장아이템 먹은 횟수+1
    this->growth_item_count = growth_item_count;
    growth_item_count++;
}

void UserData::PoisonItemIncrease() { //감소아이템 먹은 횟수+1
    this->poison_item_count = poison_item_count;
    poison_item_count++;
}


int UserData::getUsedGateCount() { //게이트를 사용한 횟수 반환
    return used_gate_count;
}


void UserData::setUsedGateCount(int used_gate_count) { //게이트를 사용한 횟수 설정
    this->used_gate_count = used_gate_count;
};

void UserData::UsedGateCountIncrease() { //게이트를 사용한 횟수+1
    this->used_gate_count = used_gate_count;
    used_gate_count++;
}

void UserData::Render() {
    mvwprintw(window, 1, 1, "ScoreBoard");
    wrefresh(window);
}