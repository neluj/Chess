#pragma once
#include "MovementsPositionState.hpp"

class MovementsDiagonal
{
public:
    std::pair<int,int> getDiagonalUpLeft   (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
    std::pair<int,int> getDiagonalUpRight  (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
    std::pair<int,int> getDiagonalDownLeft (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
    std::pair<int,int> getDiagonalDownRight(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);  
private:
    MovementsPositionState positionState;
};