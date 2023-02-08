#include "gtest/gtest.h"
#include "MovementsSides.hpp"
#include "Pawn.hpp"
#include "FigureManager.hpp"

TEST(Right, PositionNotExits) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(7, 1));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsSides movementsBasic;
    std::pair<int,int> actual = movementsBasic.getRightPosition(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(Right, rivalOnPosition) 
{
    std::pair<int,int> expectedPosition(3, 1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(2, 1));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsSides movementsBasic;
    std::pair<int,int> actual = movementsBasic.getRightPosition(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual);
}

TEST(Right, teamOnPosition) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(2, 7));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsSides movementsBasic;
    std::pair<int,int> actual = movementsBasic.getRightPosition(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(Right, emptyPosition) 
{
    std::pair<int,int> expectedPosition(4, 3);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 3));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsSides movementsBasic;
    std::pair<int,int> actual = movementsBasic.getRightPosition(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}
