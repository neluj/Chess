#include "Rook.hpp"

Rook::Rook(const Color & color, const std::shared_ptr<std::pair<int, int>> & pos, std::shared_ptr<Movements> movements):
Figure::Figure(color, Type::ROOK, pos, movements)
{}

std::shared_ptr<Figure> Rook::clone() const
{
    return std::make_shared<Rook>(*this);
}