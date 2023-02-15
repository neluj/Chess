#include "MovementsSidesDeep.hpp"
#include "MovementsSides.hpp"
#include "MovementsUpDown.hpp"
#include "MovementsOnDeepTemplates.hpp"

MovementsSidesDeep::MovementsSidesDeep()
{
    movementsSides = std::make_shared<MovementsSides>();
    movementsUpDown = std::make_shared<MovementsUpDown>();
}

std::vector<std::pair<int,int>> MovementsSidesDeep::getUpPositions       (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    return onDeep<MovementsUpDown, &MovementsUpDown::getUpPosition>(movementsUpDown, figure, figuresOnBoard);
}
std::vector<std::pair<int,int>> MovementsSidesDeep::getDownPositions     (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    return onDeep<MovementsUpDown, &MovementsUpDown::getDownPosition>(movementsUpDown, figure, figuresOnBoard);
}
std::vector<std::pair<int,int>> MovementsSidesDeep::getLeftPositions     (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    return onDeep<MovementsSides, &MovementsSides::getLeftPosition>(movementsSides, figure, figuresOnBoard);
}
std::vector<std::pair<int,int>> MovementsSidesDeep::getRightPositions    (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    return onDeep<MovementsSides, &MovementsSides::getRightPosition>(movementsSides, figure, figuresOnBoard);
}


