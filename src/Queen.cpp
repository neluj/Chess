#include "Queen.hpp"

Queen::Queen(const Color & color, const std::pair<int, int> & pos, std::shared_ptr<Movements> movements):
Figure::Figure(color, Type::QUEEN, pos, movements)
{}

std::shared_ptr<Figure> Queen::clone() const
{
    return std::make_shared<Queen>(*this);
}
