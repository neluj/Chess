#include "Board.hpp"
#include "King.hpp"
#include "Rook.hpp"
#include "Pawn.hpp"
#include "Knight.hpp"
#include "Queen.hpp"
#include "Bishop.hpp"

#include "Player.hpp"

#include "StateNothingSelected.hpp"

#include <algorithm>

using namespace chess;


Board::Board(State* newState) : state(nullptr)
{
    figures.reserve(32);
    possibleMovements = std::make_shared<std::list<std::shared_ptr<const std::pair<int,int>>>>();

    playerWhite = std::make_shared<Player>(Figure::WHITE);
    playerBlack = std::make_shared<Player>(Figure::BLACK);
    turnPlayer = playerWhite;

    setInitialState();
    updateState(newState);
    
}

Board::~Board()
{
    delete state;
}

void Board::setInitialState()
{
    figures.reserve(32);

    figures.push_back(std::make_shared<King>(Figure::WHITE, std::make_shared<std::pair<int, int>>(4, 7)));
    figures.push_back(std::make_shared<King>(Figure::BLACK, std::make_shared<std::pair<int, int>>(4, 0)));

    figures.push_back(std::make_shared<Queen>(Figure::WHITE, std::make_shared<std::pair<int, int>>(3, 7)));
    figures.push_back(std::make_shared<Queen>(Figure::BLACK, std::make_shared<std::pair<int, int>>(3, 0)));

    figures.push_back(std::make_shared<Rook>(Figure::WHITE, std::make_shared<std::pair<int, int>>(0, 7)));
    figures.push_back(std::make_shared<Rook>(Figure::WHITE, std::make_shared<std::pair<int, int>>(7, 7)));
    figures.push_back(std::make_shared<Rook>(Figure::BLACK, std::make_shared<std::pair<int, int>>(0, 0)));
    figures.push_back(std::make_shared<Rook>(Figure::BLACK, std::make_shared<std::pair<int, int>>(7, 0)));

    figures.push_back(std::make_shared<Bishop>(Figure::WHITE, std::make_shared<std::pair<int, int>>(2, 7)));
    figures.push_back(std::make_shared<Bishop>(Figure::WHITE, std::make_shared<std::pair<int, int>>(5, 7)));
    figures.push_back(std::make_shared<Bishop>(Figure::BLACK, std::make_shared<std::pair<int, int>>(2, 0)));
    figures.push_back(std::make_shared<Bishop>(Figure::BLACK, std::make_shared<std::pair<int, int>>(5, 0)));

    figures.push_back(std::make_shared<Knight>(Figure::WHITE, std::make_shared<std::pair<int, int>>(1, 7)));
    figures.push_back(std::make_shared<Knight>(Figure::WHITE, std::make_shared<std::pair<int, int>>(6, 7)));
    figures.push_back(std::make_shared<Knight>(Figure::BLACK, std::make_shared<std::pair<int, int>>(1, 0)));
    figures.push_back(std::make_shared<Knight>(Figure::BLACK, std::make_shared<std::pair<int, int>>(6, 0)));


    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::make_shared<std::pair<int, int>>(0, 6)));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::make_shared<std::pair<int, int>>(1, 6)));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::make_shared<std::pair<int, int>>(2, 6)));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::make_shared<std::pair<int, int>>(3, 6)));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::make_shared<std::pair<int, int>>(4, 6)));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::make_shared<std::pair<int, int>>(5, 6)));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::make_shared<std::pair<int, int>>(6, 6)));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::make_shared<std::pair<int, int>>(7, 6)));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::make_shared<std::pair<int, int>>(0, 1)));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::make_shared<std::pair<int, int>>(1, 1)));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::make_shared<std::pair<int, int>>(2, 1)));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::make_shared<std::pair<int, int>>(3, 1)));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::make_shared<std::pair<int, int>>(4, 1)));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::make_shared<std::pair<int, int>>(5, 1)));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::make_shared<std::pair<int, int>>(6, 1)));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::make_shared<std::pair<int, int>>(7, 1)));

}
void Board::updateState(State* newState)
{
    if (this->state != nullptr)
      delete this->state;
    this->state = newState;
    this->state->setBoard(this);
}
const std::vector<std::shared_ptr<Figure>> & Board::getFigures() const
{
    return figures;
}

const std::shared_ptr<std::list<std::shared_ptr<const std::pair<int,int>>>> Board::getPossibleMovements() const
{
    return possibleMovements;
}

std::shared_ptr<Figure> Board::getFigureFromPosition(std::shared_ptr<const std::pair<int,int>> & position) const
{

    auto figureIterator = std::find_if (figures.begin(), figures.end(), 
        [&position](const std::shared_ptr<Figure> &fig){return (fig->getPosition()->first == position->first && fig->getPosition()->second == position->second);}
    );

    if(figureIterator == figures.end())
        return nullptr;
    
    return *figureIterator;

}

State* Board::getState()
{
    return state;
}

const std::shared_ptr<const Figure> Board::getSelectedFigure()
{
    return selectedFigure;
}

void Board::selectFigure(std::shared_ptr<Figure> figure)
{
    selectedFigure = figure;
    auto vecPossibleMovements = figure->getPossibleMovements(figures);
    possibleMovements->clear();
    std::copy(vecPossibleMovements.begin(), vecPossibleMovements.end(), std::back_inserter(*possibleMovements));
}

