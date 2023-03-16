#include "StateFigureSelected.hpp"
#include "Board.hpp"

using namespace chess;


StateFigureSelected::StateFigureSelected(std::shared_ptr<Board> board) :
    State::State(board)
{}

void StateFigureSelected::clickOnMovemet(const std::pair<int,int> & position)
{
    board->moveSelectedFigure(position);
}   

void StateFigureSelected::clickOnEmptyBoard()                                
{}   

void StateFigureSelected::clickOnFigure(std::shared_ptr<Figure> figure)      
{
    board->unselectFigure();
}   