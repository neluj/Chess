#include "gtest/gtest.h"
#include "MovementsSides.hpp"
#include "Pawn.hpp"
#include "FigureManager.hpp"

TEST(Right, PositionNotExits) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::pair<int,int> actual;
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(7, 1));
    MovementsSides movementsBasic;
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Figure> actualFigure = movementsBasic.getRightPosition(pawn,figureManager.getFigures(), actual);
    ASSERT_EQ(expectedPosition, actual);
    ASSERT_EQ(nullptr, actualFigure);
}

TEST(Right, rivalOnPosition) 
{
    std::pair<int,int> expectedPosition(3, 1);
    std::pair<int,int> actual;
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(2, 1));
    MovementsSides movementsBasic;
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Figure> actualFigure = movementsBasic.getRightPosition(pawn,figureManager.getFigures(), actual);
    ASSERT_EQ(expectedPosition, actual); 
    ASSERT_EQ(Figure::PAWN, actualFigure->getType());
}

TEST(Right, teamOnPosition) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::pair<int,int> actual;
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(2, 7));
    MovementsSides movementsBasic;
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Figure> actualFigure = movementsBasic.getRightPosition(pawn,figureManager.getFigures(), actual);
    ASSERT_EQ(expectedPosition, actual); 
    ASSERT_EQ(nullptr, actualFigure);
}

TEST(Right, emptyPosition) 
{
    std::pair<int,int> expectedPosition(4, 3);
    std::pair<int,int> actual;
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 3));
    MovementsSides movementsBasic;
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Figure> actualFigure = movementsBasic.getRightPosition(pawn,figureManager.getFigures(), actual);
    ASSERT_EQ(expectedPosition, actual); 
    ASSERT_EQ(nullptr, actualFigure);
}
