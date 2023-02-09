#include "MovementsPawn.hpp"

std::vector<std::pair<int,int>> MovementsPawn::getMovements(const std::shared_ptr<Pawn> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    std::vector<std::pair<int,int>> movements;
    movements.reserve(3);

    //front
    
    std::pair<int,int> front = figure->getPosition();

    //If white, add one position
    if(figure->getColor() == Figure::WHITE)
        front.second = front.second-1;
    //If black, sub one position
    else
        front.second = front.second+1;
    //TODO depending on return, could be last (to take queen) or no possible movements. For now, empty vector. Maby -1,-1 on the end?
    //If front position out of table, not possible movements 
    if(front.second>7 || front.second<0)
        return movements;
    
    //Check if front position is taken by anothe figure
    bool positionTaken = false;
    size_t countFiguresOnBoard = 0;
    while(!positionTaken && countFiguresOnBoard < figuresOnBoard.size())
    {
        if(figuresOnBoard.at(countFiguresOnBoard)->getPosition() == front)
            positionTaken=true;

        ++countFiguresOnBoard;
    }
    if(!positionTaken)
        movements.push_back(front);


     //Check if front diagonal is taken by rival figure
    bool enpassantFigure = false;
    countFiguresOnBoard = 0;
    //Calc provisional movements. 
    //TODO right and left are relative to figure. On this case is ok but for methods better to use nort waste,..
    std::pair<int,int> frontRight(front.first+1, front.second);

    //Not necessary to check, but to avoid no necessary iterations
    if(frontRight.first<=7)
    while(!enpassantFigure && countFiguresOnBoard < figuresOnBoard.size())
    {
        if(figuresOnBoard.at(countFiguresOnBoard)->getPosition() == frontRight)
        if(figuresOnBoard.at(countFiguresOnBoard)->getColor() != figure->getColor())
        {
            movements.push_back(frontRight);
            enpassantFigure = true;
        }
        ++countFiguresOnBoard;
    }

    //Same for left position
    std::pair<int,int> frontLeft(front.first-1, front.second);
    enpassantFigure = false;
    countFiguresOnBoard = 0;
    if(frontLeft.first>=0)
    while(!enpassantFigure && countFiguresOnBoard < figuresOnBoard.size())
    {
        if(figuresOnBoard.at(countFiguresOnBoard)->getPosition() == frontLeft)
        if(figuresOnBoard.at(countFiguresOnBoard)->getColor() != figure->getColor())
        {
            movements.push_back(frontLeft);
            enpassantFigure = true;
        }
        ++countFiguresOnBoard;
    }

    return movements;
}
