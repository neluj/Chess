#pragma once
#include <utility>
#include <memory>

namespace chess
{

class MovementsDiagonal
{
public:

    std::shared_ptr<std::pair<int,int>> getDiagonalUpLeft   (const std::shared_ptr<std::pair<int,int>> & position);
    std::shared_ptr<std::pair<int,int>> getDiagonalUpRight  (const std::shared_ptr<std::pair<int,int>> & position);
    std::shared_ptr<std::pair<int,int>> getDiagonalDownLeft (const std::shared_ptr<std::pair<int,int>> & position);
    std::shared_ptr<std::pair<int,int>> getDiagonalDownRight(const std::shared_ptr<std::pair<int,int>> & position);  

};

}