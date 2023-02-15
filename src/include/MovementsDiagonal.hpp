#pragma once
#include <utility>

class MovementsDiagonal
{
public:

    std::pair<int,int> getDiagonalUpLeft   (const std::pair<int,int> & position);
    std::pair<int,int> getDiagonalUpRight  (const std::pair<int,int> & position);
    std::pair<int,int> getDiagonalDownLeft (const std::pair<int,int> & position);
    std::pair<int,int> getDiagonalDownRight(const std::pair<int,int> & position);  

};