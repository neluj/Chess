#pragma once
#include "Figure.hpp"

class Pawn :
    public Figure
{
public:

    Pawn(Color color, const std::pair<int, int> & pos);
    ~Pawn(){}
    std::shared_ptr<Figure> clone() const override;
    //virtual std::vector<std::pair<int, int>> getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) override;
private:

    bool isStartPosition();

};