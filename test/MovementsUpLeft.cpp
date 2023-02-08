#include "gtest/gtest.h"
#include "MovementsDiagonal.hpp"
#include "Pawn.hpp"
#include "FigureManager.hpp"

TEST(DiagonalUpLeft, PositionNotExits) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(5, 0));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsDiagonal movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDiagonalUpLeft(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(DiagonalUpLeft, rivalOnPosition) 
{
    std::pair<int,int> expectedPosition(2, 1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 2));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsDiagonal movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDiagonalUpLeft(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(DiagonalUpLeft, teamOnPosition) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 7));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsDiagonal movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDiagonalUpLeft(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(DiagonalUpLeft, emptyPosition) 
{
    std::pair<int,int> expectedPosition(3, 3);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(4, 4));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsDiagonal movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDiagonalUpLeft(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}
