#pragma once
#include "SpotBases.hpp"
#include "MovementsQueen.hpp"

namespace movementsExpectedQueen
{

MovementsType mov = std::make_shared<MovementsQueen>();


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
  expectedPosition_a1,
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
  expectedPosition_a1,
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
  expectedPosition_h5,
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
  expectedPosition_d6,
  expectedPosition_e6,
  expectedPosition_f6,
  expectedPosition_d5,
  expectedPosition_f5,
  expectedPosition_d4,
  expectedPosition_e4,
  expectedPosition_f4
};

ExpectedMovements expectedMidTeamSurrounded
{
};


};