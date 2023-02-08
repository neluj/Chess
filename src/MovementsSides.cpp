#include "MovementsSides.hpp"

std::pair<int,int> MovementsSides::getUpPosition(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::pair<int, int> upPosition(figure->getPosition().first, figure->getPosition().second-1);
    return positionState.checkPositionState(figure, figuresOnBoard, upPosition);
}
std::pair<int,int> MovementsSides::getDownPosition(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::pair<int, int> downPosition(figure->getPosition().first, figure->getPosition().second+1);
    return positionState.checkPositionState(figure, figuresOnBoard, downPosition);
}
std::pair<int,int> MovementsSides::getLeftPosition(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::pair<int, int> leftPosition(figure->getPosition().first-1, figure->getPosition().second);
    return positionState.checkPositionState(figure, figuresOnBoard, leftPosition);
}
std::pair<int,int> MovementsSides::getRightPosition(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::pair<int, int> rightPosition(figure->getPosition().first+1, figure->getPosition().second);
    return positionState.checkPositionState(figure, figuresOnBoard, rightPosition);
}



