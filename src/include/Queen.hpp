#pragma once
#include "Figure.hpp"

class Queen :
    public Figure
{
public:

    Queen(const Color & color, const std::pair<int, int> & pos, std::shared_ptr<Movements> movements = nullptr);
    ~Queen(){}
    std::shared_ptr<Figure> clone() const override;
};