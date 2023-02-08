#include "gtest/gtest.h"
#include "MovementsDiagonal.hpp"
#include "Pawn.hpp"
#include "FigureManager.hpp"

TEST(DiagonalUpRight, PositionNotExits) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::pair<int,int> actual;
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(5, 0));
    MovementsDiagonal movementsBasic;
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Figure> actualFigure = movementsBasic.getDiagonalUpRight(pawn,figureManager.getFigures(), actual);
    ASSERT_EQ(expectedPosition, actual);
    ASSERT_EQ(nullptr, actualFigure);
}

TEST(DiagonalUpRight, rivalOnPosition) 
{
    std::pair<int,int> expectedPosition(4, 1);
    std::pair<int,int> actual;
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 2));
    MovementsDiagonal movementsBasic;
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Figure> actualFigure = movementsBasic.getDiagonalUpRight(pawn,figureManager.getFigures(), actual);
    ASSERT_EQ(expectedPosition, actual); 
    ASSERT_EQ(Figure::PAWN, actualFigure->getType());
}

TEST(DiagonalUpRight, teamOnPosition) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::pair<int,int> actual;
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 7));
    MovementsDiagonal movementsBasic;
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Figure> actualFigure = movementsBasic.getDiagonalUpRight(pawn,figureManager.getFigures(), actual);
    ASSERT_EQ(expectedPosition, actual); 
    ASSERT_EQ(nullptr, actualFigure);
}

TEST(DiagonalUpRight, emptyPosition) 
{
    std::pair<int,int> expectedPosition(4, 2);
    std::pair<int,int> actual;
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 3));
    MovementsDiagonal movementsBasic;
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Figure> actualFigure = movementsBasic.getDiagonalUpRight(pawn,figureManager.getFigures(), actual);
    ASSERT_EQ(expectedPosition, actual); 
    ASSERT_EQ(nullptr, actualFigure);
}
