#include "MovementsSides.hpp"

std::pair<int,int> MovementsSides::getLeftPosition(const std::pair<int,int> & position)
{
    return std::pair<int, int>(position.first-1, position.second);
}
std::pair<int,int> MovementsSides::getRightPosition(const std::pair<int,int> & position)
{
    return std::pair<int, int>(position.first+1, position.second);
}