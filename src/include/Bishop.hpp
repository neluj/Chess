#pragma once
#include "Figure.hpp"

class Bishop :
    public Figure
{
public:

    Bishop(const Color & color, const std::pair<int, int> & pos);
    ~Bishop(){}
    std::shared_ptr<Figure> clone() const override;

};