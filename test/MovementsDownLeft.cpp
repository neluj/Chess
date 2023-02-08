#include "gtest/gtest.h"
#include "MovementsDiagonal.hpp"
#include "Pawn.hpp"
#include "FigureManager.hpp"

TEST(DownLeft, PositionNotExits) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(5, 7));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsDiagonal movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDiagonalDownLeft(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(DownLeft, rivalOnPosition) 
{
    std::pair<int,int> expectedPosition(2, 1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 0));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsDiagonal movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDiagonalDownLeft(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(DownLeft, teamOnPosition) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 6));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsDiagonal movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDiagonalDownLeft(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(DownLeft, emptyPosition) 
{
    std::pair<int,int> expectedPosition(2, 4);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 3));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsDiagonal movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDiagonalDownLeft(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}
