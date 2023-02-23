#include "Figure.hpp"

Figure::Figure(const Color & color, const Type & type, const std::pair<int, int> & pos, std::shared_ptr<Movements> movements) :
    position(pos), 
    color(color),
    type(type),
    movements(movements)
{  
    updatePosition(position.first, position.second);    
}

std::vector<std::pair<int, int>> Figure::getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard)
{
    return movements->getMovements(shared_from_this(), figuresOnBoard);
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