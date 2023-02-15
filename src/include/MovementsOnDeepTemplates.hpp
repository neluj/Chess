#pragma once
#include "MovementsPositionState.hpp"
#include "Figure.hpp"

//TODO refactorizar nombres y metodo
template<typename MovementType, std::pair<int,int>(MovementType::*MovementMethod)(std::pair<int,int>)>
std::vector<std::pair<int,int>> onDeep(const std::shared_ptr<MovementType> movementType, const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::vector<std::pair<int,int>> onDeep;
    onDeep.reserve(8);
    std::shared_ptr<Figure> hitoteticFigure = figure->clone();
    std::pair<int,int> actualPosition = figure->getPosition();
    std::pair<int,int> newPosition = ((*movementType).*MovementMethod)(hitoteticFigure->getPosition());
    bool empassant = false;

    MovementsPositionState positionState;
    while(positionState.positionExist(newPosition) && !positionState.isTeamFigureOnPosition(figure, figuresOnBoard, newPosition) && empassant==false)
    {
        onDeep.push_back(newPosition);
        hitoteticFigure->updatePosition(newPosition.first, newPosition.second);
        newPosition = ((*movementType).*MovementMethod)(hitoteticFigure->getPosition());
        std::shared_ptr<Figure> figureOnNewPosition = positionState.getFigureOnPosition(newPosition, figuresOnBoard);
        if(figureOnNewPosition != nullptr)
        if(figureOnNewPosition->getColor() != figure->getColor())
        {
            onDeep.push_back(newPosition);
            empassant = true;
        }
    }    
    return onDeep; 
}