#pragma once
#include <vector>
#include "MovementsPositionState.hpp"


class MovementsSides
{
public:
    //Returns figure if the movements ends withempassant
    std::pair<int,int> getUpPosition       (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
    std::pair<int,int> getDownPosition     (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
    std::pair<int,int> getLeftPosition     (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
    std::pair<int,int> getRightPosition    (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
private:
    MovementsPositionState positionState;
};