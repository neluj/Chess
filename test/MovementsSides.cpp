#include "MovementsSides.hpp"
#include <gtest/gtest.h>

using namespace chess;

TEST(MovementsSides, movementLeft) 
{
    MovementsSides movementsSides;
    std::shared_ptr<std::pair<int,int>> positionMiddle              = std::make_shared<std::pair<int,int>>(4,4);
    std::shared_ptr<std::pair<int,int>> positionMiddleUpExpected    = std::make_shared<std::pair<int,int>>(3,4);
    auto positionMiddleUpCalculated                                 = movementsSides.getLeftPosition(positionMiddle);
    EXPECT_EQ(positionMiddleUpExpected->first, positionMiddleUpCalculated->first);
    EXPECT_EQ(positionMiddleUpExpected->second, positionMiddleUpCalculated->second);
}

TEST(MovementsSides, movementRight) 
{
    MovementsSides movementsSides;
    std::shared_ptr<std::pair<int,int>> positionMiddle              = std::make_shared<std::pair<int,int>>(4,4);
    std::shared_ptr<std::pair<int,int>> positionMiddleDownExpected  = std::make_shared<std::pair<int,int>>(5,4);
    auto positionMiddleDownpCalculated                              = movementsSides.getRightPosition(positionMiddle);
    EXPECT_EQ(positionMiddleDownExpected->first , positionMiddleDownpCalculated->first);
    EXPECT_EQ(positionMiddleDownExpected->second, positionMiddleDownpCalculated->second);
}