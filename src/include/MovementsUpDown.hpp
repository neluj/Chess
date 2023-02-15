#pragma once
#include <utility>


class MovementsUpDown
{
public:
    // TODO parametros constantes y por referencia. Colocar const
    std::pair<int,int> getUpPosition       (std::pair<int,int> position);
    std::pair<int,int> getDownPosition     (std::pair<int,int> position);

};