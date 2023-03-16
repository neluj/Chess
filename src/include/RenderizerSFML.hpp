#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

using namespace sf;

namespace chess
{

class RenderizerSFML 
{

public:
      virtual ~RenderizerSFML(){}
      virtual void draw(RenderWindow & window) = 0;

protected:

    std::vector<std::shared_ptr<Sprite>> sprites;
    std::vector<std::shared_ptr<Texture>> textures;

};

}

