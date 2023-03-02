#pragma once
#include <utility>
#include "RenderizerSFML.hpp"


class Board;

class Game 
{
public:

    Game();
    void MainLoop() ;

private:

    void mouseLeftClick(int x, int y);
    bool clickedInsideBoard(int x, int y);
    std::pair<int,int> getBoardPositionFromClicked(int x, int y);
    void drawSFML(RenderWindow & window);

    std::shared_ptr<Board> board;
    std::vector< std::shared_ptr<RenderizerSFML> > renderizers;

};