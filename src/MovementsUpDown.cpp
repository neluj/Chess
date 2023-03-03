#include "MovementsUpDown.hpp"

std::shared_ptr<std::pair<int,int>> MovementsUpDown::getUpPosition(const std::shared_ptr<std::pair<int,int>> & position)
{
    return std::make_shared<std::pair<int, int>>(position->first, position->second-1);
}
std::shared_ptr<std::pair<int,int>> MovementsUpDown::getDownPosition(const std::shared_ptr<std::pair<int,int>> & position)
{
    return std::make_shared<std::pair<int, int>> (position->first, position->second+1);
}