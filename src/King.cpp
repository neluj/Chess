#include "King.hpp"

King::King(Color color, const std::pair<int, int> & pos):
Figure::Figure(color, Type::KING, pos)
{}

std::shared_ptr<Figure> King::clone() const
{
    return std::make_shared<King>(*this);
}