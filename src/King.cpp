#include "King.hpp"

King::King(Color color, const std::pair<int, int> & pos):
Figure::Figure(color, Type::KING, pos)
{}