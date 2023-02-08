#include "gtest/gtest.h"
#include "MovementsDiagonal.hpp"
#include "Pawn.hpp"
#include "FigureManager.hpp"

TEST(DownRight, PositionNotExits) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(5, 7));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsDiagonal movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDiagonalDownRight(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(DownRight, rivalOnPosition) 
{
    std::pair<int,int> expectedPosition(4, 1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 0));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsDiagonal movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDiagonalDownRight(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(DownRight, teamOnPosition) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 6));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsDiagonal movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDiagonalDownRight(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(DownRight, emptyPosition) 
{
    std::pair<int,int> expectedPosition(4, 4);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 3));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsDiagonal movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDiagonalDownRight(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}
