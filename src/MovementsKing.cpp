#include "MovementsKing.hpp"
#include "MovementsUpDown.hpp"
#include "MovementsSides.hpp"
#include "MovementsDiagonal.hpp"
#include "MovementsPositionState.hpp"
#include "King.hpp"

using namespace chess;


MovementsKing::MovementsKing()
{
    movementsSides = std::make_shared<MovementsSides>();
    movementsUpDown = std::make_shared<MovementsUpDown>();
    movementsDiagonal = std::make_shared<MovementsDiagonal>();
}

std::vector<std::shared_ptr<std::pair<int,int>>> MovementsKing::getMovements(const std::shared_ptr<Figure> king, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::shared_ptr<std::pair<int,int>> actualPosition = std::make_shared<std::pair<int,int>>(king->getPosition()->first, king->getPosition()->second);
    std::shared_ptr<std::pair<int,int>> movementUp = movementsUpDown->getUpPosition(actualPosition);
    std::shared_ptr<std::pair<int,int>> movementDown = movementsUpDown->getDownPosition(actualPosition);
    std::shared_ptr<std::pair<int,int>> movementLeft = movementsSides->getLeftPosition(actualPosition);
    std::shared_ptr<std::pair<int,int>> movementRight = movementsSides->getRightPosition(actualPosition);
    std::shared_ptr<std::pair<int,int>> movementDownLeft = movementsDiagonal->getDiagonalDownLeft(actualPosition);
    std::shared_ptr<std::pair<int,int>> movementDownRight = movementsDiagonal->getDiagonalDownRight(actualPosition);
    std::shared_ptr<std::pair<int,int>> movementUpLeft = movementsDiagonal->getDiagonalUpLeft(actualPosition);
    std::shared_ptr<std::pair<int,int>> movementUpRight = movementsDiagonal->getDiagonalUpRight(actualPosition);

    std::vector<std::shared_ptr<std::pair<int,int>>> movements;

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




void MovementsKing::pushPosition(std::vector<std::shared_ptr<std::pair<int,int>>> & movements, const std::shared_ptr<std::pair<int,int>> & newPosition, const std::shared_ptr<Figure> king, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
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