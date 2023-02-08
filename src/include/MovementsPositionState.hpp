#pragma once
#include <vector>
#include "Figure.hpp"

class MovementsPositionState
{

public:
    std::shared_ptr<Figure> checkPositionState(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, const std::pair<int,int> & calculatedPosition, std::pair<int,int> & newPosition);

private:
    bool positionExist(const std::pair<int, int>  &position);   
    std::shared_ptr<Figure> getFigureOnPosition(const std::pair<int, int> & position, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
    std::shared_ptr<Figure> returnNullValue(std::pair<int,int> & newPosition);
};