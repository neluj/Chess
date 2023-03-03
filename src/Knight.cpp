#include "Knight.hpp"

Knight::Knight(const Color & color, const std::shared_ptr<std::pair<int, int>> & pos, std::shared_ptr<Movements> movements):
Figure::Figure(color, Type::KNIGHT, pos, movements)
{}

std::shared_ptr<Figure> Knight::clone() const
{
    return std::make_shared<Knight>(*this);
}