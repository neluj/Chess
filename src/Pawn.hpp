#pragma once
#include "Figure.hpp"

class Pawn :
    public Figure
{
public:

    Pawn(Color color, const std::pair<int, int> & pos);
    ~Pawn(){}

};