#include "MovementsDiagonal.hpp"

std::shared_ptr<Figure> MovementsDiagonal::getDiagonalUpLeft(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition)
{
    std::pair<int, int> upLeftPosition(figure->getPosition().first-1, figure->getPosition().second-1);
    return positionState.checkPositionState(figure, figuresOnBoard, upLeftPosition, newPosition);
}
std::shared_ptr<Figure> MovementsDiagonal::getDiagonalUpRight(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition)
{
    std::pair<int, int> upRightPosition(figure->getPosition().first+1, figure->getPosition().second-1);
    return positionState.checkPositionState(figure, figuresOnBoard, upRightPosition, newPosition);
}
std::shared_ptr<Figure> MovementsDiagonal::getDiagonalDownLeft(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition)
{
    std::pair<int, int> downLeftPosition(figure->getPosition().first-1, figure->getPosition().second+1);
    return positionState.checkPositionState(figure, figuresOnBoard, downLeftPosition, newPosition);
}
std::shared_ptr<Figure> MovementsDiagonal::getDiagonalDownRight(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition)
{
    std::pair<int, int> downRightPosition(figure->getPosition().first+1, figure->getPosition().second+1);
    return positionState.checkPositionState(figure, figuresOnBoard, downRightPosition, newPosition);
}


