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
    State(std::shared_ptr<Board> board);
    virtual ~State(){}
    virtual void clickOnMovemet(const std::pair<int,int> & position)    = 0;
    virtual void clickOnEmptyBoard()                                    = 0;
    virtual void clickOnFigure(std::shared_ptr<Figure> figure)          = 0;

protected:

    std::shared_ptr<Board> board;
};

}