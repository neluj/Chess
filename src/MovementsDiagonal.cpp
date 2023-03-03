#include "MovementsDiagonal.hpp"
#include "MovementsPositionState.hpp"

std::shared_ptr<std::pair<int,int>> MovementsDiagonal::getDiagonalUpLeft(const std::shared_ptr<std::pair<int,int>> & position)
{
    return std::make_shared<std::pair<int, int>>(position->first-1, position->second-1);
}
std::shared_ptr<std::pair<int,int>> MovementsDiagonal::getDiagonalUpRight(const std::shared_ptr<std::pair<int,int>> & position)
{
    return std::make_shared<std::pair<int, int>>(position->first+1, position->second-1);
}
std::shared_ptr<std::pair<int,int>> MovementsDiagonal::getDiagonalDownLeft(const std::shared_ptr<std::pair<int,int>> & position)
{
    return std::make_shared<std::pair<int, int>>(position->first-1, position->second+1);
}
std::shared_ptr<std::pair<int,int>> MovementsDiagonal::getDiagonalDownRight(const std::shared_ptr<std::pair<int,int>> & position)
{
    return std::make_shared<std::pair<int, int>>(position->first+1, position->second+1);
}