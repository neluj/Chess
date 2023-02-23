#include "Pawn.hpp"
#include "MovementsPawn.hpp"


Pawn::Pawn(const Color & color, const std::pair<int, int> & pos):
Figure::Figure(color, Type::PAWN, pos)
{}

std::shared_ptr<Figure> Pawn::clone() const
{
    return std::make_shared<Pawn>(*this);
}
