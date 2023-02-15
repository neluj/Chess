#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <utility>

using namespace sf;
class Figure
{
public:

	enum Color { BLACK, WHITE};

    enum Type { ROOK, KNIGHT, BISHOP, QUEEN, KING, PAWN };

    Figure(const Color & color,const Type & type, const std::pair<int, int> & pos);
    virtual ~Figure(){}
    //virtual std::vector<std::pair<int, int>> getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) const = 0;
    virtual std::shared_ptr<Figure> clone() const = 0;
    virtual void updatePosition(int x, int y);
    virtual std::pair<int, int> getPosition() const;
    virtual Type getType() const;
    virtual Color getColor() const;
    virtual std::shared_ptr<Sprite> getSprite() const;


protected:

    Texture figureTexture;
    std::shared_ptr<Sprite> sprite{nullptr};
    std::pair<int, int> position;
    // TODO sprite type guardar de otra manera
    int size;
    const Color color;
    Type type;
};