#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

const int           IMAGE_SIZE = 64;
const std::string   IMAGE_PATH = "images/figures.png";

class Figure;

class FigureImage
{
public:
    FigureImage(const std::shared_ptr<Figure> figure);

private:
    std::shared_ptr<Figure> figure{nullptr};
    std::shared_ptr<sf::Sprite> sprite{nullptr};
    std::shared_ptr<sf::Texture> texture{nullptr};
};