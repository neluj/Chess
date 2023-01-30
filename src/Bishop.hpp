#pragma once
#include "Figure.hpp"

class Bishop :
    public Figure
{
public:

    Bishop(Color color, const std::pair<int, int> & pos);
    ~Bishop(){}

};