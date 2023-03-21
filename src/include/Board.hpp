#pragma once

#include <memory>
#include <vector>
#include <list>

namespace chess
{


class Figure;
class State;
class Player;

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
    void setInitialState();
   
    const std::vector<std::shared_ptr<Figure>> & getFigures() const;
    std::shared_ptr<Figure> getFigureFromPosition(std::shared_ptr<const std::pair<int,int>> & position) const;
    State* getState();
    const std::shared_ptr<const Figure> getSelectedFigure();
    void updateState(State* newState);
    void updateTurnPlayer();
    std::shared_ptr<const Player> getTurnPlayer();
    void selectFigure(std::shared_ptr<Figure> figure);
    void unselectFigure();
    void moveSelectedFigure(std::shared_ptr<const std::pair<int,int>> & clickedPosition);
    const std::shared_ptr<std::list<std::shared_ptr<const std::pair<int,int>>>> getPossibleMovements() const;
    bool captureFigure(std::shared_ptr<const std::pair<int,int>> & clickedPosition);


    size_t getFigureIndexOnBoard(const std::shared_ptr< Figure> & figureHero, const std::vector<std::shared_ptr<Figure>> & figuresSpot) const;
    bool isChecked(const std::shared_ptr<const Player> & player) const;
    bool isChecked(const std::shared_ptr<Figure> & figureHero, const std::vector<std::shared_ptr<Figure>> & figuresSpot) const;
    bool isCheckMateded(const std::shared_ptr<const Player> & player) const;
    bool isCheckMateded(const std::shared_ptr<Figure> & figureHero, const std::vector<std::shared_ptr<Figure>> & figuresSpot) const;




    
private:

    std::vector<std::vector<std::shared_ptr<Figure>>> hipoteticBoardSpots(const std::shared_ptr<Figure> & figureToCalculate, const std::vector<std::shared_ptr<Figure>> & figuresSpot ) const;
    const std::shared_ptr<Figure> getPlayersKing(const std::shared_ptr<const Player> & player, const std::vector<std::shared_ptr<Figure>> figuresSpot) const;
 
    std::vector<std::shared_ptr<Figure>> figures;
    State* state{nullptr};
    std::shared_ptr<Figure> selectedFigure{nullptr};
    std::shared_ptr<std::list<std::shared_ptr<const std::pair<int,int>>>>  possibleMovements; 
    std::shared_ptr<const Player> turnPlayer{nullptr};

    std::shared_ptr<Player> playerWhite{nullptr};
    std::shared_ptr<Player> playerBlack{nullptr};



};

}