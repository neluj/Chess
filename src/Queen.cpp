#include "Queen.hpp"
#include "MovementsQueen.hpp"

using namespace chess;


Queen::Queen(const Color & color, const std::shared_ptr<std::pair<int, int>> & pos):
Figure::Figure(color, Type::QUEEN, pos)
{}

std::shared_ptr<Figure> Queen::clone() const
{
    return std::make_shared<Queen>(*this);
}

std::vector<std::shared_ptr<std::pair<int,int>>> Queen::getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::shared_ptr<MovementsQueen> movements = std::make_shared<MovementsQueen>();
    return movements->getMovements(shared_from_this(), figuresOnBoard);
}

