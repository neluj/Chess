#include "Figure.hpp"

Figure::Figure(Color color, Type type, const std::pair<int, int> & pos)
{
    position = pos;
    int size = 64;
    figureTexture.loadFromFile("images/figures.png");
    sprite = std::make_shared<Sprite>();
    sprite->setTexture(figureTexture);
    sprite->setTextureRect(IntRect(size * type , size * color, size, size));   
    sprite->setPosition(size * pos.first, size * pos.second);    
}

std::shared_ptr<Sprite> Figure::getSprite()
{
    return sprite;
}