#pragma once
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace sf;

class FigureImage;
class Board;

class FigureRenderizer 
{
public:
    FigureRenderizer(const std::shared_ptr<Board> board);
    void draw(RenderWindow & window);

private:

    std::vector<std::shared_ptr<FigureImage>> figureImages; 

};