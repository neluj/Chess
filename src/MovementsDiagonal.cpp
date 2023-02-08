#include "MovementsDiagonal.hpp"

std::pair<int,int> MovementsDiagonal::getDiagonalUpLeft(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::pair<int, int> upLeftPosition(figure->getPosition().first-1, figure->getPosition().second-1);
    return positionState.checkPositionState(figure, figuresOnBoard, upLeftPosition);
}
std::pair<int,int> MovementsDiagonal::getDiagonalUpRight(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::pair<int, int> upRightPosition(figure->getPosition().first+1, figure->getPosition().second-1);
    return positionState.checkPositionState(figure, figuresOnBoard, upRightPosition);
}
std::pair<int,int> MovementsDiagonal::getDiagonalDownLeft(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::pair<int, int> downLeftPosition(figure->getPosition().first-1, figure->getPosition().second+1);
    return positionState.checkPositionState(figure, figuresOnBoard, downLeftPosition);
}
std::pair<int,int> MovementsDiagonal::getDiagonalDownRight(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::pair<int, int> downRightPosition(figure->getPosition().first+1, figure->getPosition().second+1);
    return positionState.checkPositionState(figure, figuresOnBoard, downRightPosition);
}


