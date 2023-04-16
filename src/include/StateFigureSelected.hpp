#pragma once
#include "State.hpp"

namespace chess
{

class StateFigureSelected : public State
{

public:

    void clickOnMovemet(std::shared_ptr<const std::pair<int,int>> & clickedPosition)    override;
    void clickOnEmptyBoard()                                                            override;
    void clickOnUnselectedFigure(std::shared_ptr<Figure> figure)                        override;
    void clickOnSelectedFigure()                                                        override;
};

}