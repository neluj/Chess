#include "Figure.hpp"

Figure::Figure(Color col, Type tp, const std::pair<int, int> & pos) :
    position(pos), color(col)
{
    size = 64;
    type =tp;
    figureTexture.loadFromFile("images/figures.png");
    sprite = std::make_shared<Sprite>();
    sprite->setTexture(figureTexture);
    sprite->setTextureRect(IntRect(size * type , size * color, size, size));   
    updatePosition(position.first, position.second);    
}

std::shared_ptr<Sprite> Figure::getSprite() const
{
    return sprite;
}

void Figure::updatePosition(int x, int y)
{
    position = std::pair<int, int>(x,y);
    sprite->setPosition(size * position.first, size * position.second); 
}

std::pair<int, int> Figure::getPosition() const
{
    return position;
}

Figure::Type Figure::getType() const
{
    return type;
}
Figure::Color Figure::getColor() const
{
    return color;
}