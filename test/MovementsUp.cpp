#include "gtest/gtest.h"
#include "MovementsSides.hpp"
#include "Pawn.hpp"
#include "FigureManager.hpp"

TEST(Up, PositionNotExits) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(5, 0));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsSides movementsBasic;
    std::pair<int,int> actual = movementsBasic.getUpPosition(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(Up, rivalOnPosition) 
{
    std::pair<int,int> expectedPosition(3, 1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 2));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsSides movementsBasic;
    std::pair<int,int> actual = movementsBasic.getUpPosition(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(Up, teamOnPosition) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 7));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsSides movementsBasic;
    std::pair<int,int> actual = movementsBasic.getUpPosition(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(Up, emptyPosition) 
{
    std::pair<int,int> expectedPosition(3, 2);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 3));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsSides movementsBasic;
    std::pair<int,int> actual = movementsBasic.getUpPosition(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}
