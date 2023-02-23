#pragma once

#include "Movements.hpp"

class MovementsUpDown;
class MovementsPositionState;
class MovementsDiagonal;


class MovementsPawn : public Movements
{
public:
    MovementsPawn();
    //Returns figure if the movements ends withempassant
    virtual std::vector<std::pair<int,int>> getMovements(const std::shared_ptr<Figure> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard) override;
private:

    // TODO captura al paso       
    // TODO depending on return, could be last (to take queen) or no possible movements. For now, empty vector. Maby -1,-1 on the end?
    std::vector<std::pair<int,int>> getWhiteMovements
    (const std::shared_ptr<Figure> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);

    std::vector<std::pair<int,int>> getBlackMovements
    (const std::shared_ptr<Figure> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
    
    std::vector<std::pair<int,int>> getWhiteDiagonals
    (const std::shared_ptr<Figure> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
    
    std::vector<std::pair<int,int>> getBlackDiagonals
    (const std::shared_ptr<Figure> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);
    
    std::vector<std::pair<int,int>> getWhiteFronts
    (const std::shared_ptr<Figure> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);

    std::vector<std::pair<int,int>> getBlackFronts
    (const std::shared_ptr<Figure> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);

    bool isWhiteInitialPosition(const std::pair<int,int> &position);
    bool isBlackInitialPosition(const std::pair<int,int> &position);

    std::vector<std::pair<int,int>> getFrontPositions
    (bool               (MovementsPawn::*isInitialPosition)(const std::pair<int,int> &),
    std::pair<int,int>  (MovementsUpDown::*frontMovement  )(const std::pair<int,int> &), 
    const std::shared_ptr<Figure> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);

    std::vector<std::pair<int,int>> getDiagonalsPositions
    (std::pair<int,int>  (MovementsDiagonal::*diagonalLeft   )(const std::pair<int,int>&), 
     std::pair<int,int>  (MovementsDiagonal::*diagonalRight  )(const std::pair<int,int>&), 
     const std::shared_ptr<Figure> pawn, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);

    // TODO pasar por parametro desde el metodo principal
    std::shared_ptr<MovementsUpDown> movementsUpDown;
    std::shared_ptr<MovementsPositionState> movementsPositionState;
    std::shared_ptr<MovementsDiagonal> movementsDiagonal;

};