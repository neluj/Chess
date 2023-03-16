#include "Knight.hpp"
#include "MovementsKnight.hpp"

using namespace chess;


Knight::Knight(const Color & color, const std::shared_ptr<std::pair<int, int>> & pos):
Figure::Figure(color, Type::KNIGHT, pos)
{}

std::shared_ptr<Figure> Knight::clone() const
{
    return std::make_shared<Knight>(*this);
}

std::vector<std::shared_ptr<std::pair<int,int>>> Knight::getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    static MovementsKnight movements;
    return movements.getMovements(shared_from_this(), figuresOnBoard);
}
