#pragma once
#include "MovementsPositionState.hpp"
#include "Figure.hpp"

namespace chess
{


//Given a movement, iterates until 
//1.-the end of the board,
//2.-A team mate is founded,
//3.-An enemy is founded and it captured,
template<typename MovementType, std::shared_ptr<std::pair<int,int>>(MovementType::*MovementMethod)(const std::shared_ptr<std::pair<int,int>> & )>
std::vector<std::shared_ptr<std::pair<int,int>>> onDeep(const std::shared_ptr<MovementType> movementType, const std::shared_ptr<const Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::vector<std::shared_ptr<std::pair<int,int>>> onDeep;
    onDeep.reserve(8);
    std::shared_ptr<std::pair<int,int>> hipoteticPosition = std::make_shared<std::pair<int,int>>(figure->getPosition()->first, figure->getPosition()->second);
    std::shared_ptr<std::pair<int,int>> newPosition = ((*movementType).*MovementMethod)(hipoteticPosition);
    bool capture = false;

    MovementsPositionState positionState;
    while(positionState.positionExist(newPosition) && !positionState.isTeamFigureOnPosition(figure, figuresOnBoard, newPosition) && capture==false)
    {
        std::shared_ptr<Figure> figureOnNewPosition = positionState.getFigureOnPosition(newPosition, figuresOnBoard);
        if(figureOnNewPosition != nullptr)
        if(figureOnNewPosition->getColor() != figure->getColor())
        {
            capture = true;
        }
        onDeep.push_back(newPosition);
        hipoteticPosition = std::make_shared<std::pair<int,int>>(newPosition->first, newPosition->second);
        newPosition = ((*movementType).*MovementMethod)(hipoteticPosition);

    }    
    return onDeep; 
}

}