#include "gtest/gtest.h"
#include "MovementsDiagonal.hpp"
#include "Pawn.hpp"
#include "FigureManager.hpp"

TEST(DiagonalUpLeft, PositionNotExits) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::pair<int,int> actual;
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(5, 0));
    MovementsDiagonal movementsBasic;
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Figure> actualFigure = movementsBasic.getDiagonalUpLeft(pawn,figureManager.getFigures(), actual);
    ASSERT_EQ(expectedPosition, actual);
    ASSERT_EQ(nullptr, actualFigure);
}

TEST(DiagonalUpLeft, rivalOnPosition) 
{
    std::pair<int,int> expectedPosition(2, 1);
    std::pair<int,int> actual;
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 2));
    MovementsDiagonal movementsBasic;
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Figure> actualFigure = movementsBasic.getDiagonalUpLeft(pawn,figureManager.getFigures(), actual);
    ASSERT_EQ(expectedPosition, actual); 
    ASSERT_EQ(Figure::PAWN, actualFigure->getType());
}

TEST(DiagonalUpLeft, teamOnPosition) 
{
    std::pair<int,int> expectedPosition(-1, -1);
    std::pair<int,int> actual;
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(3, 7));
    MovementsDiagonal movementsBasic;
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Figure> actualFigure = movementsBasic.getDiagonalUpLeft(pawn,figureManager.getFigures(), actual);
    ASSERT_EQ(expectedPosition, actual); 
    ASSERT_EQ(nullptr, actualFigure);
}

TEST(DiagonalUpLeft, emptyPosition) 
{
    std::pair<int,int> expectedPosition(3, 3);
    std::pair<int,int> actual;
    std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(Figure::WHITE, std::pair<int, int>(4, 4));
    MovementsDiagonal movementsBasic;
    FigureManager figureManager;
    figureManager.setInitialState();
    std::shared_ptr<Figure> actualFigure = movementsBasic.getDiagonalUpLeft(pawn,figureManager.getFigures(), actual);
    ASSERT_EQ(expectedPosition, actual); 
    ASSERT_EQ(nullptr, actualFigure);
}
