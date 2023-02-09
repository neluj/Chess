#include "gtest/gtest.h"
#include "MovementsPawn.hpp"
#include "FigureManager.hpp"

TEST(pawnMovements, twoEats) 
{
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(5, 2));
    MovementsPawn movements;
    std::vector<std::pair<int,int>> actual = movements.getMovements(pawn,figureManager.getFigures());
    //ASSERT_THAT(actual, ElementsAre(std::pair<int,int>(5,1), std::pair<int,int>(4,1), std::pair<int,int>(6,1)));
    std::pair<int,int> up(5,1);
    std::pair<int,int> upLeft(4,1);
    std::pair<int,int> upRight(6,1);
    ASSERT_EQ(actual.size(), 2);
    if(actual.size()>1)
    {
        ASSERT_EQ(actual.at(0), upRight);
        ASSERT_EQ(actual.at(1), upLeft);
    }
}

TEST(pawnMovements, justFront) 
{
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(5, 3));
    MovementsPawn movements;
    std::vector<std::pair<int,int>> actual = movements.getMovements(pawn,figureManager.getFigures());
    //ASSERT_THAT(actual, ElementsAre(std::pair<int,int>(5,1), std::pair<int,int>(4,1), std::pair<int,int>(6,1)));
    std::pair<int,int> up(5,2);
    ASSERT_EQ(actual.size(), 1);
    if(actual.size()>0)
    {
        ASSERT_EQ(actual.at(0), up);
    }
}


