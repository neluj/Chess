#include "MovementsPositionState.hpp"

bool MovementsPositionState::positionExist(const std::shared_ptr<std::pair<int,int>>  &position)
{
    //Chek if some of the points is bigger than 7 or smaller than 0
    if(position->first >7 || position->second>7 || position->first<0 || position->second<0)
        return false;
    return true;
}

std::shared_ptr<Figure> MovementsPositionState::getFigureOnPosition(const std::shared_ptr<std::pair<int,int>> & position, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::shared_ptr<Figure> figureOnPosition{nullptr};  
    for(std::shared_ptr<Figure> fig : figuresOnBoard)
    {
        if(fig->getPosition() == position)
            return fig;
    }
    return figureOnPosition;
}

bool MovementsPositionState::isFree          (const std::shared_ptr<std::pair<int,int>> & position, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::shared_ptr<Figure> figureOnPosition = getFigureOnPosition(position, figuresOnBoard);
    if(figureOnPosition == nullptr)
        return true;
    return false;
}

bool MovementsPositionState::isEnemyFigureOnPosition(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, const std::shared_ptr<std::pair<int,int>> & calculatedPosition)
{
    std::shared_ptr<Figure> figureOnPosition = getFigureOnPosition(calculatedPosition, figuresOnBoard);
    if(isFree(calculatedPosition, figuresOnBoard))
        return false;
    if(figure->getColor() != figureOnPosition->getColor())
        return true;
    return false;
}
bool MovementsPositionState::isTeamFigureOnPosition (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, const std::shared_ptr<std::pair<int,int>> & calculatedPosition)
{
    std::shared_ptr<Figure> figureOnPosition = getFigureOnPosition(calculatedPosition, figuresOnBoard);
    if(isFree(calculatedPosition, figuresOnBoard))
        return false;
    if(figure->getColor() == figureOnPosition->getColor())
        return true;
    return false;
}