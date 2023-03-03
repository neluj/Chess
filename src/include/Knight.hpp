#pragma once
#include "Figure.hpp"


class Knight :
    public Figure
{
public:

    Knight(const Color & color, const std::shared_ptr<std::pair<int, int>> & pos);
    ~Knight(){}
    std::shared_ptr<Figure> clone() const override;
    std::vector<std::shared_ptr<std::pair<int,int>>> getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) override;

};