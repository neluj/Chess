#pragma once
#include "SpotBases.hpp"
#include "MovementsRook.hpp"

namespace movementsExpectedRook
{


MovementsType mov = std::make_shared<MovementsRook>();


ExpectedMovements expectedMidEmpty
{
  expectedPosition_e8,
  expectedPosition_e7,
  expectedPosition_e6,
  expectedPosition_e4,
  expectedPosition_e3,
  expectedPosition_e2,
  expectedPosition_e1,
  expectedPosition_a5,
  expectedPosition_b5,
  expectedPosition_c5,
  expectedPosition_d5,
  expectedPosition_f5,
  expectedPosition_g5,
  expectedPosition_h5
};


ExpectedMovements expectedMidEnemySides
{
  expectedPosition_e4,
  expectedPosition_e6,
  expectedPosition_d5,
  expectedPosition_f5
};


ExpectedMovements expectedMidEnemyDiagonals
{
  expectedPosition_e8,
  expectedPosition_e7,
  expectedPosition_e6,
  expectedPosition_e4,
  expectedPosition_e3,
  expectedPosition_e2,
  expectedPosition_e1,
  expectedPosition_a5,
  expectedPosition_b5,
  expectedPosition_c5,
  expectedPosition_d5,
  expectedPosition_f5,
  expectedPosition_g5,
  expectedPosition_h5
};


ExpectedMovements expectedMidTeamSides
{};


ExpectedMovements expectedMidTeamDiagonals
{
  expectedPosition_e8,
  expectedPosition_e7,
  expectedPosition_e6,
  expectedPosition_e4,
  expectedPosition_e3,
  expectedPosition_e2,
  expectedPosition_e1,
  expectedPosition_a5,
  expectedPosition_b5,
  expectedPosition_c5,
  expectedPosition_d5,
  expectedPosition_f5,
  expectedPosition_g5,
  expectedPosition_h5
};


ExpectedMovements expectedMidEnemySurrounded
{
  expectedPosition_e6,
  expectedPosition_d5,
  expectedPosition_f5,
  expectedPosition_e4
};

ExpectedMovements expectedMidTeamSurrounded
{
};

};