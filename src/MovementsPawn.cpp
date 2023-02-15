#include "MovementsPawn.hpp"
#include "MovementsDiagonal.hpp"
#include "MovementsUpDown.hpp"
#include "MovementsPositionState.hpp"
#include "Pawn.hpp"

MovementsPawn::MovementsPawn()
{
    movementsUpDown = std::make_shared<MovementsUpDown>();
}
std::vector<std::pair<int,int>> MovementsPawn::getMovements(const std::shared_ptr<Pawn> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{

    if(pawn->getColor() == Figure::WHITE)
        return getWhiteMovements(pawn, figuresOnBoard);
    //If black, sub one position
    else if(pawn->getColor() == Figure::BLACK)
        return getBlackMovements(pawn, figuresOnBoard);

    return std::vector<std::pair<int,int>>();

}

std::vector<std::pair<int,int>> MovementsPawn::getWhiteMovements(const std::shared_ptr<Pawn> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::vector<std::pair<int,int>> movements;
    movements.reserve(4);

    return movements;

}
std::vector<std::pair<int,int>> MovementsPawn::getBlackMovements(const std::shared_ptr<Pawn> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::vector<std::pair<int,int>> movements;
    movements.reserve(4);

    return movements;
}
//std::vector<std::pair<int,int>> MovementsPawn::getWhiteDiagonals(const std::shared_ptr<Pawn> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
//{
//}
//std::vector<std::pair<int,int>> MovementsPawn::getBlackDiagonals(const std::shared_ptr<Pawn> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
//{
//}

// DELETE borrar returns del template
std::vector<std::pair<int,int>> MovementsPawn::getWhiteFronts(const std::shared_ptr<Pawn> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    return getFrontPositions(&MovementsPawn::isWhiteInitialPosition, &MovementsUpDown::getUpPosition, pawn, figuresOnBoard);
    //return frontPositions<MovementsUpDown, &MovementsUpDown::getUpPosition, MovementsPawn, &MovementsPawn::isWhiteInitialPosition >(movementsUpDown, *this, pawn, figuresOnBoard);
}
std::vector<std::pair<int,int>> MovementsPawn::getBlackFronts(const std::shared_ptr<Pawn> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    return getFrontPositions(&MovementsPawn::isBlackInitialPosition, &MovementsUpDown::getDownPosition, pawn, figuresOnBoard);
    //return frontPositions<MovementsUpDown, &MovementsUpDown::getDownPosition, MovementsPawn, &MovementsPawn::isBlackInitialPosition >(movementsUpDown, *this, pawn, figuresOnBoard);
}
bool MovementsPawn::isWhiteInitialPosition(const std::pair<int,int> &position)
{
    if(position.second == 6)
        return true;
    return false;    
}
bool MovementsPawn::isBlackInitialPosition(const std::pair<int,int> &position)
{
    if(position.second == 1)
        return true;
    return false;
}

std::vector<std::pair<int,int>> MovementsPawn::getFrontPositions
(bool               (MovementsPawn::*isInitialPosition)(const std::pair<int,int> &position),
std::pair<int,int>  (MovementsUpDown::*frontMovement  )(std::pair<int,int>), 
const std::shared_ptr<Pawn> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::vector<std::pair<int,int>> movements;
    movements.reserve(2);

    std::pair<int,int> initialPosition = pawn->getPosition();
    std::pair<int,int> front = ((*movementsUpDown).*frontMovement)(initialPosition);
    if(!movementsPositionState->positionExist(front) || movementsPositionState->getFigureOnPosition(front,figuresOnBoard) != nullptr)
    {
        return movements;
    }
    movements.push_back(front);

    if(!(this->*isInitialPosition)(pawn->getPosition()))
        return movements;

    std::pair<int,int> twoPositionsFront = ((*movementsUpDown).*frontMovement)(initialPosition);
    if(!movementsPositionState->positionExist(twoPositionsFront) || movementsPositionState->getFigureOnPosition(twoPositionsFront,figuresOnBoard) != nullptr)
    {
        return movements;
    }
    movements.push_back(twoPositionsFront);
    return movements;

}
