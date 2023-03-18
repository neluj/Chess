#pragma once
#include "Figure.hpp"


namespace chess
{

static size_t playerCounter = 0;

class Player 
{
public:

    Player(Figure::Color figureColor, std::string name); 
    Player(Figure::Color figureColor); 

    std::string getName();
    Figure::Color getAsignedFigureColor();

private:

        std::string name;
        Figure::Color asignedFigureColor;

};

}