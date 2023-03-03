#pragma once
#include "Figure.hpp"

class Pawn :
    public Figure
{
public:

    Pawn(const Color & color, const std::shared_ptr<std::pair<int, int>> & pos, std::shared_ptr<Movements> movements = nullptr);
    ~Pawn(){}
    std::shared_ptr<Figure> clone() const override;

};