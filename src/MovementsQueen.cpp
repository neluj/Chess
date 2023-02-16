#include "MovementsQueen.hpp"
#include "MovementsOnDeepTemplates.hpp"
#include "MovementsDiagonal.hpp"
#include "MovementsUpDown.hpp"
#include "MovementsSides.hpp"
#include "Queen.hpp"

MovementsQueen::MovementsQueen()
{
    movementsSides = std::make_shared<MovementsSides>();
    movementsUpDown = std::make_shared<MovementsUpDown>();
    movementsDiagonal = std::make_shared<MovementsDiagonal>();
}

std::vector<std::pair<int,int>> MovementsQueen::getMovements(const std::shared_ptr<Queen> queen, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::vector<std::pair<int,int>> movementsUp = onDeep<MovementsUpDown, &MovementsUpDown::getUpPosition>  (movementsUpDown, queen, figuresOnBoard);
    std::vector<std::pair<int,int>> movementsDown = onDeep<MovementsUpDown, &MovementsUpDown::getDownPosition>(movementsUpDown, queen, figuresOnBoard);
    std::vector<std::pair<int,int>> movementsLeft = onDeep<MovementsSides, &MovementsSides::getLeftPosition>(movementsSides, queen, figuresOnBoard);
    std::vector<std::pair<int,int>> movementsRight = onDeep<MovementsSides, &MovementsSides::getRightPosition>(movementsSides, queen, figuresOnBoard);
    std::vector<std::pair<int,int>> movementsDownLeft = onDeep<MovementsDiagonal, &MovementsDiagonal::getDiagonalDownLeft>(movementsDiagonal, queen, figuresOnBoard);
    std::vector<std::pair<int,int>> movementsDownRight = onDeep<MovementsDiagonal, &MovementsDiagonal::getDiagonalDownRight>(movementsDiagonal, queen, figuresOnBoard);
    std::vector<std::pair<int,int>> movementsUpLeft = onDeep<MovementsDiagonal, &MovementsDiagonal::getDiagonalUpLeft>(movementsDiagonal, queen, figuresOnBoard);
    std::vector<std::pair<int,int>> movementsUpRight = onDeep<MovementsDiagonal, &MovementsDiagonal::getDiagonalUpRight>(movementsDiagonal, queen, figuresOnBoard);

    std::vector<std::pair<int,int>> movements;
    size_t movementsSize = movementsUp.size() + movementsDown.size() + movementsLeft.size() + movementsRight.size() + 
                           movementsDownLeft.size() + movementsDownRight.size() + movementsUpLeft.size() + movementsUpRight.size();

    movements.reserve(movementsSize);

    movements.insert(movements.end(), movementsUp.begin(), movementsUp.end());
    movements.insert(movements.end(), movementsDown.begin(), movementsDown.end());
    movements.insert(movements.end(), movementsLeft.begin(), movementsLeft.end());
    movements.insert(movements.end(), movementsRight.begin(), movementsRight.end());
    movements.insert(movements.end(), movementsDownLeft.begin(), movementsDownLeft.end());
    movements.insert(movements.end(), movementsDownRight.begin(), movementsDownRight.end());
    movements.insert(movements.end(), movementsUpLeft.begin(), movementsUpLeft.end());
    movements.insert(movements.end(), movementsUpRight.begin(), movementsUpRight.end());

    return movements;

}
