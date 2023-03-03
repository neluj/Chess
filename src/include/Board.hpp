#pragma once

#include <memory>
#include <vector>


class Figure;
// TODO
class State;

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
    std::shared_ptr<Figure> getFigureFromPosition(const std::shared_ptr<std::pair<int,int>> & position) const;
    const std::vector<std::shared_ptr<std::pair<int,int>>> getPossibleMovements() const;
    // TODO
    const std::shared_ptr<State> getState();
    void selectFigure(std::shared_ptr<Figure> figure);
    void unselectFigure();
    void moveSelectedFigure(const std::pair<int,int> & position);

    
private:
 
    std::vector<std::shared_ptr<Figure>> figures;
    std::vector<std::shared_ptr<std::pair<int,int>>> possibleMovements; 

    // TODO
    std::shared_ptr<State> state;
    std::shared_ptr<Figure> selectedFigure{nullptr};

};