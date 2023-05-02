#include "MovementsUpDown.hpp"
#include <gtest/gtest.h>

using namespace chess;

TEST(MovementsUpDownTest, movementUp) 
{
    MovementsUpDown movementsUpDown;
    std::shared_ptr<std::pair<int,int>> positionMiddle              = std::make_shared<std::pair<int,int>>(4,4);
    std::shared_ptr<std::pair<int,int>> positionMiddleUpExpected    = std::make_shared<std::pair<int,int>>(4,3);
    auto positionMiddleUpCalculated                                 = movementsUpDown.getUpPosition(positionMiddle);
    EXPECT_EQ(positionMiddleUpExpected->first, positionMiddleUpCalculated->first);
    EXPECT_EQ(positionMiddleUpExpected->second, positionMiddleUpCalculated->second);
}

TEST(MovementsUpDownTest, movementDown) 
{
    MovementsUpDown movementsUpDown;
    std::shared_ptr<std::pair<int,int>> positionMiddle              = std::make_shared<std::pair<int,int>>(4,4);
    std::shared_ptr<std::pair<int,int>> positionMiddleDownExpected  = std::make_shared<std::pair<int,int>>(4,5);
    auto positionMiddleDownpCalculated                              = movementsUpDown.getDownPosition(positionMiddle);
    EXPECT_EQ(positionMiddleDownExpected->first , positionMiddleDownpCalculated->first);
    EXPECT_EQ(positionMiddleDownExpected->second, positionMiddleDownpCalculated->second);
}