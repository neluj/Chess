#include "Player.hpp"

using namespace chess;

Player::Player(Figure::Color figureColor, std::string name)
{
    this->asignedFigureColor        = figureColor;
    this->name                      = name;
    playerCounter++;
}

Player::Player(Figure::Color figureColor)
{
    this->asignedFigureColor        = figureColor;

    std::string DEFAULT_PLAYER_NAME = "Player " + std::to_string(playerCounter); 

    this->name = DEFAULT_PLAYER_NAME;
    playerCounter++;

}

std::string Player::getName()
{
    return name;
}

Figure::Color Player::getAsignedFigureColor()
{
    return asignedFigureColor;
}