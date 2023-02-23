#pragma once
#include "Movements.hpp"

class Figure 
{
public:

	enum Color { BLACK, WHITE};

    enum Type { ROOK, KNIGHT, BISHOP, QUEEN, KING, PAWN };

    Figure(const Color & color,const Type & type, const std::pair<int, int> & pos);
    virtual ~Figure(){}
    virtual std::vector<std::pair<int, int>> getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
    virtual std::shared_ptr<Figure> clone() const = 0;
    virtual void updatePosition(int x, int y);
    virtual std::pair<int, int> getPosition() const;
    virtual Type getType() const;
    virtual Color getColor() const;


protected:

    std::pair<int, int> position;
    const Color color;
    Type type;
    std::shared_ptr<Movements> movemets;

};