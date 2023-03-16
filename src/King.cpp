#include "King.hpp"
#include "MovementsKing.hpp"

using namespace chess;


King::King(const Color & color, const std::shared_ptr<std::pair<int, int>> & pos):
Figure::Figure(color, Type::KING, pos)
{}

std::shared_ptr<Figure> King::clone() const
{
    return std::make_shared<King>(*this);
}

std::vector<std::shared_ptr<std::pair<int,int>>> King::getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::shared_ptr<MovementsKing> movements = std::make_shared<MovementsKing>();
    return movements->getMovements(shared_from_this(), figuresOnBoard);
}
