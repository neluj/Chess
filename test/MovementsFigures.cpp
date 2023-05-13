#include "Pawn.hpp"
#include "FigureMock.hpp"
#include "Spots.hpp"
#include <map>
#include <tuple>

#include "MovementsExpectedQueen.hpp"
#include "MovementsExpectedRook.hpp"
#include "MovementsKing.hpp"
#include "MovementsExpectedPawn.hpp"
#include "MovementsKnight.hpp"
#include "MovementsExpectedBishop.hpp"

using namespace chess;

using ::testing::ValuesIn;
using ::testing::Pointee;
using ::testing::UnorderedElementsAreArray;


class MovementsTest
    : public testing::TestWithParam<
        std::pair<SpotName,
          std::tuple<Spot, MovementsType, ExpectedMovements>
        >>
{};



// Nombre
std::map<SpotName,
  std::tuple<Spot, MovementsType, ExpectedMovements>
  > spots = 
{
    // Queen
    {"Mid_Empty_Queen",             std::make_tuple(midEmpty,             movementsExpectedQueen::mov,  movementsExpectedQueen::expectedMidEmpty)},
    {"Mid_Enemy_Sides_Queen",       std::make_tuple(midEnemySides,        movementsExpectedQueen::mov,  movementsExpectedQueen::expectedMidEnemySides)},
    {"Mid_Team_Sides_Queen",        std::make_tuple(midTeamSides,         movementsExpectedQueen::mov,  movementsExpectedQueen::expectedMidTeamSides)},
    {"Mid_Enemy_Diagonals_Queen",   std::make_tuple(midEnemyDiagonals,    movementsExpectedQueen::mov,  movementsExpectedQueen::expectedMidEnemyDiagonals)},
    {"Mid_Team_Diagonals_Queen",    std::make_tuple(midTeamDiagonals,     movementsExpectedQueen::mov,  movementsExpectedQueen::expectedMidTeamDiagonals)},
    {"Mid_Enemy_Surrounded_Queen",  std::make_tuple(midEnemySurrounded,   movementsExpectedQueen::mov,  movementsExpectedQueen::expectedMidEnemySurrounded)},
    {"Mid_Team_Surrounded_Queen",   std::make_tuple(midTeamSurrounded,    movementsExpectedQueen::mov,  movementsExpectedQueen::expectedMidTeamSurrounded)},
    // Rook
    {"Mid_Empty_Rook",              std::make_tuple(midEmpty,             movementsExpectedRook::mov,   movementsExpectedRook::expectedMidEmpty)},
    {"Mid_Enemy_Sides_Rook",        std::make_tuple(midEnemySides,        movementsExpectedRook::mov,   movementsExpectedRook::expectedMidEnemySides)},
    {"Mid_Team_Sides_Rook",         std::make_tuple(midTeamSides,         movementsExpectedRook::mov,   movementsExpectedRook::expectedMidTeamSides)},
    {"Mid_Enemy_Diagonals_Rook",    std::make_tuple(midEnemyDiagonals,    movementsExpectedRook::mov,   movementsExpectedRook::expectedMidEnemyDiagonals)},
    {"Mid_Team_Diagonals_Rook",     std::make_tuple(midTeamDiagonals,     movementsExpectedRook::mov,   movementsExpectedRook::expectedMidTeamDiagonals)},
    {"Mid_Enemy_Surrounded_Rook",   std::make_tuple(midEnemySurrounded,   movementsExpectedRook::mov,   movementsExpectedRook::expectedMidEnemySurrounded)},
    {"Mid_Team_Surrounded_Rook",    std::make_tuple(midTeamSurrounded,    movementsExpectedRook::mov,   movementsExpectedRook::expectedMidTeamSurrounded)},
    // Bishop
    {"Mid_Empty_Bishop",            std::make_tuple(midEmpty,             movementsExpectedBishop::mov, movementsExpectedBishop::expectedMidEmpty)},
    {"Mid_Enemy_Sides_Bishop",      std::make_tuple(midEnemySides,        movementsExpectedBishop::mov, movementsExpectedBishop::expectedMidEnemySides)},
    {"Mid_Team_Sides_Bishop",       std::make_tuple(midTeamSides,         movementsExpectedBishop::mov, movementsExpectedBishop::expectedMidTeamSides)},
    {"Mid_Enemy_Diagonals_Bishop",  std::make_tuple(midEnemyDiagonals,    movementsExpectedBishop::mov, movementsExpectedBishop::expectedMidEnemyDiagonals)},
    {"Mid_Team_Diagonals_Bishop",   std::make_tuple(midTeamDiagonals,     movementsExpectedBishop::mov, movementsExpectedBishop::expectedMidTeamDiagonals)},
    {"Mid_Enemy_Surrounded_Bishop", std::make_tuple(midEnemySurrounded,   movementsExpectedBishop::mov, movementsExpectedBishop::expectedMidEnemySurrounded)},
    {"Mid_Team_Surrounded_Bishop",  std::make_tuple(midTeamSurrounded,    movementsExpectedBishop::mov, movementsExpectedBishop::expectedMidTeamSurrounded)},
    // Pawn
    {"Mid_Empty_Pawn",              std::make_tuple(midEmpty,             movementsExpectedPawn::mov,   movementsExpectedPawn::expectedMidEmpty)},
    {"Mid_Enemy_Sides_Pawn",        std::make_tuple(midEnemySides,        movementsExpectedPawn::mov,   movementsExpectedPawn::expectedMidEnemySides)},
    {"Mid_Team_Sides_Pawn",         std::make_tuple(midTeamSides,         movementsExpectedPawn::mov,   movementsExpectedPawn::expectedMidTeamSides)},
    {"Mid_Enemy_Diagonals_Pawn",    std::make_tuple(midEnemyDiagonals,    movementsExpectedPawn::mov,   movementsExpectedPawn::expectedMidEnemyDiagonals)},
    {"Mid_Team_Diagonals_Pawn",     std::make_tuple(midTeamDiagonals,     movementsExpectedPawn::mov,   movementsExpectedPawn::expectedMidTeamDiagonals)},
    {"Mid_Enemy_Surrounded_Pawn",   std::make_tuple(midEnemySurrounded,   movementsExpectedPawn::mov,   movementsExpectedPawn::expectedMidEnemySurrounded)},
    {"Mid_Team_Surrounded_Pawn",    std::make_tuple(midTeamSurrounded,    movementsExpectedPawn::mov,   movementsExpectedPawn::expectedMidTeamSurrounded)}
 
};

INSTANTIATE_TEST_SUITE_P(
    SpotNameGenerator, MovementsTest,
    testing::ValuesIn(spots),
    [](const testing::TestParamInfo<MovementsTest::ParamType> &info) {
      return info.param.first;
    });


TEST_P(MovementsTest, WorksForVariousInputs) {

  auto p = GetParam().second;

  Spot                spot        = std::get<0>(p);
  MovementsType       movementType= std::get<1>(p);
  ExpectedMovements   expected    = std::get<2>(p);
  Hero                hero        = std::get<0>(spot);
  BoardSpot           boardSpot   = std::get<1>(spot);

  auto result = movementType->getMovements( hero, boardSpot);

  EXPECT_THAT(expected.size(), result.size());

  std::vector<std::pair<int,int>> expectedValues;
  std::vector<std::pair<int,int>> resultValues;

  for(auto exp : expected)
  {
    int first;
    int second;
    first = exp->first;
    second = exp->second;
    expectedValues.push_back(std::make_pair(first, second));
  }

  for(auto res : result)
  {
    int first;
    int second;
    first = res->first;
    second = res->second;
    resultValues.push_back(std::make_pair(first, second));
  }

  EXPECT_THAT(resultValues, UnorderedElementsAreArray(expectedValues));
}



