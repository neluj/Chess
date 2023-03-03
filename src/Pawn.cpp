#include "Pawn.hpp"
#include "MovementsPawn.hpp"


Pawn::Pawn(const Color & color, const std::shared_ptr<std::pair<int, int>> & pos):
Figure::Figure(color, Type::PAWN, pos)
{}

std::shared_ptr<Figure> Pawn::clone() const
{
    return std::make_shared<Pawn>(*this);
}

std::vector<std::shared_ptr<std::pair<int,int>>> Pawn::getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::shared_ptr<MovementsPawn> movements = std::make_shared<MovementsPawn>();
    return movements->getMovements(shared_from_this(), figuresOnBoard);
}

