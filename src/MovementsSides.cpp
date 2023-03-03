#include "MovementsSides.hpp"

std::shared_ptr<std::pair<int,int>> MovementsSides::getLeftPosition(const std::shared_ptr<std::pair<int,int>> & position)
{
    return std::make_shared<std::pair<int, int>>(position->first-1, position->second);
}
std::shared_ptr<std::pair<int,int>> MovementsSides::getRightPosition(const std::shared_ptr<std::pair<int,int>> & position)
{
    return std::make_shared<std::pair<int, int>>(position->first+1, position->second);
}