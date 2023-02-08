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

    Figure(Color color, Type type, const std::pair<int, int> & pos);
    virtual ~Figure(){}
    //virtual std::vector<std::pair<int, int>> getPossibleMovements(const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) = 0;
    virtual void updatePosition(int x, int y);
    virtual std::pair<int, int> getPosition();
    virtual Type getType();
    virtual Color getColor();

    //TODO ver si es virtual
    virtual std::shared_ptr<Sprite> getSprite();


protected:

    Texture figureTexture;
    std::shared_ptr<Sprite> sprite{nullptr};
    std::pair<int, int> position;
    // TODO sprite type guardar de otra manera
    int size;
    const Color color;
    Type type;
};