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
    //virtual std::vector<std::pair<int, int>> getPossibleMovements() = 0;

    //TODO ver si es virtual
    virtual std::shared_ptr<Sprite> getSprite();

protected:

    Texture figureTexture;
    std::shared_ptr<Sprite> sprite{nullptr};
    std::pair<int, int> position;
    int size;
};