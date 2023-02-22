#include "Figure.hpp"

Figure::Figure(const Color & color, const Type & type, const std::pair<int, int> & pos) :
    position(pos), 
    color(color),
    type(type)
{  
    updatePosition(position.first, position.second);    
}

void Figure::updatePosition(int x, int y)
{
    position = std::pair<int, int>(x,y);
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