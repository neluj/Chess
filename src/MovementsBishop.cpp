#include "MovementsBishop.hpp"
#include "MovementsOnDeepTemplates.hpp"
#include "MovementsDiagonal.hpp"
#include "Bishop.hpp"

MovementsBishop::MovementsBishop()
{
    movementsDiagonal = std::make_shared<MovementsDiagonal>();
}

std::vector<std::pair<int,int>> MovementsBishop::getMovements(const std::shared_ptr<Bishop> bishop, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{

    std::vector<std::pair<int,int>> movementsDownLeft = onDeep<MovementsDiagonal, &MovementsDiagonal::getDiagonalDownLeft>(movementsDiagonal, bishop, figuresOnBoard);
    std::vector<std::pair<int,int>> movementsDownRight = onDeep<MovementsDiagonal, &MovementsDiagonal::getDiagonalDownRight>(movementsDiagonal, bishop, figuresOnBoard);
    std::vector<std::pair<int,int>> movementsUpLeft = onDeep<MovementsDiagonal, &MovementsDiagonal::getDiagonalUpLeft>(movementsDiagonal, bishop, figuresOnBoard);
    std::vector<std::pair<int,int>> movementsUpRight = onDeep<MovementsDiagonal, &MovementsDiagonal::getDiagonalUpRight>(movementsDiagonal, bishop, figuresOnBoard);

    std::vector<std::pair<int,int>> movements;
    size_t movementsSize = movementsDownLeft.size() + movementsDownRight.size() + movementsUpLeft.size() + movementsUpRight.size();

    movements.reserve(movementsSize);

    movements.insert(movements.end(), movementsDownLeft.begin(), movementsDownLeft.end());
    movements.insert(movements.end(), movementsDownRight.begin(), movementsDownRight.end());
    movements.insert(movements.end(), movementsUpLeft.begin(), movementsUpLeft.end());
    movements.insert(movements.end(), movementsUpRight.begin(), movementsUpRight.end());

    return movements;

}
