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

std::pair<int,int> MovementsPositionState::returnNullValue()
{
    return std::pair<int, int>(-1,-1);
}

std::pair<int,int> MovementsPositionState::checkPositionState(const std::shared_ptr<Figure> figure,const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, const std::pair<int,int> & calculatedPosition)
{ 
    std::shared_ptr<Figure> figureOnPosition{nullptr};
    if(!positionExist(calculatedPosition))
        return returnNullValue();  
    
    figureOnPosition = getFigureOnPosition(calculatedPosition, figuresOnBoard);
    if(figureOnPosition==nullptr )
    {
        return calculatedPosition;
    }

    else if(figureOnPosition->getColor() != figure->getColor())
    {
        return calculatedPosition;
    }
    return returnNullValue();   
}