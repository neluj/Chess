#include "MovementsKnight.hpp"
#include "MovementsPositionState.hpp"
#include "Knight.hpp"

MovementsKnight::MovementsKnight()
{
    movementsPositionState = std::make_shared<MovementsPositionState>();
}


std::vector<std::pair<int,int>> MovementsKnight::getMovements(const std::shared_ptr<Knight> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::vector<std::pair<int,int>> movements;
    movements.reserve(8);

    //up-left
    std::pair<int,int> upLeft(figure->getPosition().first-1, figure->getPosition().second-2);
    pushPosition(movements, upLeft, figure, figuresOnBoard);

    //up-right
    std::pair<int,int> upRight(figure->getPosition().first+1, figure->getPosition().second-2);
    pushPosition(movements, upRight, figure, figuresOnBoard);

    //right-up
    std::pair<int,int> rightUp(figure->getPosition().first+2, figure->getPosition().second-1);
    pushPosition(movements, rightUp, figure, figuresOnBoard);

    //right-down
    std::pair<int,int> rightDown(figure->getPosition().first+2, figure->getPosition().second+1);
    pushPosition(movements, rightDown, figure, figuresOnBoard);

    //down-right
    std::pair<int,int> downRight(figure->getPosition().first+1, figure->getPosition().second+2);
    pushPosition(movements, downRight, figure, figuresOnBoard);

    //down-left
    std::pair<int,int> downLeft(figure->getPosition().first-1, figure->getPosition().second+2);
    pushPosition(movements, downLeft, figure, figuresOnBoard);

    //left-down
    std::pair<int,int> leftDown(figure->getPosition().first-2, figure->getPosition().second+1);
    pushPosition(movements, leftDown, figure, figuresOnBoard);

    //left-up
    std::pair<int,int> leftUp(figure->getPosition().first-2, figure->getPosition().second-1);
    pushPosition(movements, leftUp, figure, figuresOnBoard);

    return movements;
}

void MovementsKnight::pushPosition(std::vector<std::pair<int,int>> & movements, const std::pair<int,int> & newPosition, const std::shared_ptr<Knight> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    if(movementsPositionState->positionExist(newPosition))
    {
        if(movementsPositionState->getFigureOnPosition(newPosition,figuresOnBoard)!=nullptr)
        {
            if(movementsPositionState->getFigureOnPosition(newPosition,figuresOnBoard)->getColor() != figure->getColor())
                movements.push_back(newPosition);
        }
        else
            movements.push_back(newPosition);
    }
}
