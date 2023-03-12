#pragma once
#include "RenderizerSFML.hpp"
#include <list>


class PossibleMovementsRenderizerSFML : public RenderizerSFML
{
public:

    PossibleMovementsRenderizerSFML(const std::shared_ptr<std::list<std::shared_ptr<const std::pair<int,int>>>> possibleMovements);
    void draw(RenderWindow & window) override;

private:

    const int           IMAGE_SIZE = 64;
    const std::string   IMAGE_PATH = "images/squareSelection.png";

    const std::shared_ptr<std::list<std::shared_ptr<const std::pair<int,int>>>> possibleMovements;

};