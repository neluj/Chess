#pragma once
#include "RenderizerSFML.hpp"
#include <list>


class PossibleMovementsRenderizerSFML : public RenderizerSFML
{
public:

    PossibleMovementsRenderizerSFML(const std::vector<std::shared_ptr<std::pair<int,int>>> & possibleMovements);
    void draw(RenderWindow & window) override;

private:

    const int           IMAGE_SIZE = 64;
    const std::string   IMAGE_PATH = "images/squareSelection.png";

    const std::vector<std::shared_ptr<std::pair<int,int>>> possibleMovements;

};