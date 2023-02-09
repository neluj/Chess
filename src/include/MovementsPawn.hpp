#pragma once
#include "Pawn.hpp"


class MovementsPawn
{
public:
    //Returns figure if the movements ends withempassant
    std::vector<std::pair<int,int>> getMovements(const std::shared_ptr<Pawn> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);

};