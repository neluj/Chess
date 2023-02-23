#pragma once

#include <memory>
#include <vector>


class MovementsKing;
class MovementsRook;
class MovementsPawn;
class MovementsKnight;
class MovementsQueen;
class MovementsBishop;

class Figure;

class Board 
{

public:
    Board();

    //r, n, b, q, k, b, n, r
    //p, p, p, p, p, p, p, p
    //e, e, e, e, e, e, e, e
    //e, e, e, e, e, e, e, e
    //e, e, e, e, e, e, e, e
    //e, e, e, e, e, e, e, e
    //P, P, P, P, P, P, P, P
    //R, N, B, Q, K, B, N, R   
    void setInitialState();
    const std::vector<std::shared_ptr<Figure>> & getFigures() const;
    
private:
 
    std::vector<std::shared_ptr<Figure>> figures; 

    std::shared_ptr<MovementsKing   >movementsKing{nullptr};
    std::shared_ptr<MovementsRook   >movementsRook{nullptr};
    std::shared_ptr<MovementsPawn   >movementsPawn{nullptr};
    std::shared_ptr<MovementsKnight >movementsKnight{nullptr};
    std::shared_ptr<MovementsQueen  >movementsQueen{nullptr};
    std::shared_ptr<MovementsBishop >movementsBishop{nullptr};

};

