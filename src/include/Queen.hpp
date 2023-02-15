#pragma once
#include "Figure.hpp"

class Queen :
    public Figure
{
public:

    Queen(const Color & color, const std::pair<int, int> & pos);
    ~Queen(){}
    std::shared_ptr<Figure> clone() const override;

};