#pragma once
#include "State.hpp"

class StateNothingSelected : public State
{

public:
    StateNothingSelected(std::shared_ptr<Board> board);
    void clickOnMovemet(const std::pair<int,int> & position)    override;
    void clickOnEmptyBoard()                                    override;
    void clickOnFigure(std::shared_ptr<Figure> figure)          override;
};