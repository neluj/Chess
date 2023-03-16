#pragma once
#include <utility>
#include <memory>

namespace chess
{

class MovementsUpDown
{
public:

    std::shared_ptr<std::pair<int,int>> getUpPosition       (const std::shared_ptr<std::pair<int,int>> & position);
    std::shared_ptr<std::pair<int,int>> getDownPosition     (const std::shared_ptr<std::pair<int,int>> & position);

};

}