#ifndef _SNAKE_
#define _SNAKE_

#include <vector>
#include "point.h"

class Snake 
{
public:
    /*
    final Point INIT_HEAD;
    final std::vector<Point> INIT_BODY;
    final int INIT_DIRECTION;
    final int INIT_BODYSIZE;
    */
   
    static Snake& instance() 
    {
        static Snake* instance = new Snake();
        return instance;
    }

    void clear();
    void move();
    int getSnakeSize(); 
    Point getHeadPosition();
    bool isValidSize(); 
    void setDirction(int d); 

private:
    Snake() {}
    std::vector <Point> body_positions;
    int current_direction; 
}

#endif