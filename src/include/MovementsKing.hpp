#pragma once
#include "Movements.hpp"

class MovementsSides;
class MovementsUpDown;
class MovementsDiagonal;
class MovementsPositionState;

class MovementsKing : public Movements
{
public:
    MovementsKing();
    std::vector<std::pair<int,int>> getMovements(const std::shared_ptr<Figure> king, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) override;

private:

    void pushPosition(std::vector<std::pair<int,int>> & movements, const std::pair<int,int> & newPosition, const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);

    std::shared_ptr<MovementsSides> movementsSides;
    std::shared_ptr<MovementsUpDown> movementsUpDown;
    std::shared_ptr<MovementsDiagonal> movementsDiagonal;
    std::shared_ptr<MovementsPositionState> movementsPositionState;


};