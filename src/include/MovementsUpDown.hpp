#pragma once
#include <utility>


class MovementsUpDown
{
public:

    std::pair<int,int> getUpPosition       (const std::pair<int,int> & position);
    std::pair<int,int> getDownPosition     (const std::pair<int,int> & position);

};