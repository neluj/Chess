#include "MovementsKing.hpp"
#include "MovementsUpDown.hpp"
#include "MovementsSides.hpp"
#include "MovementsDiagonal.hpp"
#include "MovementsPositionState.hpp"
#include <algorithm>
#include "King.hpp"

using namespace chess;

MovementsKing::MovementsKing()
{
    movementsSides = std::make_shared<MovementsSides>();
    movementsUpDown = std::make_shared<MovementsUpDown>();
    movementsDiagonal = std::make_shared<MovementsDiagonal>();
}

std::vector<std::shared_ptr<std::pair<int, int>>> MovementsKing::getMovements(const std::shared_ptr<Figure> king, const std::vector<std::shared_ptr<Figure>> &figuresOnBoard)
{
    std::shared_ptr<std::pair<int, int>> actualPosition = std::make_shared<std::pair<int, int>>(king->getPosition()->first, king->getPosition()->second);
    std::shared_ptr<std::pair<int, int>> movementUp = movementsUpDown->getUpPosition(actualPosition);
    std::shared_ptr<std::pair<int, int>> movementDown = movementsUpDown->getDownPosition(actualPosition);
    std::shared_ptr<std::pair<int, int>> movementLeft = movementsSides->getLeftPosition(actualPosition);
    std::shared_ptr<std::pair<int, int>> movementRight = movementsSides->getRightPosition(actualPosition);
    std::shared_ptr<std::pair<int, int>> movementDownLeft = movementsDiagonal->getDiagonalDownLeft(actualPosition);
    std::shared_ptr<std::pair<int, int>> movementDownRight = movementsDiagonal->getDiagonalDownRight(actualPosition);
    std::shared_ptr<std::pair<int, int>> movementUpLeft = movementsDiagonal->getDiagonalUpLeft(actualPosition);
    std::shared_ptr<std::pair<int, int>> movementUpRight = movementsDiagonal->getDiagonalUpRight(actualPosition);

    std::vector<std::shared_ptr<std::pair<int, int>>> movements;

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

bool MovementsKing::enemysPossibleMovement(const std::shared_ptr<Figure> king, const std::shared_ptr<std::pair<int, int>> &newPosition, const std::vector<std::shared_ptr<Figure>> &figuresOnBoard)
{

    auto hipoteticFiguresOnBoard = figuresOnBoard;
    std::shared_ptr<King> hipoteticKing = std::make_shared<King>(king->getColor(), newPosition);

    bool founded{false};
    size_t counter = 0;

    while(!founded && counter < hipoteticFiguresOnBoard.size())
    {
        auto figure = hipoteticFiguresOnBoard[counter];
        if(figure->getType() == Figure::KING && figure->getColor() == king->getColor())
        {
            hipoteticFiguresOnBoard[counter] = hipoteticKing;
            founded = true;
        }
        counter++;
    }


    //TODO si el nuevo movimiento está al alcance del otro rey, va a permir realizarlo. Esto es porque si se calcula el hipotético próximo movimiento del rey
    // entra en un búcle infiníto de llamadas a calcular hipotéticos pósibles próximos movimiento. Se puede crear una variable estática(?) para contar los movimientos
    // para asegurarse de que solo se llama una vez al rey.
    for (auto figure : hipoteticFiguresOnBoard)
    {
        if(figure->getType() != Figure::KING)
        if (figure->getColor() != king->getColor())
        {
            auto figurePossibleMovements = figure->getPossibleMovements(hipoteticFiguresOnBoard);

            auto possibleMovementsIterator = std::find_if(
                figurePossibleMovements.begin(), figurePossibleMovements.end(),
                [&newPosition](const std::shared_ptr<const std::pair<int, int>> &possibleMovement)
                { return (possibleMovement->first == newPosition->first && possibleMovement->second == newPosition->second); }
            );

            if (possibleMovementsIterator != figurePossibleMovements.end())
                return true;
        }
    }
    return false;
}

void MovementsKing::pushPosition(std::vector<std::shared_ptr<std::pair<int, int>>> &movements, const std::shared_ptr<std::pair<int, int>> &newPosition, const std::shared_ptr<Figure> king, const std::vector<std::shared_ptr<Figure>> &figuresOnBoard)
{
    if (movementsPositionState->positionExist(newPosition))
    {

        if (movementsPositionState->getFigureOnPosition(newPosition, figuresOnBoard) != nullptr)
        {
            if (movementsPositionState->getFigureOnPosition(newPosition, figuresOnBoard)->getColor() != king->getColor())
                if (!enemysPossibleMovement(king, newPosition, figuresOnBoard))
                    movements.push_back(newPosition);
        }
        else
            if (!enemysPossibleMovement(king, newPosition, figuresOnBoard))
            movements.push_back(newPosition);
    }
    
}       