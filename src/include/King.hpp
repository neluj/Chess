#pragma once
#include "Figure.hpp"

class King :
    public Figure
{
public:

    King(const Color & color, const std::pair<int, int> & pos, std::shared_ptr<Movements> movements = nullptr);
    ~King(){}
    std::shared_ptr<Figure> clone() const override;

};