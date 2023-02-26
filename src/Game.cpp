#include "Game.hpp"
#include "Board.hpp"
#include "FigureRenderizerSFML.hpp"
#include "PossibleMovementsRenderizerSFML.hpp"

//TODO borrar
#include "Figure.hpp"

Game::Game()
{
    board            =  std::make_shared<Board>(); 
    renderizers.push_back(std::make_shared<FigureRenderizerSFML>(board->getFigures()));
    renderizers.push_back(std::make_shared<PossibleMovementsRenderizerSFML>(&possibleMovements));
}


void Game::MainLoop()
{
    Sprite boardSprite;

    // Load board
    Texture boardTexture;
    boardTexture.loadFromFile("images/board.png");
    boardSprite.setTexture(boardTexture);   


    RenderWindow window(VideoMode(512, 520), "The Chess! (press SPACE)");

    Vector2f offset(28,28);

    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window) - Vector2i(offset);
        Event e;
        if (window.pollEvent(e))
        {
            if (e.type == Event::MouseButtonPressed)
            {
                if (e.key.code == Mouse::Left)
                {
                    mouseLeftClick(pos.x,pos.y);            
                }  
            }
        }
        
        window.clear();
        window.draw(boardSprite);
        drawSFML(window);
        window.display();
    }   
}


void Game::mouseLeftClick(int x, int y)
{
    //if(figureIsSelected)
    //{
    //    if()
    //    figureManager.updatePosition(...);
    //}
    //else 
    //{
    //    figureManager.selecFigure(...);
    //}
    //
    //figureManager.updatePosition();
    //for(std::shared_ptr<Figure> figImag : figureManager.getFigureImages())
    //{
    //    if (figImag->getSprite()->getGlobalBounds().contains(x,y))
    //    {
    //        figImag->updatePosition(5,5);
    //    } 
    //}       
}

void Game::drawSFML(RenderWindow & window)
{
    for(auto render : renderizers)
    {
        render->draw(window);
    }
}