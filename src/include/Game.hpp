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

    void mouseLeftClick(std::shared_ptr<const std::pair<int,int>> & clickedPosition) ;
    bool clickedInsideBoard(std::shared_ptr<const std::pair<int,int>> & clickedPosition) const;
    std::shared_ptr<std::pair<int,int>> getBoardPositionFromClicked(int x, int y) const;
    void updateSFMLObjects(RenderWindow & window);
    void draw(RenderWindow & window);

    bool eventClickOnPossibleMovement   (std::shared_ptr<const std::pair<int,int>> & clickedPosition);
    bool eventClickOnFigure             (std::shared_ptr<const std::pair<int,int>> & clickedPosition);
    bool eventClickOnEmptyBoard         (std::shared_ptr<const std::pair<int,int>> & clickedPosition);
    
    Sprite boardSprite;
    Texture boardTexture;
    std::shared_ptr<Board> board;
    std::vector< std::shared_ptr<RenderizerSFML> > renderizers;

};

}