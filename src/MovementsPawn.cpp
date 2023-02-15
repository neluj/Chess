#include "MovementsPawn.hpp"
#include "MovementsDiagonal.hpp"
#include "MovementsUpDown.hpp"
#include "MovementsPositionState.hpp"
#include "Pawn.hpp"

MovementsPawn::MovementsPawn()
{
    movementsUpDown = std::make_shared<MovementsUpDown>();
    movementsDiagonal = std::make_shared<MovementsDiagonal>();
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
// TODO test return vector sizes
// TODO unificar positions y movements!!!! O diferenciarlos claramente, posicion puede ser cualquier cosa y movements solo a las posiciones que se pueden acceder
std::vector<std::pair<int,int>> MovementsPawn::getWhiteMovements(const std::shared_ptr<Pawn> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::vector<std::pair<int,int>> whiteMovements;
    std::vector<std::pair<int,int>> movementsFront = getWhiteFronts(pawn, figuresOnBoard);
    std::vector<std::pair<int,int>> movementsDiagonal = getWhiteDiagonals(pawn, figuresOnBoard);

    whiteMovements.reserve(movementsFront.size() + movementsDiagonal.size());
    whiteMovements.insert(whiteMovements.end(), movementsFront.begin(), movementsFront.end());
    whiteMovements.insert(whiteMovements.end(), movementsDiagonal.begin(), movementsDiagonal.end());

    return whiteMovements;
}
std::vector<std::pair<int,int>> MovementsPawn::getBlackMovements(const std::shared_ptr<Pawn> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::vector<std::pair<int,int>> blackMovements;
    std::vector<std::pair<int,int>> movementsFront = getBlackFronts(pawn, figuresOnBoard);
    std::vector<std::pair<int,int>> movementsDiagonal = getBlackDiagonals(pawn, figuresOnBoard);

    blackMovements.reserve(movementsFront.size() + movementsDiagonal.size());
    blackMovements.insert(blackMovements.end(), movementsFront.begin(), movementsFront.end());
    blackMovements.insert(blackMovements.end(), movementsDiagonal.begin(), movementsDiagonal.end());

    return blackMovements;
}
std::vector<std::pair<int,int>> MovementsPawn::getWhiteDiagonals(const std::shared_ptr<Pawn> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    return getDiagonalsPositions(&MovementsDiagonal::getDiagonalUpLeft, &MovementsDiagonal::getDiagonalUpRight, pawn, figuresOnBoard);
}

std::vector<std::pair<int,int>> MovementsPawn::getBlackDiagonals(const std::shared_ptr<Pawn> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    return getDiagonalsPositions(&MovementsDiagonal::getDiagonalDownLeft, &MovementsDiagonal::getDiagonalDownRight, pawn, figuresOnBoard);
}

std::vector<std::pair<int,int>> MovementsPawn::getWhiteFronts(const std::shared_ptr<Pawn> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    return getFrontPositions(&MovementsPawn::isWhiteInitialPosition, &MovementsUpDown::getUpPosition, pawn, figuresOnBoard);
}

std::vector<std::pair<int,int>> MovementsPawn::getBlackFronts(const std::shared_ptr<Pawn> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    return getFrontPositions(&MovementsPawn::isBlackInitialPosition, &MovementsUpDown::getDownPosition, pawn, figuresOnBoard);
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

//TODO para hacer push en los vectores, hacer como en el de los cavallos, en vez de comprobar una y otra vez
// TODO test return vector sizes
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

    std::pair<int,int> twoPositionsFront = ((*movementsUpDown).*frontMovement)(front);
    if(!movementsPositionState->positionExist(twoPositionsFront) || movementsPositionState->getFigureOnPosition(twoPositionsFront,figuresOnBoard) != nullptr)
    {
        return movements;
    }
    movements.push_back(twoPositionsFront);
    return movements;

}


std::vector<std::pair<int,int>> MovementsPawn::getDiagonalsPositions
(std::pair<int,int>  (MovementsDiagonal::*diagonalLeft   )(const std::pair<int,int>&), 
 std::pair<int,int>  (MovementsDiagonal::*diagonalRight  )(const std::pair<int,int>&), 
 const std::shared_ptr<Pawn> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
 {
    std::vector<std::pair<int,int>> movements;
    movements.reserve(2);  

    std::pair<int,int> initialPosition = pawn->getPosition();

    std::pair<int,int> diagonalLeftPosition = ((*movementsDiagonal).*diagonalLeft)(initialPosition);
    if(movementsPositionState->isEnemyFigureOnPosition(pawn,figuresOnBoard,diagonalLeftPosition))
        movements.push_back(diagonalLeftPosition);

    std::pair<int,int> diagonalRightPosition = ((*movementsDiagonal).*diagonalRight)(initialPosition);
    if(movementsPositionState->isEnemyFigureOnPosition(pawn,figuresOnBoard,diagonalRightPosition))
        movements.push_back(diagonalRightPosition);
      

    return movements;
 }