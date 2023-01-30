#include "Queen.hpp"

Queen::Queen(Color color, const std::pair<int, int> & pos):
Figure::Figure(color, Type::QUEEN, pos)
{}