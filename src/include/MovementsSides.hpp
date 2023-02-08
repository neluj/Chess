#pragma once
#include <utility>
#include <memory>
#include <vector>
#include "Figure.hpp"



class MovementsSides
{
public:

    //Returns figure if the movements ends withempassant
    std::shared_ptr<Figure> getUpPosition       (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition);
    std::shared_ptr<Figure> getDownPosition     (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition);
    std::shared_ptr<Figure> getLeftPosition     (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition);
    std::shared_ptr<Figure> getRightPosition    (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition);
    bool positionExist(const std::pair<int, int>  &position);   
    std::shared_ptr<Figure> getFigureOnPosition(const std::pair<int, int> & position, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);

private:
    std::shared_ptr<Figure> returnNullValue(std::pair<int,int> & newPosition);
    std::shared_ptr<Figure> checkPositionState(const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, const std::pair<int,int> & calculatedPosition, std::pair<int,int> & newPosition);
};