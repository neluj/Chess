#include "gtest/gtest.h"
#include "MovementsSides.hpp"
#include "Pawn.hpp"
#include "FigureManager.hpp"

TEST(Left, PositionNotExits) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(0, 1));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsSides movementsBasic;
    std::pair<int,int> actual = movementsBasic.getLeftPosition(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(Left, rivalOnPosition) 
{
    std::pair<int,int> expectedPosition(3, 1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(4, 1));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsSides movementsBasic;
    std::pair<int,int> actual = movementsBasic.getLeftPosition(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(Left, teamOnPosition) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(2, 7));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsSides movementsBasic;
    std::pair<int,int> actual = movementsBasic.getLeftPosition(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(Left, emptyPosition) 
{
    std::pair<int,int> expectedPosition(3, 3);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(4, 3));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsSides movementsBasic;
    std::pair<int,int> actual = movementsBasic.getLeftPosition(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}
