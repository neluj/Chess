#include "Bishop.hpp"
#include "MovementsBishop.hpp"

Bishop::Bishop(const Color & color, const std::shared_ptr<std::pair<int, int>> & pos):
Figure::Figure(color, Type::BISHOP, pos)
{}

std::shared_ptr<Figure> Bishop::clone() const
{
    return std::make_shared<Bishop>(*this);
}

std::vector<std::shared_ptr<std::pair<int,int>>> Bishop::getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::shared_ptr<MovementsBishop> movements = std::make_shared<MovementsBishop>();
    return movements->getMovements(shared_from_this(), figuresOnBoard);
}
