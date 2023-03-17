#include "Game.hpp"
#include "Board.hpp"
#include "FigureRenderizerSFML.hpp"
#include "PossibleMovementsRenderizerSFML.hpp"

// TODO borrar
#include "Figure.hpp"
#include "StateNothingSelected.hpp"

using namespace chess;


const unsigned int BOARD_SIZE_X = 512;
const unsigned int BOARD_SIZE_Y = 512;

const unsigned short SQUARES_SIZE = 8;

Game::Game()
{
    board = std::make_shared<Board>(new StateNothingSelected);
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
                    std::shared_ptr<const std::pair<int, int>> selectedPosition = getBoardPositionFromClicked(pos.x, pos.y);
                    mouseLeftClick(selectedPosition);
                    draw(window);
                }
            }
        }
    }
}

void Game::mouseLeftClick(std::shared_ptr<const std::pair<int,int>> & clickedPosition)
{
    bool moved = false;
    if (clickedInsideBoard(clickedPosition))
    {
        auto possibleMovementsIterator = board->getPossibleMovements()->begin();
        while(!moved && possibleMovementsIterator != board->getPossibleMovements()->end())
        {
            if(((*possibleMovementsIterator)->first == clickedPosition->first) && ((*possibleMovementsIterator)->second == clickedPosition->second))
            {
                board->getState()->clickOnMovemet(clickedPosition);
                moved = true;
            }
            else
            {
                ++possibleMovementsIterator;
            }
        }
        if(!moved)
        {
            std::shared_ptr<Figure> figure = board->getFigureFromPosition(clickedPosition);
    
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
}

bool Game::clickedInsideBoard(std::shared_ptr<const std::pair<int,int>> & clickedPosition) const
{
    if (clickedPosition->first > BOARD_SIZE_X || clickedPosition->second > BOARD_SIZE_Y)
        return false;

    return true;
}

std::shared_ptr<std::pair<int, int>> Game::getBoardPositionFromClicked(int x, int y) const
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