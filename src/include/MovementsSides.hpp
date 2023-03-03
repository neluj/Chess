#pragma once
#include <vector>
#include "Figure.hpp"


class MovementsSides
{
public:
    //Returns figure if the movements ends withempassant

    std::shared_ptr<std::pair<int,int>> getLeftPosition     (const std::shared_ptr<std::pair<int,int>> & position);
    std::shared_ptr<std::pair<int,int>> getRightPosition    (const std::shared_ptr<std::pair<int,int>> & position);

};