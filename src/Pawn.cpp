#include "Pawn.hpp"

Pawn::Pawn(Color color, const std::pair<int, int> & pos):
Figure::Figure(color, Type::PAWN, pos)
{}