#include "MovementsKnight.hpp"

std::vector<std::pair<int,int>> MovementsKnight::getMovements(const std::shared_ptr<Knight> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::vector<std::pair<int,int>> movements;
    movements.reserve(8);

    //up-left
    std::pair<int,int> upLeft(figure->getPosition().first-1, figure->getPosition().second-2);
    if(positionState.checkPositionState(figure,figuresOnBoard,upLeft).first==-1)
        movements.push_back(upLeft);

    //up-right
    std::pair<int,int> upRight(figure->getPosition().first+1, figure->getPosition().second-2);
    if(positionState.checkPositionState(figure,figuresOnBoard,upLeft).first==-1)
        movements.push_back(upRight);

    //right-up
    std::pair<int,int> rightUp(figure->getPosition().first+2, figure->getPosition().second-1);
    if(positionState.checkPositionState(figure,figuresOnBoard,upLeft).first==-1)
        movements.push_back(rightUp);

    //right-down
    std::pair<int,int> rightDown(figure->getPosition().first+2, figure->getPosition().second+1);
    if(positionState.checkPositionState(figure,figuresOnBoard,upLeft).first==-1)
        movements.push_back(rightDown);

    //down-right
    std::pair<int,int> downRight(figure->getPosition().first+1, figure->getPosition().second+2);
    if(positionState.checkPositionState(figure,figuresOnBoard,upLeft).first==-1)
        movements.push_back(downRight);

    //down-left
    std::pair<int,int> downLeft(figure->getPosition().first-1, figure->getPosition().second+2);
    if(positionState.checkPositionState(figure,figuresOnBoard,upLeft).first==-1)
        movements.push_back(downLeft);

    //left-down
    std::pair<int,int> leftDown(figure->getPosition().first-2, figure->getPosition().second+1);
    if(positionState.checkPositionState(figure,figuresOnBoard,upLeft).first==-1)
        movements.push_back(leftDown);

    //left-up
    std::pair<int,int> leftUp(figure->getPosition().first-2, figure->getPosition().second-1);
    if(positionState.checkPositionState(figure,figuresOnBoard,upLeft).first==-1)
        movements.push_back(leftUp);

    return movements;
}
