#pragma once
#include <SFML/Graphics.hpp>
#include "FigureManager.hpp"

using namespace sf;
class ChessManager 
{
public:

    void run() ;

private:

    void mouseLeftClick(int x, int y);

    FigureManager figureManager;

};