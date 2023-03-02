#include "Board.hpp"
#include "King.hpp"
#include "Rook.hpp"
#include "Pawn.hpp"
#include "Knight.hpp"
#include "Queen.hpp"
#include "Bishop.hpp"

#include "MovementsKing.hpp"
#include "MovementsRook.hpp"
#include "MovementsPawn.hpp"
#include "MovementsKnight.hpp"
#include "MovementsQueen.hpp"
#include "MovementsBishop.hpp"

// TODO
#include "StateNothingSelected.hpp"
#include "StateFigureSelected.hpp"


#include <algorithm>

Board::Board()
{
    movementsKing   = std::make_shared<MovementsKing   >();
    movementsRook   = std::make_shared<MovementsRook   >();
    movementsPawn   = std::make_shared<MovementsPawn   >();
    movementsKnight = std::make_shared<MovementsKnight >();
    movementsQueen  = std::make_shared<MovementsQueen  >();
    movementsBishop = std::make_shared<MovementsBishop >();

    figures.reserve(32);
    setInitialState();
}

void Board::setInitialState()
{
    figures.reserve(32);

    figures.push_back(std::make_shared<King>(Figure::WHITE, std::pair<int, int>(4, 7), movementsKing));
    figures.push_back(std::make_shared<King>(Figure::BLACK, std::pair<int, int>(4, 0), movementsKing));

    figures.push_back(std::make_shared<Queen>(Figure::WHITE, std::pair<int, int>(3, 7), movementsQueen));
    figures.push_back(std::make_shared<Queen>(Figure::BLACK, std::pair<int, int>(3, 0), movementsQueen));

    figures.push_back(std::make_shared<Rook>(Figure::WHITE, std::pair<int, int>(0, 7), movementsRook));
    figures.push_back(std::make_shared<Rook>(Figure::WHITE, std::pair<int, int>(7, 7), movementsRook));
    figures.push_back(std::make_shared<Rook>(Figure::BLACK, std::pair<int, int>(0, 0), movementsRook));
    figures.push_back(std::make_shared<Rook>(Figure::BLACK, std::pair<int, int>(7, 0), movementsRook));

    figures.push_back(std::make_shared<Bishop>(Figure::WHITE, std::pair<int, int>(2, 7), movementsBishop));
    figures.push_back(std::make_shared<Bishop>(Figure::WHITE, std::pair<int, int>(5, 7), movementsBishop));
    figures.push_back(std::make_shared<Bishop>(Figure::BLACK, std::pair<int, int>(2, 0), movementsBishop));
    figures.push_back(std::make_shared<Bishop>(Figure::BLACK, std::pair<int, int>(5, 0), movementsBishop));

    figures.push_back(std::make_shared<Knight>(Figure::WHITE, std::pair<int, int>(1, 7), movementsKnight));
    figures.push_back(std::make_shared<Knight>(Figure::WHITE, std::pair<int, int>(6, 7), movementsKnight));
    figures.push_back(std::make_shared<Knight>(Figure::BLACK, std::pair<int, int>(1, 0), movementsKnight));
    figures.push_back(std::make_shared<Knight>(Figure::BLACK, std::pair<int, int>(6, 0), movementsKnight));


    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(0, 6), movementsPawn));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(1, 6), movementsPawn));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(2, 6), movementsPawn));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 6), movementsPawn));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(4, 6), movementsPawn));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(5, 6), movementsPawn));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(6, 6), movementsPawn));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(7, 6), movementsPawn));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::pair<int, int>(0, 1), movementsPawn));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::pair<int, int>(1, 1), movementsPawn));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::pair<int, int>(2, 1), movementsPawn));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::pair<int, int>(3, 1), movementsPawn));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::pair<int, int>(4, 1), movementsPawn));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::pair<int, int>(5, 1), movementsPawn));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::pair<int, int>(6, 1), movementsPawn));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::pair<int, int>(7, 1), movementsPawn));
    // TODO
    state = std::make_shared<StateNothingSelected>(std::make_shared<Board>(*this));

}

const std::vector<std::shared_ptr<Figure>> & Board::getFigures() const
{
    return figures;
}

const std::vector<std::pair<int,int>> Board::getPossibleMovements() const
{
    return possibleMovements;
}

std::shared_ptr<Figure> Board::getFigureFromPosition(const std::pair<int,int> & position) const
{

    auto figureIterator = std::find_if (figures.begin(), figures.end(), 
        [&position](const std::shared_ptr<Figure> &fig){return fig->getPosition() == position;}
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
    possibleMovements = figure->getPossibleMovements(figures);
    state = std::make_shared<StateFigureSelected>(std::make_shared<Board>(*this));
}

void Board::unselectFigure()
{
    selectedFigure = nullptr;
    possibleMovements.clear();
    state = std::make_shared<StateNothingSelected>(std::make_shared<Board>(*this));
}

//TODO cambiar a state del rival
void Board::moveSelectedFigure(const std::pair<int,int> & position)
{
    if(selectedFigure != nullptr)
        selectedFigure->updatePosition(position.first, position.second);
}
