#include "Rook.hpp"

Rook::Rook(Color color, const std::pair<int, int> & pos):
Figure::Figure(color, Type::ROOK, pos)
{}

std::shared_ptr<Figure> Rook::clone() const
{
    return std::make_shared<Rook>(*this);
}