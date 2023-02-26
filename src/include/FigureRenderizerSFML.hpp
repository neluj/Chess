#pragma once
#include <memory>
#include "RenderizerSFML.hpp"

class Figure;

class FigureRenderizerSFML : public RenderizerSFML
{
public:

    FigureRenderizerSFML(const std::vector<std::shared_ptr<Figure>> & figures);
    void draw(RenderWindow & window) override;

private:

    // TODO hacer con unordered map sprites-figures
    const int           IMAGE_SIZE = 64;
    const std::string   IMAGE_PATH = "images/figures.png";

    const std::vector<std::shared_ptr<Figure>> figures;

};