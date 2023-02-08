#include "MovementsSides.hpp"

std::shared_ptr<Figure> MovementsSides::getUpPosition(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition)
{
    std::pair<int, int> upPosition(figure->getPosition().first, figure->getPosition().second-1);
    return positionState.checkPositionState(figure, figuresOnBoard, upPosition, newPosition);
}
std::shared_ptr<Figure> MovementsSides::getDownPosition(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition)
{
    std::pair<int, int> downPosition(figure->getPosition().first, figure->getPosition().second+1);
    return positionState.checkPositionState(figure, figuresOnBoard, downPosition, newPosition);
}
std::shared_ptr<Figure> MovementsSides::getLeftPosition(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition)
{
    std::pair<int, int> leftPosition(figure->getPosition().first-1, figure->getPosition().second);
    return positionState.checkPositionState(figure, figuresOnBoard, leftPosition, newPosition);
}
std::shared_ptr<Figure> MovementsSides::getRightPosition(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition)
{
    std::pair<int, int> rightPosition(figure->getPosition().first+1, figure->getPosition().second);
    return positionState.checkPositionState(figure, figuresOnBoard, rightPosition, newPosition);
}



