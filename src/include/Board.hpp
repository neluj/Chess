#pragma once

#include "King.hpp"
#include "Rook.hpp"
#include "Pawn.hpp"
#include "Knight.hpp"
#include "Queen.hpp"
#include "Bishop.hpp"

#include <vector>

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

};