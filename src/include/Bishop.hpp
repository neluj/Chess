#pragma once
#include "Figure.hpp"

namespace chess
{

class Bishop :
    public Figure
{
public:

    Bishop(const Color & color, const std::shared_ptr<std::pair<int, int>> & pos);
    ~Bishop(){}
    std::shared_ptr<Figure> clone() const override;
    std::vector<std::shared_ptr<std::pair<int,int>>> getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) override;

};

}