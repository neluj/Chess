#include "FigureRenderizerSFML.hpp"
#include "Figure.hpp"
    
    
FigureRenderizerSFML::FigureRenderizerSFML(const std::vector<std::shared_ptr<Figure>> & figures) :
    figures(figures)
{
    size_t elements_size = figures.size();
    sprites.reserve(elements_size);
    textures.reserve(elements_size);
    for(auto figure : figures)
    {
        sprites.push_back(std::make_shared<sf::Sprite>());
        textures.push_back(std::make_shared<sf::Texture>());
        textures.back()->loadFromFile(IMAGE_PATH);
        sprites.back()->setTexture(*textures.back());
        sprites.back()->setTextureRect(sf::IntRect(IMAGE_SIZE * figure->getType() , IMAGE_SIZE * figure->getColor(), IMAGE_SIZE, IMAGE_SIZE)); 
        sprites.back()->setPosition(IMAGE_SIZE * figure->getPosition().first, IMAGE_SIZE * figure->getPosition().second); 
    }

}
    
void FigureRenderizerSFML::draw(RenderWindow & window)
{
    size_t renders = figures.size() < sprites.size() ? figures.size()  : sprites.size();
    for(size_t ind = 0; ind < renders ; ++ind)
    {
        sprites.at(ind)->setPosition(IMAGE_SIZE * figures.at(ind)->getPosition().first, IMAGE_SIZE * figures.at(ind)->getPosition().second); 
        window.draw(*(sprites.at(ind)));
    }
}
