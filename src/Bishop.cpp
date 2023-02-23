#include "Bishop.hpp"

Bishop::Bishop(const Color & color, const std::pair<int, int> & pos, std::shared_ptr<Movements> movements):
Figure::Figure(color, Type::BISHOP, pos, movements)
{}

std::shared_ptr<Figure> Bishop::clone() const
{
    return std::make_shared<Bishop>(*this);
}