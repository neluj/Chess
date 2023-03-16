#include "MovementsRook.hpp"
#include "MovementsOnDeepTemplates.hpp"
#include "MovementsUpDown.hpp"
#include "MovementsSides.hpp"
#include "Rook.hpp"

using namespace chess;


MovementsRook::MovementsRook()
{
    movementsSides = std::make_shared<MovementsSides>();
    movementsUpDown = std::make_shared<MovementsUpDown>();
}

std::vector<std::shared_ptr<std::pair<int,int>>> MovementsRook::getMovements(const std::shared_ptr<Figure> rook, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::vector<std::shared_ptr<std::pair<int,int>>> movementsUp = onDeep<MovementsUpDown, &MovementsUpDown::getUpPosition>  (movementsUpDown, rook, figuresOnBoard);
    std::vector<std::shared_ptr<std::pair<int,int>>> movementsDown = onDeep<MovementsUpDown, &MovementsUpDown::getDownPosition>(movementsUpDown, rook, figuresOnBoard);
    std::vector<std::shared_ptr<std::pair<int,int>>> movementsLeft = onDeep<MovementsSides, &MovementsSides::getLeftPosition>(movementsSides, rook, figuresOnBoard);
    std::vector<std::shared_ptr<std::pair<int,int>>> movementsRight = onDeep<MovementsSides, &MovementsSides::getRightPosition>(movementsSides, rook, figuresOnBoard);

    std::vector<std::shared_ptr<std::pair<int,int>>> movements;
    size_t movementsSize = movementsUp.size() + movementsDown.size() + movementsLeft.size() + movementsRight.size();

    movements.reserve(movementsSize);

    movements.insert(movements.end(), movementsUp.begin(), movementsUp.end());
    movements.insert(movements.end(), movementsDown.begin(), movementsDown.end());
    movements.insert(movements.end(), movementsLeft.begin(), movementsLeft.end());
    movements.insert(movements.end(), movementsRight.begin(), movementsRight.end());

    return movements;

}
