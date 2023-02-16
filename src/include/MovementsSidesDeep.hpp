#pragma once

#include <functional>
#include <vector>
#include <memory>


class MovementsSides;
class MovementsUpDown;
class Figure;

class MovementsSidesDeep
{

public:
    MovementsSidesDeep();
    //Returns figure if the movements ends withempassant
    std::vector<std::pair<int,int>> getUpPositions       (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) const;
    std::vector<std::pair<int,int>> getDownPositions     (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) const;
    std::vector<std::pair<int,int>> getLeftPositions     (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) const;
    std::vector<std::pair<int,int>> getRightPositions    (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) const;

private:

    std::shared_ptr<MovementsSides> movementsSides;
    std::shared_ptr<MovementsUpDown> movementsUpDown;
};