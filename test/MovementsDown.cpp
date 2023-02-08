#include "gtest/gtest.h"
#include "MovementsSides.hpp"
#include "Pawn.hpp"
#include "FigureManager.hpp"

TEST(Down, PositionNotExits) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(5, 7));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsSides movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDownPosition(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(Down, rivalOnPosition) 
{
    std::pair<int,int> expectedPosition(3, 1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 0));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsSides movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDownPosition(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(Down, teamOnPosition) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 6));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsSides movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDownPosition(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}

TEST(Down, emptyPosition) 
{
    std::pair<int,int> expectedPosition(3, 4);
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 3));
    FigureManager figureManager;
    figureManager.setInitialState();
    MovementsSides movementsBasic;
    std::pair<int,int> actual = movementsBasic.getDownPosition(pawn,figureManager.getFigures());
    ASSERT_EQ(expectedPosition, actual); 
}
