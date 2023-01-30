#include "Knight.hpp"

Knight::Knight(Color color, const std::pair<int, int> & pos):
Figure::Figure(color, Type::KNIGHT, pos)
{}