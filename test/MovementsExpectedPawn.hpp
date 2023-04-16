#pragma once
#include "SpotBases.hpp"
#include "MovementsPawn.hpp"

namespace movementsExpectedPawn
{

MovementsType mov = std::make_shared<MovementsPawn>();


ExpectedMovements expectedMidEmpty
{
  expectedPosition_e6,
};


ExpectedMovements expectedMidEnemySides
{
};


ExpectedMovements expectedMidEnemyDiagonals
{
  expectedPosition_e6,
  expectedPosition_d6,
  expectedPosition_f6
};


ExpectedMovements expectedMidTeamSides
{
};


ExpectedMovements expectedMidTeamDiagonals
{
    expectedPosition_e6
};

ExpectedMovements expectedMidEnemySurrounded
{
  expectedPosition_d6,
  expectedPosition_f6
};

ExpectedMovements expectedMidTeamSurrounded
{
};


};