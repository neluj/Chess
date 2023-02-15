#pragma once
#include <vector>
#include "Figure.hpp"

class MovementsPositionState
{

public:

    bool positionExist         (const std::pair<int, int>  &position);
    std::shared_ptr<Figure> getFigureOnPosition(const std::pair<int, int> & position, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
    bool isFree          (const std::pair<int, int> & position, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
    bool isEnemyFigureOnPosition(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, const std::pair<int,int> & calculatedPosition);
    bool isTeamFigureOnPosition (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, const std::pair<int,int> & calculatedPosition);

};