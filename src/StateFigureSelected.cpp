#include "StateFigureSelected.hpp"
#include "StateNothingSelected.hpp"
#include "Board.hpp"

using namespace chess;


void StateFigureSelected::clickOnMovemet(std::shared_ptr<const std::pair<int,int>> & clickedPosition)
{
    board->moveSelectedFigure(clickedPosition);
    board->updateState(new StateNothingSelected);
}   

void StateFigureSelected::clickOnEmptyBoard()                                
{
    board->unselectFigure();
    board->updateState(new StateNothingSelected);
}   

void StateFigureSelected::clickOnFigure(std::shared_ptr<Figure> figure)      
{
    board->unselectFigure();
    board->updateState(new StateNothingSelected);
}   