#pragma once
#include "State.hpp"

namespace chess
{

class StateFigureSelected : public State
{

public:
    StateFigureSelected(std::shared_ptr<Board> board);
    void clickOnMovemet(const std::pair<int,int> & position)    override;
    void clickOnEmptyBoard()                                    override;
    void clickOnFigure(std::shared_ptr<Figure> figure)          override;
};

}