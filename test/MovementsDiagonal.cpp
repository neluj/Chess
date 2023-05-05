#include "MovementsDiagonal.hpp"
#include <gtest/gtest.h>

using namespace chess;

TEST(MovementsDiagonal, movementUpLeft) 
{
    MovementsDiagonal movementsDiagonal;
    std::shared_ptr<std::pair<int,int>> positionMiddle              = std::make_shared<std::pair<int,int>>(4,4);
    std::shared_ptr<std::pair<int,int>> positionMiddleUpLeftExpected    = std::make_shared<std::pair<int,int>>(3,3);
    auto positionMiddleUpCalculated                                 = movementsDiagonal.getDiagonalUpLeft(positionMiddle);
    EXPECT_EQ(positionMiddleUpLeftExpected->first, positionMiddleUpCalculated->first);
    EXPECT_EQ(positionMiddleUpLeftExpected->second, positionMiddleUpCalculated->second);
}

TEST(MovementsDiagonal, movementUpRight ) 
{
    MovementsDiagonal movementsDiagonal;
    std::shared_ptr<std::pair<int,int>> positionMiddle              = std::make_shared<std::pair<int,int>>(4,4);
    std::shared_ptr<std::pair<int,int>> positionMiddleUpRightExpected  = std::make_shared<std::pair<int,int>>(5,3);
    auto positionMiddleDownpCalculated                              = movementsDiagonal.getDiagonalUpRight(positionMiddle);
    EXPECT_EQ(positionMiddleUpRightExpected->first , positionMiddleDownpCalculated->first);
    EXPECT_EQ(positionMiddleUpRightExpected->second, positionMiddleDownpCalculated->second);
}

TEST(MovementsDiagonal, movementDownLeft) 
{
    MovementsDiagonal movementsDiagonal;
    std::shared_ptr<std::pair<int,int>> positionMiddle              = std::make_shared<std::pair<int,int>>(4,4);
    std::shared_ptr<std::pair<int,int>> positionMiddleDownLeftExpected    = std::make_shared<std::pair<int,int>>(3,5);
    auto positionMiddleUpCalculated                                 = movementsDiagonal.getDiagonalDownLeft(positionMiddle);
    EXPECT_EQ(positionMiddleDownLeftExpected->first, positionMiddleUpCalculated->first);
    EXPECT_EQ(positionMiddleDownLeftExpected->second, positionMiddleUpCalculated->second);
}

TEST(MovementsDiagonal, movementDownRight) 
{
    MovementsDiagonal movementsDiagonal;
    std::shared_ptr<std::pair<int,int>> positionMiddle              = std::make_shared<std::pair<int,int>>(4,4);
    std::shared_ptr<std::pair<int,int>> positionMiddleDownRightExpected  = std::make_shared<std::pair<int,int>>(5,5);
    auto positionMiddleDownpCalculated                              = movementsDiagonal.getDiagonalDownRight(positionMiddle);
    EXPECT_EQ(positionMiddleDownRightExpected->first , positionMiddleDownpCalculated->first);
    EXPECT_EQ(positionMiddleDownRightExpected->second, positionMiddleDownpCalculated->second);
}