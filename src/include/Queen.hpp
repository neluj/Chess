#pragma once
#include "Figure.hpp"

class Queen :
    public Figure
{
public:

    Queen(Color color, const std::pair<int, int> & pos);
    ~Queen(){}

};