#pragma once
#include "Figure.hpp"


class Rook :
    public Figure
{
public:

    Rook(const Color & color, const std::shared_ptr<std::pair<int, int>> & pos);
    ~Rook(){}
    std::shared_ptr<Figure> clone() const override;
    std::vector<std::shared_ptr<std::pair<int,int>>> getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) override;

};