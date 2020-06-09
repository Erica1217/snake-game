#ifndef _ITEM_
#define _ITEM_

#include "Point.h"

class Item{
private:
    Point pos; //아이템의 위치(position)
	int kinds; //아이템의 종류 (1:grwoth 2:poison)
	int created_tick; //아이템 생성 시기
public:
	Item();
    Item(const Point pos, const int kinds, const int tick);
    Point getPos();
    int getKinds();
    int getCreatedTick();
    void setPos(const Point pos);
    void setKinds(const int kinds);
    void setCreatedTick(const int tick);
};

#endif