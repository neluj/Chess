#include "Queen.hpp"

Queen::Queen(const Color & color, const std::pair<int, int> & pos):
Figure::Figure(color, Type::QUEEN, pos)
{}

std::shared_ptr<Figure> Queen::clone() const
{
    return std::make_shared<Queen>(*this);
}