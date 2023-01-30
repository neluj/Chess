#include <SFML/Graphics.hpp>
#include "FigureManager.hpp"

using namespace sf;
Sprite boardSprite;

void loadBoard(const Texture & boardTexture)
{
    boardSprite.setTexture(boardTexture);   
}


int main()
{
    // Load board
    Texture boardTexture;
    boardTexture.loadFromFile("images/board.png");
    loadBoard(boardTexture);

    FigureManager figureManager;

    RenderWindow window(VideoMode(512, 520), "The Chess! (press SPACE)");

    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {}
        window.clear();
        window.draw(boardSprite);
        for(std::shared_ptr<Figure> fig : figureManager.getFigures())
        {
            window.draw(*fig->getSprite());
        }
        window.display();
    }

}