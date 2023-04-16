#pragma once
#include "SpotBases.hpp"
#include "MovementsBishop.hpp"

namespace movementsExpectedBishop
{

MovementsType mov = std::make_shared<MovementsBishop>();


ExpectedMovements expectedMidEmpty
{
  expectedPosition_b8,
  expectedPosition_c7,
  expectedPosition_d6,
  expectedPosition_f4,
  expectedPosition_g3,
  expectedPosition_h2,
  expectedPosition_h8,
  expectedPosition_g7,
  expectedPosition_f6,
  expectedPosition_d4,
  expectedPosition_c3,
  expectedPosition_b2,
  expectedPosition_a1
};


ExpectedMovements expectedMidEnemySides
{
  expectedPosition_b8,
  expectedPosition_c7,
  expectedPosition_d6,
  expectedPosition_f4,
  expectedPosition_g3,
  expectedPosition_h2,
  expectedPosition_h8,
  expectedPosition_g7,
  expectedPosition_f6,
  expectedPosition_d4,
  expectedPosition_c3,
  expectedPosition_b2,
  expectedPosition_a1
};


ExpectedMovements expectedMidEnemyDiagonals
{
  expectedPosition_d6,
  expectedPosition_d4,
  expectedPosition_f6,
  expectedPosition_f4
};


ExpectedMovements expectedMidTeamSides
{
  expectedPosition_b8,
  expectedPosition_c7,
  expectedPosition_d6,
  expectedPosition_f4,
  expectedPosition_g3,
  expectedPosition_h2,
  expectedPosition_h8,
  expectedPosition_g7,
  expectedPosition_f6,
  expectedPosition_d4,
  expectedPosition_c3,
  expectedPosition_b2,
  expectedPosition_a1
};


ExpectedMovements expectedMidTeamDiagonals
{
};

ExpectedMovements expectedMidEnemySurrounded
{
  expectedPosition_d6,
  expectedPosition_d4,
  expectedPosition_f6,
  expectedPosition_f4
};

ExpectedMovements expectedMidTeamSurrounded
{
};


};