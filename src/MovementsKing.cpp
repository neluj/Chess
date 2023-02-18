#include "MovementsKing.hpp"
#include "MovementsUpDown.hpp"
#include "MovementsSides.hpp"
#include "MovementsDiagonal.hpp"
#include "MovementsPositionState.hpp"
#include "King.hpp"

MovementsKing::MovementsKing()
{
    movementsSides = std::make_shared<MovementsSides>();
    movementsUpDown = std::make_shared<MovementsUpDown>();
    movementsDiagonal = std::make_shared<MovementsDiagonal>();
}

std::vector<std::pair<int,int>> MovementsKing::getMovements(const std::shared_ptr<King> king, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::pair<int,int> movementUp = movementsUpDown->getUpPosition(king->getPosition());
    std::pair<int,int> movementDown = movementsUpDown->getDownPosition(king->getPosition());
    std::pair<int,int> movementLeft = movementsSides->getLeftPosition(king->getPosition());
    std::pair<int,int> movementRight = movementsSides->getRightPosition(king->getPosition());
    std::pair<int,int> movementDownLeft = movementsDiagonal->getDiagonalDownLeft(king->getPosition());
    std::pair<int,int> movementDownRight = movementsDiagonal->getDiagonalDownRight(king->getPosition());
    std::pair<int,int> movementUpLeft = movementsDiagonal->getDiagonalUpLeft(king->getPosition());
    std::pair<int,int> movementUpRight = movementsDiagonal->getDiagonalUpRight(king->getPosition());

    std::vector<std::pair<int,int>> movements;

    movements.reserve(8);

    pushPosition(movements, movementUp, king, figuresOnBoard);
    pushPosition(movements, movementDown, king, figuresOnBoard);
    pushPosition(movements, movementLeft, king, figuresOnBoard);
    pushPosition(movements, movementRight, king, figuresOnBoard);
    pushPosition(movements, movementDownLeft, king, figuresOnBoard);
    pushPosition(movements, movementDownRight, king, figuresOnBoard);
    pushPosition(movements, movementUpLeft, king, figuresOnBoard);
    pushPosition(movements, movementUpRight, king, figuresOnBoard);

    return movements;

}




void MovementsKing::pushPosition(std::vector<std::pair<int,int>> & movements, const std::pair<int,int> & newPosition, const std::shared_ptr<King> king, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    if(movementsPositionState->positionExist(newPosition))
    {
        if(movementsPositionState->getFigureOnPosition(newPosition,figuresOnBoard)!=nullptr)
        {
            if(movementsPositionState->getFigureOnPosition(newPosition,figuresOnBoard)->getColor() != king->getColor())
                movements.push_back(newPosition);
        }
        else
            movements.push_back(newPosition);
    }
}