void Board::updateTurnPlayer()
{
    if(turnPlayer == playerWhite)
    {
        turnPlayer = playerBlack;
    }
    else
        turnPlayer = playerWhite;
}

std::shared_ptr<const Player> Board::getTurnPlayer()
{
    return turnPlayer;
}


void Board::unselectFigure()
{
    selectedFigure = nullptr;
    possibleMovements->clear();
}

//TODO cambiar a state del rival
void Board::moveSelectedFigure(std::shared_ptr<const std::pair<int,int>> & clickedPosition)
{   
    captureFigure(clickedPosition);
    if(selectedFigure != nullptr)
        selectedFigure->updatePosition(clickedPosition->first, clickedPosition->second);
}

bool Board::captureFigure(std::shared_ptr<const std::pair<int,int>> & clickedPosition)
{
    std::shared_ptr<Figure> capturedFigure = getFigureFromPosition(clickedPosition);
    if(capturedFigure != nullptr)
    {
        capturedFigure->updatePosition(8,0);
        return true;
    }
    return false;
}

bool Board::isCheckMateded(const std::shared_ptr<const Player> & player) const
{
    const std::shared_ptr<Figure> heroKing = getPlayersKing(player, figures);

    return isCheckMateded(heroKing, figures);
}

bool Board::isCheckMateded(const std::shared_ptr<Figure> & figureHero, const std::vector<std::shared_ptr<Figure>> & figuresSpot) const
{
    for(auto figureIt : figuresSpot)
    {
        if(figureIt->getColor() == figureHero->getColor())
        {
            // Calculates all possible movements for player
            std::vector<std::vector<std::shared_ptr<Figure>>> hipoteticSpots = hipoteticBoardSpots(figureIt, figuresSpot);

            // If there is at least one possible movement where the figure is not check, then the figure is not on checkMate
            for(auto hSpot : hipoteticSpots)
            if(!isChecked(figureHero, hSpot))
                return false;
        }
    }
    return true;
}



bool Board::isChecked(const std::shared_ptr<const Player> & player) const
{

    const std::shared_ptr<Figure> heroKing = getPlayersKing(player, figures);

    return isChecked(heroKing, figures);
}


bool Board::isChecked(const std::shared_ptr<Figure> & figureHero, const std::vector<std::shared_ptr<Figure>> & figuresSpot) const
{

    for(auto figureIt : figuresSpot)
    {
        if(figureHero->getColor() != figureIt->getColor())
        {
            auto figurePossibleMovements = figureIt->getPossibleMovements(figuresSpot);

            auto possibleMovementsIterator = std::find_if (
                figurePossibleMovements.begin(), figurePossibleMovements.end(), 
                [&figureHero](const std::shared_ptr<const std::pair<int,int>> &possibleMovement)
                {return (possibleMovement->first == figureHero->getPosition()->first && possibleMovement->second == figureHero->getPosition()->second);}
            );

            if(possibleMovementsIterator != figurePossibleMovements.end())
                return true;

        }
    }
    
    return false;    
}


size_t Board::getFigureIndexOnBoard(const std::shared_ptr< Figure> & figureHero, const std::vector<std::shared_ptr<Figure>> & figuresSpot) const
{
    size_t figureIndex = -1;

    bool figureIndexFounded{false};
    size_t figuresCounter = 0;
    while(!figureIndexFounded && figuresCounter < figuresSpot.size())
    {
        auto figure = figuresSpot[figuresCounter];
        if(figure == figureHero)
        {
            figureIndex = figuresCounter;
            figureIndexFounded = true;
        }

        figuresCounter++;
    }

    return figureIndex;
}

// TODO con esto solo vale para saber si es jaque mate, lo que hay que hacer es para cada movimiento de
// figura del color propio (no se distingue si es rey), comprobar si es jaque. Si es, es jaque mate.
std::vector<std::vector<std::shared_ptr<Figure>>> Board::hipoteticBoardSpots(const std::shared_ptr<Figure> & figureToCalculate, const std::vector<std::shared_ptr<Figure>> & figuresSpot) const
{
    std::vector<std::vector<std::shared_ptr<Figure>>> hipoteticBoardSpots;

    // Find index of the figure on board
    size_t figureIndex = getFigureIndexOnBoard(figureToCalculate,figuresSpot);

    //For each movement, create a possible spot
    auto possibleMovements = figureToCalculate->getPossibleMovements(figuresSpot);

    for(auto possibleMov : possibleMovements)
    {
        auto hipoteticFiguresOnBoard = figuresSpot;
        hipoteticFiguresOnBoard[figureIndex]->updatePosition(possibleMov->first, possibleMov->second);
        hipoteticBoardSpots.push_back(hipoteticFiguresOnBoard);
    }

    return hipoteticBoardSpots;

}

const std::shared_ptr<Figure> Board::getPlayersKing(const std::shared_ptr<const Player> & player, const std::vector<std::shared_ptr<Figure>> figuresSpot) const
{
    for(auto figureIt : figuresSpot)
    {
        if(figureIt->getType() == Figure::KING && figureIt->getColor() == player->getAsignedFigureColor())
        {
            return figureIt;
        }   
    }
    return nullptr;
}
