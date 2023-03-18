#pragma once
#include "Figure.hpp"


namespace chess
{

static size_t playerCounter = 0;
std::string DEFAULT_PLAYER_NAME = "Player " + std::to_string(playerCounter); 

class Player 
{
public:
    
    Player(Figure::Color figureColor, std::string name = DEFAULT_PLAYER_NAME); 

    std::string getName();
    Figure::Color getAsignedFigureColor();

private:

        std::string name;
        Figure::Color asignedFigureColor;
};

}