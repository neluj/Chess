#pragma once
#include "Figure.hpp"

class Rook :
    public Figure
{
public:

    Rook(Color color, const std::pair<int, int> & pos);
    ~Rook(){}
    std::shared_ptr<Figure> clone() const override;
};