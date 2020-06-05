#include "Item.h"

Item::Item() 
{ 
    ;
}
int Item::getKinds(){ //아이템의 종류반환
    return kinds;
}
int Item::getCreatedTick(){//아이템 생성 시기 반환
    return created_tick;
} 
void Item::setPos(Point pos){//아이템의 위치 설정
    this -> pos = pos;
} 
void Item::setKinds(int kinds){//아이템의 종류 설정
    this -> kinds = kinds;
} 
void Item::setCreatedTick(int tick){//아이템 생성 시기 설정
    this -> created_tick = tick;
} 
Point Item::getPos() {
    return this -> pos;
}