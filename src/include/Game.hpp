#pragma once
#include "RenderizerSFML.hpp"


class Board;

class Game 
{
public:

    Game();
    void MainLoop() ;

private:

    void drawSFML(RenderWindow & window);
    void mouseLeftClick(int x, int y);

    std::shared_ptr<Board> board;
    std::vector< std::shared_ptr<RenderizerSFML> > renderizers;
    std::vector<std::pair<int,int>> possibleMovements;

};