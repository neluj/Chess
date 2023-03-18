#include "Player.hpp"

using namespace chess;

Player::Player(Figure::Color figureColor, std::string name)
{
    this->asignedFigureColor        = figureColor;
    this->name                      = name;
}

std::string Player::getName()
{
    return name;
}

Figure::Color Player::getAsignedFigureColor()
{
    return asignedFigureColor;
}