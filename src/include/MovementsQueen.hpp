#pragma once
#include "Movements.hpp"

class MovementsSides;
class MovementsUpDown;
class MovementsDiagonal;

class MovementsQueen : public Movements
{
public:
    MovementsQueen();
    std::vector<std::shared_ptr<std::pair<int,int>>> getMovements(const std::shared_ptr<Figure> queen, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) override;

private:

    std::shared_ptr<MovementsSides> movementsSides;
    std::shared_ptr<MovementsUpDown> movementsUpDown;
    std::shared_ptr<MovementsDiagonal> movementsDiagonal;

};