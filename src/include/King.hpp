#pragma once
#include "Figure.hpp"


class King :
    public Figure
{
public:

    King(const Color & color, const std::shared_ptr<std::pair<int, int>> & pos);
    ~King(){}
    std::shared_ptr<Figure> clone() const override;
    std::vector<std::shared_ptr<std::pair<int,int>>> getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) override;

};