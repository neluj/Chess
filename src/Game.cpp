#include "Game.hpp"
#include "Board.hpp"
#include "FigureRenderizerSFML.hpp"
#include "PossibleMovementsRenderizerSFML.hpp"

// TODO borrar
#include "Figure.hpp"
#include "State.hpp"

using namespace chess;


const unsigned int BOARD_SIZE_X = 512;
const unsigned int BOARD_SIZE_Y = 512;

const unsigned short SQUARES_SIZE = 8;

Game::Game()
{
    board = std::make_shared<Board>();
    renderizers.push_back(std::make_shared<FigureRenderizerSFML>(board->getFigures()));
    renderizers.push_back(std::make_shared<PossibleMovementsRenderizerSFML>(board->getPossibleMovements()));
}

void Game::MainLoop()
{

    // Load board
    boardTexture.loadFromFile("images/board.png");
    boardSprite.setTexture(boardTexture);
 
    RenderWindow window(VideoMode(BOARD_SIZE_X, BOARD_SIZE_Y), "Chess");
    draw(window);

    Vector2f offset;

    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window) - Vector2i(offset);
        Event e;
        if (window.waitEvent(e))
        {
            if (e.type == Event::MouseButtonPressed)
            {
                if (e.key.code == Mouse::Left)
                {
                    mouseLeftClick(pos.x, pos.y);
                    draw(window);
                }
            }
        }
    }
}

void Game::mouseLeftClick(int x, int y)
{
    if (clickedInsideBoard(x, y))
    {
        std::shared_ptr<std::pair<int, int>> selectedPosition = getBoardPositionFromClicked(x, y);
        std::shared_ptr<Figure> figure = board->getFigureFromPosition(selectedPosition);

        if (figure != nullptr)
        {
            board->getState()->clickOnFigure(figure);
        }
        else
        {
            board->getState()->clickOnEmptyBoard();
        }
    }
}

bool Game::clickedInsideBoard(int x, int y)
{
    if (x > BOARD_SIZE_X || y > BOARD_SIZE_Y)
        return false;

    return true;
}

std::shared_ptr<std::pair<int, int>> Game::getBoardPositionFromClicked(int x, int y)
{
    int posX = (x * SQUARES_SIZE) / BOARD_SIZE_X;
    int posY = (y * SQUARES_SIZE) / BOARD_SIZE_Y;

    return std::make_shared<std::pair<int, int>>(posX, posY);
}

void Game::updateSFMLObjects(RenderWindow &window)
{
    for (auto render : renderizers)
    {
        render->draw(window);
    }
}

void Game::draw(RenderWindow &window)
{
    window.clear();
    window.draw(boardSprite);
    updateSFMLObjects(window);
    window.display();
}