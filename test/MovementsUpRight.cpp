#include "gtest/gtest.h"
#include "MovementsDiagonal.hpp"
#include "Pawn.hpp"
#include "FigureManager.hpp"

TEST(DiagonalUpRight, PositionNotExits) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(5, 0));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsDiagonal movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDiagonalUpRight(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(DiagonalUpRight, rivalOnPosition) 
{
    std::pair<int,int> expectedPosition(4, 1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 2));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsDiagonal movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDiagonalUpRight(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(DiagonalUpRight, teamOnPosition) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 7));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsDiagonal movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDiagonalUpRight(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(DiagonalUpRight, emptyPosition) 
{
    std::pair<int,int> expectedPosition(4, 2);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 3));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsDiagonal movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDiagonalUpRight(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}
