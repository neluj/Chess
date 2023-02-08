#pragma once
#include <vector>
#include "MovementsPositionState.hpp"


class MovementsSides
{
public:
    //Returns figure if the movements ends withempassant
    std::shared_ptr<Figure> getUpPosition       (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition);
    std::shared_ptr<Figure> getDownPosition     (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition);
    std::shared_ptr<Figure> getLeftPosition     (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition);
    std::shared_ptr<Figure> getRightPosition    (const std::shared_ptr<Figure> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard, std::pair<int,int> & newPosition);
private:
    MovementsPositionState positionState;
};