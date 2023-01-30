#include <SFML/Graphics.hpp>
#include "Rook.hpp"
#include "Pawn.hpp"
#include "Bishop.hpp"

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

    Bishop witheRook(Figure::WHITE, std::pair<int, int>(2, 7));


    RenderWindow window(VideoMode(512, 520), "The Chess! (press SPACE)");

    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {}
        window.clear();
        window.draw(boardSprite);
        window.draw(*witheRook.getSprite());
        window.display();
    }

}