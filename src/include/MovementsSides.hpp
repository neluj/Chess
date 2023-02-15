#pragma once
#include <vector>
#include "Figure.hpp"


class MovementsSides
{
public:
    //Returns figure if the movements ends withempassant

    std::pair<int,int> getLeftPosition     ( std::pair<int,int>  position);
    std::pair<int,int> getRightPosition    ( std::pair<int,int>  position);

};