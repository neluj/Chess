#include "PossibleMovementsRenderizerSFML.hpp"

PossibleMovementsRenderizerSFML::PossibleMovementsRenderizerSFML(const std::vector<std::shared_ptr<std::pair<int,int>>> & possibleMovements) :
    possibleMovements(possibleMovements)
{
}

void PossibleMovementsRenderizerSFML::draw(RenderWindow & window)
{
    size_t elements_size = possibleMovements.size();
    sprites.clear();
    textures.clear();
    sprites.reserve(elements_size);
    textures.reserve(elements_size);
    for(auto possibleMovement : possibleMovements)
    {
        sprites.push_back(std::make_shared<sf::Sprite>());
        textures.push_back(std::make_shared<sf::Texture>());
        textures.back()->loadFromFile(IMAGE_PATH);
        sprites.back()->setTexture(*textures.back());
        sprites.back()->setPosition(IMAGE_SIZE * possibleMovement->first, IMAGE_SIZE * possibleMovement->second); 
        window.draw(*(sprites.back()));
    }
}
