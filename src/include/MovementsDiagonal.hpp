#pragma once
#include "MovementsPositionState.hpp"

class MovementsDiagonal
{
public:
    std::shared_ptr<Figure> getDiagonalUpLeft   (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition);
    std::shared_ptr<Figure> getDiagonalUpRight  (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition);
    std::shared_ptr<Figure> getDiagonalDownLeft (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition);
    std::shared_ptr<Figure> getDiagonalDownRight(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition);  
private:
    MovementsPositionState positionState;
};