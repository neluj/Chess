#pragma once
#include "Figure.hpp"

class Rook :
    public Figure
{
public:

    Rook(const Color & color, const std::pair<int, int> & pos);
    ~Rook(){}
    std::shared_ptr<Figure> clone() const override;
};