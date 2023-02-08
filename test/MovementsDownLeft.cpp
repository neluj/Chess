#include "gtest/gtest.h"
#include "MovementsDiagonal.hpp"
#include "Pawn.hpp"
#include "FigureManager.hpp"

TEST(DownLeft, PositionNotExits) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::pair<int,int> actual;
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(5, 7));
    MovementsDiagonal movementsBasic;
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Figure> actualFigure = movementsBasic.getDiagonalDownLeft(pawn,figureManager.getFigures(), actual);
    ASSERT_EQ(expectedPosition, actual);
    ASSERT_EQ(nullptr, actualFigure);
}

TEST(DownLeft, rivalOnPosition) 
{
    std::pair<int,int> expectedPosition(2, 1);
    std::pair<int,int> actual;
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 0));
    MovementsDiagonal movementsBasic;
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Figure> actualFigure = movementsBasic.getDiagonalDownLeft(pawn,figureManager.getFigures(), actual);
    ASSERT_EQ(expectedPosition, actual); 
    ASSERT_EQ(Figure::PAWN, actualFigure->getType());
}

TEST(DownLeft, teamOnPosition) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::pair<int,int> actual;
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 6));
    MovementsDiagonal movementsBasic;
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Figure> actualFigure = movementsBasic.getDiagonalDownLeft(pawn,figureManager.getFigures(), actual);
    ASSERT_EQ(expectedPosition, actual); 
    ASSERT_EQ(nullptr, actualFigure);
}

TEST(DownLeft, emptyPosition) 
{
    std::pair<int,int> expectedPosition(2, 4);
    std::pair<int,int> actual;
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 3));
    MovementsDiagonal movementsBasic;
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Figure> actualFigure = movementsBasic.getDiagonalDownLeft(pawn,figureManager.getFigures(), actual);
    ASSERT_EQ(expectedPosition, actual); 
    ASSERT_EQ(nullptr, actualFigure);
}
