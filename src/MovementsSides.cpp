#include "MovementsSides.hpp"

std::pair<int,int> MovementsSides::getLeftPosition( std::pair<int,int>  position)
{
    return std::pair<int, int>(position.first-1, position.second);
}
std::pair<int,int> MovementsSides::getRightPosition( std::pair<int,int>  position)
{
    return std::pair<int, int>(position.first+1, position.second);
}