#pragma once
#include "State.hpp"

namespace chess
{

class StateNothingSelected : public State
{

public:

    void clickOnMovemet(std::shared_ptr<const std::pair<int,int>> & clickedPosition)    override;
    void clickOnEmptyBoard()                                                            override;
    void clickOnFigure(std::shared_ptr<Figure> figure)                                  override;
};

}