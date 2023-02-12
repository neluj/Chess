#pragma once
#include "Figure.hpp"

class King :
    public Figure
{
public:

    King(Color color, const std::pair<int, int> & pos);
    ~King(){}
    std::shared_ptr<Figure> clone() const override;

};