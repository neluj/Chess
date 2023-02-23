#pragma once
#include "Movements.hpp"

class MovementsDiagonal;

class MovementsBishop : public Movements
{
public:
    MovementsBishop();
    virtual std::vector<std::pair<int,int>> getMovements(const std::shared_ptr<Figure> bishop, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) override;

private:

    std::shared_ptr<MovementsDiagonal> movementsDiagonal;

};