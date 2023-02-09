#pragma once
#include <vector>
#include "MovementsPositionState.hpp"
#include "Knight.hpp"


class MovementsKnight
{
public:
    //Returns figure if the movements ends withempassant
    std::vector<std::pair<int,int>> getMovements(const std::shared_ptr<Knight> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
private:
    MovementsPositionState positionState;
};