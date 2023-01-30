#include "Bishop.hpp"

Bishop::Bishop(Color color, const std::pair<int, int> & pos):
Figure::Figure(color, Type::BISHOP, pos)
{}