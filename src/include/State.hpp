#pragma once
#include <memory>
#include <utility>

namespace chess
{

class Board;
class Figure;

class State
{
public:
    
    virtual ~State(){}
    void setBoard(Board *board);
    virtual void clickOnMovemet(std::shared_ptr<const std::pair<int,int>> & clickedPosition)    = 0;
    virtual void clickOnEmptyBoard()                                    = 0;
    virtual void clickOnFigure(std::shared_ptr<Figure> figure)          = 0;

protected:

    Board *board;
};

}