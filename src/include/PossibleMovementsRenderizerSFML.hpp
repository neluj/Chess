#pragma once
#include "RenderizerSFML.hpp"
#include <vector>


class PossibleMovementsRenderizerSFML : public RenderizerSFML
{
public:

    PossibleMovementsRenderizerSFML(std::vector<std::pair<int,int>> * possibleMovements);
    void draw(RenderWindow & window) override;

private:

    const int           IMAGE_SIZE = 64;
    const std::string   IMAGE_PATH = "images/squareSelection.png";

    std::vector<std::pair<int,int>> * possibleMovements;

};