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
    virtual void updatePosition(int x, int y);

    //TODO ver si es virtual
    virtual std::shared_ptr<Sprite> getSprite();


protected:

    virtual bool positionExist(const std::pair<int, int>  &position);
    virtual std::pair<int, int> getUpPosition();
    virtual std::pair<int, int> getDownPosition();
    virtual std::pair<int, int> getLeftPosition();
    virtual std::pair<int, int> getRightPosition();
    virtual std::pair<int, int> getDiagonalUpLeft();
    virtual std::pair<int, int> getDiagonalUpRight();
    virtual std::pair<int, int> getDiagonalDownLeft();
    virtual std::pair<int, int> getDiagonalDownRight();
    Texture figureTexture;
    std::shared_ptr<Sprite> sprite{nullptr};
    std::pair<int, int> position;
    int size;
};