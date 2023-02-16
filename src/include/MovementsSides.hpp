#pragma once
#include <vector>
#include "Figure.hpp"


class MovementsSides
{
public:
    //Returns figure if the movements ends withempassant

    std::pair<int,int> getLeftPosition     (const std::pair<int,int> & position);
    std::pair<int,int> getRightPosition    (const std::pair<int,int> & position);

};