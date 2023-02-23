#pragma once
#include <utility>
#include <memory>
#include <vector>

class Figure;

class Movements
{
public:

    virtual std::vector<std::pair<int,int>> getMovements(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) = 0;;

};