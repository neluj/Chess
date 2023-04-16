#pragma once
#include "SpotBases.hpp"


BoardSpot BoardSpotMidEmpty{};

BoardSpot BoardSpotMidEnemySides{
    enemy_e4,
    enemy_e6,
    enemy_d5,
    enemy_f5
};

BoardSpot BoardSpotMidEnemyDiagonals{
    enemy_d6,
    enemy_f6,
    enemy_d4,
    enemy_f4
};

BoardSpot BoardSpotMidTeamSides{
    hero_e4,
    hero_e6,
    hero_d5,
    hero_f5
};

BoardSpot BoardSpotMidTeamDiagonals{
    hero_d6,
    hero_f6,
    hero_d4,
    hero_f4
};

BoardSpot BoardSpotMidEnemySurrounded{
    enemy_e4,
    enemy_e6,
    enemy_d5,
    enemy_f5,
    enemy_d6,
    enemy_f6,
    enemy_d4,
    enemy_f4

};

BoardSpot BoardSpotMidTeamSurrounded{
    hero_e4,
    hero_e6,
    hero_d5,
    hero_f5,
    hero_d6,
    hero_f6,
    hero_d4,
    hero_f4
};

Spot midEmpty           {std::make_tuple(hero_e5, BoardSpotMidEmpty)};
Spot midEnemySides      {std::make_tuple(hero_e5, BoardSpotMidEnemySides)};
Spot midEnemyDiagonals  {std::make_tuple(hero_e5, BoardSpotMidEnemyDiagonals)};
Spot midTeamSides       {std::make_tuple(hero_e5, BoardSpotMidTeamSides)};
Spot midTeamDiagonals   {std::make_tuple(hero_e5, BoardSpotMidTeamDiagonals)};
Spot midEnemySurrounded {std::make_tuple(hero_e5, BoardSpotMidEnemySurrounded)};
Spot midTeamSurrounded  {std::make_tuple(hero_e5, BoardSpotMidTeamSurrounded)};