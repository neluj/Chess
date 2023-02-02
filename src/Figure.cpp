#include "Figure.hpp"

Figure::Figure(Color col, Type type, const std::pair<int, int> & pos)
{
    position = pos;
    size = 64;
    figureTexture.loadFromFile("images/figures.png");
    sprite = std::make_shared<Sprite>();
    sprite->setTexture(figureTexture);
    sprite->setTextureRect(IntRect(size * type , size * col, size, size));   
    updatePosition(position.first, position.second);    
}

std::shared_ptr<Sprite> Figure::getSprite()
{
    return sprite;
}

void Figure::updatePosition(int x, int y)
{
    position = std::pair<int, int>(x,y);
    sprite->setPosition(size * position.first, size * position.second); 
}

bool Figure::positionExist(const std::pair<int, int>  &position)
{
    //Chek if some of the points is bigger than 7 or smaller than 0
    if((position.first || position.second)>7 || (position.first || position.second)<0)
        return false;
    return true;
}

std::pair<int, int> Figure::getUpPosition()
{
    std::pair<int, int> upPosition(position.first-1, position.second);
    if(!positionExist(upPosition))
        return std::pair<int, int>(-1,-1);
    return upPosition;
}
std::pair<int, int> Figure::getDownPosition()
{
    std::pair<int, int> downPosition(position.first+1, position.second);
    if(!positionExist(downPosition))
        return std::pair<int, int>(-1,-1);
    return downPosition;
}
std::pair<int, int> Figure::getLeftPosition()
{
    std::pair<int, int> leftPosition(position.first, position.second-1);
    if(!positionExist(leftPosition))
        return std::pair<int, int>(-1,-1);
    return leftPosition;
}
std::pair<int, int> Figure::getRightPosition()
{
    std::pair<int, int> rightPosition(position.first, position.second+1);
    if(!positionExist(rightPosition))
        return std::pair<int, int>(-1,-1);
    return rightPosition;
}
std::pair<int, int> Figure::getDiagonalUpLeft()
{
    std::pair<int, int> upLeftPosition(getUpPosition().second, getLeftPosition().first);
    if(!positionExist(upLeftPosition))
        return std::pair<int, int>(-1,-1);
    return upLeftPosition;
}
std::pair<int, int> Figure::getDiagonalUpRight()
{
    std::pair<int, int> upRightPosition(getUpPosition().second, getRightPosition().first);
    if(!positionExist(upRightPosition))
        return std::pair<int, int>(-1,-1);
    return upRightPosition;
}
std::pair<int, int> Figure::getDiagonalDownLeft()
{
    std::pair<int, int> downLeftPosition(getDownPosition().second, getLeftPosition().first);
    if(!positionExist(downLeftPosition))
        return std::pair<int, int>(-1,-1);
    return downLeftPosition;
}
std::pair<int, int> Figure::getDiagonalDownRight()
{
    std::pair<int, int> downRightPosition(getDownPosition().second, getRightPosition().first);
    if(!positionExist(downRightPosition))
        return std::pair<int, int>(-1,-1);
    return downRightPosition;
}