#include "ChessManager.hpp"

void ChessManager::run()
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
        for(std::shared_ptr<Figure> fig : figureManager.getFigures())
        {
            window.draw(*fig->getSprite());
        }
        window.display();
    }   
}

void ChessManager::mouseLeftClick(int x, int y)
{
    for(std::shared_ptr<Figure> fig : figureManager.getFigures())
    {
        if (fig->getSprite()->getGlobalBounds().contains(x,y))
        {
            fig->updatePosition(5,5);
        } 
    }       
}