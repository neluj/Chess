#include "FigureImage.hpp"
#include "Figure.hpp"

FigureImage::FigureImage(const std::shared_ptr<Figure> figure) :
    figure(figure)
{
    sprite = std::make_shared<sf::Sprite>();
    texture = std::make_shared<sf::Texture>();
    texture->loadFromFile(IMAGE_PATH);
    sprite->setTexture(*texture);
    sprite->setTextureRect(IntRect(IMAGE_SIZE * figure->getType() , IMAGE_SIZE * figure->getColor(), IMAGE_SIZE, IMAGE_SIZE)); 
    sprite->setPosition(IMAGE_SIZE * figure->getPosition().first, IMAGE_SIZE * figure->getPosition().second); 
}
