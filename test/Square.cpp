#include "Square.hpp"
#include <gtest/gtest.h>

using namespace chess;

TEST(Square, stdChar2Pos) 
{
    Square sqrCharA8('A','8');
    Square sqrNumZZ(0,0);
    EXPECT_EQ(sqrNumZZ,sqrCharA8);

    Square sqrCharA1('A','1');
    Square sqrNumZS(0,7);
    EXPECT_EQ(sqrNumZS,sqrCharA1);

    Square sqrCharH8('H','8');
    Square sqrNumSZ(7,0);
    EXPECT_EQ(sqrNumSZ,sqrCharH8);

    Square sqrCharH1('H','1');
    Square sqrNumSS(7,7);
    EXPECT_EQ(sqrNumSS,sqrCharH1);

    Square sqrCharE5('E','5');
    Square sqrNumFT(4,3);
    EXPECT_EQ(sqrNumFT,sqrCharE5);
}

TEST(Square, stdString2Pos) 
{
    Square sqrCharA8("A8");
    Square sqrNumZZ(0,0);
    EXPECT_EQ(sqrNumZZ,sqrCharA8);

    Square sqrCharA1("A1");
    Square sqrNumZS(0,7);
    EXPECT_EQ(sqrNumZS,sqrCharA1);

    Square sqrCharH8("H8");
    Square sqrNumSZ(7,0);
    EXPECT_EQ(sqrNumSZ,sqrCharH8);

    Square sqrCharH1("H1");
    Square sqrNumSS(7,7);
    EXPECT_EQ(sqrNumSS,sqrCharH1);

    Square sqrCharE5("E5");
    Square sqrNumFT(4,3);
    EXPECT_EQ(sqrNumFT,sqrCharE5);
}