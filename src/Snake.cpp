#include "Snake.h"

void Snake::clear()
{
    
}
void Snake::move()
{

}
int Snake::getSnakeSize()
{
    return body_positions.size();
}
Point Snake::getHeadPosition()
{
    return body_positions[0];
}
bool Snake::isValidSize()
{

}
void Snake::setDirction(int d)
{
    current_direction = d;
}