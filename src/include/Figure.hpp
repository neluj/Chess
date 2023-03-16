#pragma once
#include <utility>
#include <memory>
#include <vector>

namespace chess
{

class Figure : public std::enable_shared_from_this<Figure>
{
public:

	enum Color { BLACK, WHITE};

    enum Type { ROOK, KNIGHT, BISHOP, QUEEN, KING, PAWN };

    Figure(const Color & color,const Type & type, const std::shared_ptr<std::pair<int, int>> & pos);
    virtual ~Figure(){}
    virtual std::vector<std::shared_ptr<std::pair<int,int>>> getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) = 0;
    virtual std::shared_ptr<Figure> clone() const = 0;
    virtual void updatePosition(int x, int y);
    virtual const std::shared_ptr<const std::pair<int, int>> getPosition() const;
    virtual Type getType() const;
    virtual Color getColor() const;


protected:

    std::shared_ptr<std::pair<int, int>> position;
    const Color color;
    Type type;

};

}