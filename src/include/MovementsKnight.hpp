#pragma once
#include "Movements.hpp"

class MovementsPositionState;

class MovementsKnight : public Movements
{
public:
    MovementsKnight();
    //Returns figure if the movements ends withempassant
    virtual std::vector<std::pair<int,int>> getMovements(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) override;

private:

    void pushPosition(std::vector<std::pair<int,int>> & movements, const std::pair<int,int> & newPosition, const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
    std::shared_ptr<MovementsPositionState> movementsPositionState;

};