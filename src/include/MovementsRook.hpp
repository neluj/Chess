#pragma once
#include "Movements.hpp"

namespace chess
{

class MovementsSides;
class MovementsUpDown;

class MovementsRook : public Movements
{
public:
    MovementsRook();
    std::vector<std::shared_ptr<std::pair<int,int>>> getMovements(const std::shared_ptr<Figure> rook, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) override;

private:

    std::shared_ptr<MovementsSides> movementsSides;
    std::shared_ptr<MovementsUpDown> movementsUpDown;
};

}