#include "MovementsSides.hpp"

std::shared_ptr<Figure> MovementsSides::getUpPosition(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition)
{
    std::pair<int, int> upPosition(figure->getPosition().first, figure->getPosition().second-1);
    return checkPositionState(figure, figuresOnBoard, upPosition, newPosition);
    
}
std::shared_ptr<Figure> MovementsSides::getDownPosition(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition)
{
    std::pair<int, int> downPosition(figure->getPosition().first, figure->getPosition().second+1);
    return checkPositionState(figure, figuresOnBoard, downPosition, newPosition);
}
std::shared_ptr<Figure> MovementsSides::getLeftPosition(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition)
{
    std::pair<int, int> leftPosition(figure->getPosition().first-1, figure->getPosition().second);
    return checkPositionState(figure, figuresOnBoard, leftPosition, newPosition);
}
std::shared_ptr<Figure> MovementsSides::getRightPosition(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition)
{
    std::pair<int, int> rightPosition(figure->getPosition().first+1, figure->getPosition().second);
    return checkPositionState(figure, figuresOnBoard, rightPosition, newPosition);
}

std::shared_ptr<Figure> MovementsSides::checkPositionState(const std::shared_ptr<Figure> figure,const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, const std::pair<int,int> & calculatedPosition, std::pair<int,int> & newPosition)
{ 
    std::shared_ptr<Figure> figureOnPosition{nullptr};
    if(!positionExist(calculatedPosition))
        return returnNullValue(newPosition);  
    
    figureOnPosition = getFigureOnPosition(calculatedPosition, figuresOnBoard);
    if(figureOnPosition==nullptr )
    {
        newPosition = calculatedPosition;
        return figureOnPosition;
    }

    else if(figureOnPosition->getColor() != figure->getColor())
    {
        newPosition = calculatedPosition;
        return figureOnPosition;
    }

    return returnNullValue(newPosition);   
}

bool MovementsSides::positionExist(const std::pair<int, int>  &position)
{
    //Chek if some of the points is bigger than 7 or smaller than 0
    if(position.first >7 || position.second>7 || position.first<0 || position.second<0)
        return false;
    return true;
}

std::shared_ptr<Figure> MovementsSides::getFigureOnPosition(const std::pair<int, int> & position, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::shared_ptr<Figure> figureOnPosition{nullptr};  
    for(std::shared_ptr<Figure> fig : figuresOnBoard)
    {
        if(fig->getPosition() == position)
            return fig;
    }
    return figureOnPosition;
}

std::shared_ptr<Figure> MovementsSides::returnNullValue(std::pair<int,int> & newPosition)
{
    newPosition = std::pair<int, int>(-1,-1);    
    return nullptr;
}
