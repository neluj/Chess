#include "Board.hpp"

Board::Board()
{
    figures.reserve(32);
    setInitialState();
}

void Board::setInitialState()
{
    figures.reserve(32);

    figures.push_back(std::make_shared<King>(Figure::WHITE, std::pair<int, int>(4, 7)));
    figures.push_back(std::make_shared<King>(Figure::BLACK, std::pair<int, int>(4, 0)));

    figures.push_back(std::make_shared<Queen>(Figure::WHITE, std::pair<int, int>(3, 7)));
    figures.push_back(std::make_shared<Queen>(Figure::BLACK, std::pair<int, int>(3, 0)));

    figures.push_back(std::make_shared<Rook>(Figure::WHITE, std::pair<int, int>(0, 7)));
    figures.push_back(std::make_shared<Rook>(Figure::WHITE, std::pair<int, int>(7, 7)));
    figures.push_back(std::make_shared<Rook>(Figure::BLACK, std::pair<int, int>(0, 0)));
    figures.push_back(std::make_shared<Rook>(Figure::BLACK, std::pair<int, int>(7, 0)));

    figures.push_back(std::make_shared<Bishop>(Figure::WHITE, std::pair<int, int>(2, 7)));
    figures.push_back(std::make_shared<Bishop>(Figure::WHITE, std::pair<int, int>(5, 7)));
    figures.push_back(std::make_shared<Bishop>(Figure::BLACK, std::pair<int, int>(2, 0)));
    figures.push_back(std::make_shared<Bishop>(Figure::BLACK, std::pair<int, int>(5, 0)));

    figures.push_back(std::make_shared<Knight>(Figure::WHITE, std::pair<int, int>(1, 7)));
    figures.push_back(std::make_shared<Knight>(Figure::WHITE, std::pair<int, int>(6, 7)));
    figures.push_back(std::make_shared<Knight>(Figure::BLACK, std::pair<int, int>(1, 0)));
    figures.push_back(std::make_shared<Knight>(Figure::BLACK, std::pair<int, int>(6, 0)));


    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(0, 6)));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(1, 6)));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(2, 6)));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 6)));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(4, 6)));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(5, 6)));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(6, 6)));
    figures.push_back(std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(7, 6)));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::pair<int, int>(0, 1)));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::pair<int, int>(1, 1)));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::pair<int, int>(2, 1)));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::pair<int, int>(3, 1)));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::pair<int, int>(4, 1)));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::pair<int, int>(5, 1)));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::pair<int, int>(6, 1)));
    figures.push_back(std::make_shared<Pawn>(Figure::BLACK, std::pair<int, int>(7, 1)));

}

const std::vector<std::shared_ptr<Figure>> & Board::getFigures() const
{
    return figures;
}