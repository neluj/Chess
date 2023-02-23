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

}

const std::vector<std::shared_ptr<Figure>> & Board::getFigures() const
{
    return figures;
}