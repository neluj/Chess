#pragma once
#include "Figure.hpp"

class Rook :
    public Figure
{
public:

    Rook(const Color & color, const std::pair<int, int> & pos, std::shared_ptr<Movements> movements = nullptr);
    ~Rook(){}
    std::shared_ptr<Figure> clone() const override;
};