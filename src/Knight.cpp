#include "Knight.hpp"

Knight::Knight(const Color & color, const std::pair<int, int> & pos):
Figure::Figure(color, Type::KNIGHT, pos)
{}

std::shared_ptr<Figure> Knight::clone() const
{
    return std::make_shared<Knight>(*this);
}