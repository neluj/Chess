#pragma once
#include <memory>
#include <vector>

class MovementsPositionState;
class Knight;
class Figure;

class MovementsKnight
{
public:
    MovementsKnight();
    //Returns figure if the movements ends withempassant
    std::vector<std::pair<int,int>> getMovements(const std::shared_ptr<Knight> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);

private:

    void pushPosition(std::vector<std::pair<int,int>> & movements, const std::pair<int,int> & newPosition, const std::shared_ptr<Knight> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
    std::shared_ptr<MovementsPositionState> movementsPositionState;

};