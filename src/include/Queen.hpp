#pragma once
#include "Figure.hpp"


class Queen :
    public Figure
{
public:

    Queen(const Color & color, const std::shared_ptr<std::pair<int, int>> & pos);
    ~Queen(){}
    std::shared_ptr<Figure> clone() const override;
    std::vector<std::shared_ptr<std::pair<int,int>>> getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) override;

};