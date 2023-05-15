#include "Square.hpp"

using namespace chess;

Square::Square(int ix, int iy) :
    x(ix),
    y(iy)
{}

Square::Square(char cx, char cy)
{
    setPosition(cx,cy);
}

Square::Square(const std::string & post)
{
    setPosition(post.at(0),post.at(1));
}

bool Square::operator==(const Square & square) const
{
    return((square.x == x) && (square.y == y));
}

void Square::setPosition(char cx, char cy)
{
    x = int(cx) - 65;
    y = 56 - int(cy);
}
