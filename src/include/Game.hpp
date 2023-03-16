#pragma once
#include <utility>
#include "RenderizerSFML.hpp"

namespace chess
{

class Board;

class Game 
{
public:

    Game();
    void MainLoop() ;

private:

    void mouseLeftClick(int x, int y);
    bool clickedInsideBoard(int x, int y);
    std::shared_ptr<std::pair<int,int>> getBoardPositionFromClicked(int x, int y);
    void updateSFMLObjects(RenderWindow & window);
    void draw(RenderWindow & window);
    
    Sprite boardSprite;
    Texture boardTexture;
    std::shared_ptr<Board> board;
    std::vector< std::shared_ptr<RenderizerSFML> > renderizers;

};

}