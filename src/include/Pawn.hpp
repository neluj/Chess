#pragma once
#include "Figure.hpp"

class Pawn :
    public Figure
{
public:

    Pawn(const Color & color, const std::pair<int, int> & pos);
    ~Pawn(){}
    std::shared_ptr<Figure> clone() const override;

};