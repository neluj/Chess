#include "Board.hpp"
#include "King.hpp"
#include "Rook.hpp"
#include "Pawn.hpp"
#include "Knight.hpp"
#include "Queen.hpp"
#include "Bishop.hpp"


// TODO
#include "StateNothingSelected.hpp"
#include "StateFigureSelected.hpp"


#include <algorithm>

Board::Board()
{
    figures.reserve(32);
    possibleMovements = std::make_shared<std::list<std::shared_ptr<const std::pair<int,int>>>>();
    setInitialState();
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
    // TODO
    state = std::make_shared<StateNothingSelected>(std::make_shared<Board>(*this));

}

const std::vector<std::shared_ptr<Figure>> & Board::getFigures() const
{
    return figures;
}

const std::shared_ptr<std::list<std::shared_ptr<const std::pair<int,int>>>> Board::getPossibleMovements() const
{
    return possibleMovements;
}

std::shared_ptr<Figure> Board::getFigureFromPosition(const std::shared_ptr<std::pair<int,int>> & position) const
{

    auto figureIterator = std::find_if (figures.begin(), figures.end(), 
        [&position](const std::shared_ptr<Figure> &fig){return (fig->getPosition()->first == position->first && fig->getPosition()->second == position->second);}
    );

    if(figureIterator == figures.end())
        return nullptr;
    
    return *figureIterator;

}

const std::shared_ptr<State> Board::getState()
{
    return state;
}

void Board::selectFigure(std::shared_ptr<Figure> figure)
{
    selectedFigure = figure;
    auto vecPossibleMovements = figure->getPossibleMovements(figures);
    possibleMovements->clear();
    std::copy(vecPossibleMovements.begin(), vecPossibleMovements.end(), std::back_inserter(*possibleMovements));
    state = std::make_shared<StateFigureSelected>(std::make_shared<Board>(*this));
}

void Board::unselectFigure()
{
    selectedFigure = nullptr;
    possibleMovements->clear();
    state = std::make_shared<StateNothingSelected>(std::make_shared<Board>(*this));
}

//TODO cambiar a state del rival
void Board::moveSelectedFigure(const std::pair<int,int> & position)
{
    if(selectedFigure != nullptr)
        selectedFigure->updatePosition(position.first, position.second);
}
