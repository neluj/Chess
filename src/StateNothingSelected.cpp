#include "StateNothingSelected.hpp"
#include "Board.hpp"

StateNothingSelected::StateNothingSelected(std::shared_ptr<Board> board) :
    State::State(board)
{}

void StateNothingSelected::clickOnMovemet(const std::pair<int,int> & position)
{}   

void StateNothingSelected::clickOnEmptyBoard()                                
{}   

void StateNothingSelected::clickOnFigure(std::shared_ptr<Figure> figure)      
{
    board->selectFigure(figure);
}   