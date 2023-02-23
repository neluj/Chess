#include "King.hpp"

King::King(const Color & color, const std::pair<int, int> & pos, std::shared_ptr<Movements> movements):
Figure::Figure(color, Type::KING, pos, movements)
{}

std::shared_ptr<Figure> King::clone() const
{
    return std::make_shared<King>(*this);
}