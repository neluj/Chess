#include "Rook.hpp"

Rook::Rook(Color color, const std::pair<int, int> & pos):
Figure::Figure(color, Type::ROOK, pos)
{}