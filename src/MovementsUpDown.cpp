#include "MovementsUpDown.hpp"

std::pair<int,int> MovementsUpDown::getUpPosition(std::pair<int,int> position)
{
    return std::pair<int, int>(position.first, position.second-1);
}
std::pair<int,int> MovementsUpDown::getDownPosition(std::pair<int,int> position)
{
    return std::pair<int, int> (position.first, position.second+1);
}