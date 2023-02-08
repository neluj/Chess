#include "Pawn.hpp"

Pawn::Pawn(Color color, const std::pair<int, int> & pos):
Figure::Figure(color, Type::PAWN, pos)
{}

bool Pawn::isStartPosition()
{
    if(color == Color::BLACK)
    {
        if(position.second == 1)
            return true;
        return false;
    }
    if(position.second == 6)
        return true;
    return false;
}