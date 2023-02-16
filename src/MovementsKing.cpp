#include "MovementsKing.hpp"
#include "MovementsUpDown.hpp"
#include "MovementsSides.hpp"
#include "MovementsDiagonal.hpp"
#include "King.hpp"

MovementsKing::MovementsKing()
{
    movementsSides = std::make_shared<MovementsSides>();
    movementsUpDown = std::make_shared<MovementsUpDown>();
    movementsDiagonal = std::make_shared<MovementsDiagonal>();
}

std::vector<std::pair<int,int>> MovementsKing::getMovements(const std::shared_ptr<King> king, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::pair<int,int> movementUp = movementsUpDown->getUpPosition();
    std::pair<int,int> movementDown = movementsUpDown->getDownPosition();
    std::pair<int,int> movementLeft = movementsSides->getLeftPosition();
    std::pair<int,int> movementRight = movementsSides->getRightPosition();
    std::pair<int,int> movementDownLeft = movementsDiagonal->getDiagonalDownLeft();
    std::pair<int,int> movementDownRight = movementsDiagonal->getDiagonalDownRight;
    std::pair<int,int> movementUpLeft = movementsDiagonal->getDiagonalUpLeft();
    std::pair<int,int> movementUpRight = movementsDiagonal->getDiagonalUpRight();

    std::vector<std::pair<int,int>> movements;

    movements.reserve(8);

    pushPosition(movementUp);
    pushPosition(movementDown);
    pushPosition(movementLeft);
    pushPosition(movementRight);
    pushPosition(movementDownLeft);
    pushPosition(movementDownRight);
    pushPosition(movementUpLeft);
    pushPosition(movementUpRight);

    return movements;

}




void MovementsKing::pushPosition(std::vector<std::pair<int,int>> & movement, const std::pair<int,int> & newPosition, const std::shared_ptr<King> king, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
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