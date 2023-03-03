#pragma once
#include "Figure.hpp"


class Pawn :
    public Figure
{
public:

    Pawn(const Color & color, const std::shared_ptr<std::pair<int, int>> & pos);
    ~Pawn(){}
    std::shared_ptr<Figure> clone() const override;
    std::vector<std::shared_ptr<std::pair<int,int>>> getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) override;

};