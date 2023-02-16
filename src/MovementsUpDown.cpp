#include "MovementsUpDown.hpp"

std::pair<int,int> MovementsUpDown::getUpPosition(const std::pair<int,int> & position)
{
    return std::pair<int, int>(position.first, position.second-1);
}
std::pair<int,int> MovementsUpDown::getDownPosition(const std::pair<int,int> & position)
{
    return std::pair<int, int> (position.first, position.second+1);
}