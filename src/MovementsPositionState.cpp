#include "MovementsPositionState.hpp"

bool MovementsPositionState::positionExist(const std::pair<int, int>  &position)
{
    //Chek if some of the points is bigger than 7 or smaller than 0
    if(position.first >7 || position.second>7 || position.first<0 || position.second<0)
        return false;
    return true;
}

std::shared_ptr<Figure> MovementsPositionState::getFigureOnPosition(const std::pair<int, int> & position, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::shared_ptr<Figure> figureOnPosition{nullptr};  
    for(std::shared_ptr<Figure> fig : figuresOnBoard)
    {
        if(fig->getPosition() == position)
            return fig;
    }
    return figureOnPosition;
}

std::shared_ptr<Figure> MovementsPositionState::returnNullValue(std::pair<int,int> & newPosition)
{
    newPosition = std::pair<int, int>(-1,-1);    
    return nullptr;
}

std::shared_ptr<Figure> MovementsPositionState::checkPositionState(const std::shared_ptr<Figure> figure,const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, const std::pair<int,int> & calculatedPosition, std::pair<int,int> & newPosition)
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