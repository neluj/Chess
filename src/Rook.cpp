#include "Rook.hpp"
#include "MovementsRook.hpp"

using namespace chess;


Rook::Rook(const Color & color, const std::shared_ptr<std::pair<int, int>> & pos):
Figure::Figure(color, Type::ROOK, pos)
{}

std::shared_ptr<Figure> Rook::clone() const
{
    return std::make_shared<Rook>(*this);
}

std::vector<std::shared_ptr<std::pair<int,int>>> Rook::getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::shared_ptr<MovementsRook> movements = std::make_shared<MovementsRook>();
    return movements->getMovements(shared_from_this(), figuresOnBoard);
}
