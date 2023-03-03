#pragma once
#include "Figure.hpp"

class Bishop :
    public Figure
{
public:

    Bishop(const Color & color, const std::shared_ptr<std::pair<int, int>> & pos, std::shared_ptr<Movements> movements = nullptr);
    ~Bishop(){}
    std::shared_ptr<Figure> clone() const override;

};