#pragma once
#include "Figure.hpp"

class Knight :
    public Figure
{
public:

    Knight(Color color, const std::pair<int, int> & pos);
    ~Knight(){}
    std::shared_ptr<Figure> clone() const override;

};