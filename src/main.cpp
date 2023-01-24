#include <SFML/Graphics.hpp>
#include <time.h>
#include "iostream"

using namespace sf;

Sprite figures[2][16]; //figures

Sprite boardSprite;


int boardRepresentation[8][8] = 
    {   
        {-1,-2,-3,-4,-5,-3,-2,-1},
        {-6,-6,-6,-6,-6,-6,-6,-6},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {6, 6, 6, 6, 6, 6, 6, 6},
        {1, 2, 3, 4, 5, 3, 2, 1}
    };


void loadFigures(const Texture & figureTexture)
{
    int size = 64;
    Sprite figureMoldes[2][6];
    for (int i = 0; i < 2; i++)
    { 
        for (int j = 0; j < 6; j++)
        {
            figureMoldes[i][j].setTexture(figureTexture);
            figureMoldes[i][j].setTextureRect(IntRect(size * j , size * i, size, size));
        }
    }   
    
    size_t whiteCounter = 0, blackCounter = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++)
        {
            if(boardRepresentation[i][j] != 0)
            {
                size_t y = boardRepresentation[i][j]>0?1:0;  
                if(y == 0)
                {
                    figures[y][blackCounter] = figureMoldes[y][abs(boardRepresentation[i][j])-1];
                    figures[y][blackCounter].setPosition(size * j, size * i);
                    blackCounter++;
                }
                else if (y == 1)
                {
                    figures[y][whiteCounter] = figureMoldes[y][(boardRepresentation[i][j]-1)];
                    figures[y][whiteCounter].setPosition(size * j, size * i);
                    whiteCounter++;
                }            
            } 
        
        }    
    }
    
}

void loadBoard(const Texture & boardTexture)
{
    boardSprite.setTexture(boardTexture);   
}

void drawFigures(RenderWindow & window)
{
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 16; j++)
        {
            window.draw(figures[i][j]);
        }
    }
}
int main()
{
    RenderWindow window(VideoMode(512, 520), "The Chess! (press SPACE)");

    // Load board
    Texture boardTexture;
    boardTexture.loadFromFile("images/board.png");
    loadBoard(boardTexture);

    // Load figures
    Texture figureTexture;
    figureTexture.loadFromFile("images/figures.png");
    loadFigures(figureTexture);


    while (window.isOpen())
    {

        Event e;
        while (window.pollEvent(e))
        {

        }
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            //boardRepresentation[0][0] = -6;
            //boardRepresentation[1][0] = -1;
            //loadFigures(figureTexture);
        }

        window.clear();
        window.draw(boardSprite);
        drawFigures(window);

        window.display();

    }

    return 0;
}

