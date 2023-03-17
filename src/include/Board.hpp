#pragma once

#include <memory>
#include <vector>
#include <list>

namespace chess
{


class Figure;
// TODO
class State;

class Board 
{

public:
    Board(State* newState);
    ~Board();

    //r, n, b, q, k, b, n, r
    //p, p, p, p, p, p, p, p
    //e, e, e, e, e, e, e, e
    //e, e, e, e, e, e, e, e
    //e, e, e, e, e, e, e, e
    //e, e, e, e, e, e, e, e
    //P, P, P, P, P, P, P, P
    //R, N, B, Q, K, B, N, R   
    void setInitialState(State* newState);
   
    const std::vector<std::shared_ptr<Figure>> & getFigures() const;
    std::shared_ptr<Figure> getFigureFromPosition(std::shared_ptr<const std::pair<int,int>> & position) const;
    // TODO
    State* getState();
    const std::shared_ptr<const Figure> getSelectedFigure();
    void updateState(State* newState);
    void selectFigure(std::shared_ptr<Figure> figure);
    void unselectFigure();
    void moveSelectedFigure(std::shared_ptr<const std::pair<int,int>> & clickedPosition);
    const std::shared_ptr<std::list<std::shared_ptr<const std::pair<int,int>>>> getPossibleMovements() const;


    
private:
 
    std::vector<std::shared_ptr<Figure>> figures;


    // TODO
    State* state{nullptr};
    std::shared_ptr<Figure> selectedFigure{nullptr};
    std::shared_ptr<std::list<std::shared_ptr<const std::pair<int,int>>>>  possibleMovements; 

};

}