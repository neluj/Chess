#include "StateNothingSelected.hpp"
#include "StateFigureSelected.hpp"

#include "Board.hpp"

using namespace chess;


void StateNothingSelected::clickOnMovemet(std::shared_ptr<const std::pair<int,int>> & clickedPosition)
{}   

void StateNothingSelected::clickOnEmptyBoard()                                
{}   

void StateNothingSelected::clickOnFigure(std::shared_ptr<Figure> figure)      
{
    board->selectFigure(figure);
    board->updateState(new StateFigureSelected);
}   