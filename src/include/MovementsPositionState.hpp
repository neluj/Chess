#pragma once
#include <vector>
#include "Figure.hpp"

class MovementsPositionState
{

public:
    std::pair<int,int> checkPositionState(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, const std::pair<int,int> & calculatedPosition);

private:
    bool positionExist(const std::pair<int, int>  &position);   
    std::shared_ptr<Figure> getFigureOnPosition(const std::pair<int, int> & position, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
    std::pair<int,int> returnNullValue();
};