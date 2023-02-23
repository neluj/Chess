#pragma once
#include "Figure.hpp"

class Knight :
    public Figure
{
public:

    Knight(const Color & color, const std::pair<int, int> & pos, std::shared_ptr<Movements> movements = nullptr);
    ~Knight(){}
    std::shared_ptr<Figure> clone() const override;

};