#include "FigureRenderizer.hpp"
#include "FigureImage.hpp"
#include "Board.hpp"

FigureRenderizer::FigureRenderizer(const std::shared_ptr<Board> board)
{
    figureImages.reserve(board->getFigures().size());
    for(auto fig : board->getFigures())
    {
        auto figureImage = std::make_shared<FigureImage>(fig);
        figureImages.push_back(figureImage);
    }
}

void FigureRenderizer::draw(RenderWindow & window)
{
    for(auto figImag : figureImages)
    {
        window.draw(*figImag->getSprite());
    }
}
