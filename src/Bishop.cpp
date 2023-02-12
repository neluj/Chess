#include "Bishop.hpp"

Bishop::Bishop(Color color, const std::pair<int, int> & pos):
Figure::Figure(color, Type::BISHOP, pos)
{}

std::shared_ptr<Figure> Bishop::clone() const
{
    return std::make_shared<Bishop>(*this);
}