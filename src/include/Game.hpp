#pragma once
#include "Board.hpp"
#include <memory>

class FigureRenderizer;

class Game 
{
public:

    Game();
    void MainLoop() ;

private:

    void mouseLeftClick(int x, int y);


    std::shared_ptr<Board> board;
    std::shared_ptr<FigureRenderizer> figureRenderizer;

};