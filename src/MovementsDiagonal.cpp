#include "MovementsDiagonal.hpp"
#include "MovementsPositionState.hpp"

std::pair<int,int> MovementsDiagonal::getDiagonalUpLeft(const std::pair<int,int> & position)
{
    return std::pair<int, int> (position.first-1, position.second-1);
}
std::pair<int,int> MovementsDiagonal::getDiagonalUpRight(const std::pair<int,int> & position)
{
    return std::pair<int, int> (position.first+1, position.second-1);
}
std::pair<int,int> MovementsDiagonal::getDiagonalDownLeft(const std::pair<int,int> & position)
{
    return std::pair<int, int> (position.first-1, position.second+1);
}
std::pair<int,int> MovementsDiagonal::getDiagonalDownRight(const std::pair<int,int> & position)
{
    return std::pair<int, int> (position.first+1, position.second+1);
}


