#include <vector>
#include <utility>
#include <memory>

class Queen;
class Figure;
class MovementsSides;
class MovementsUpDown;
class MovementsDiagonal;

class MovementsQueen
{
public:
    MovementsQueen();
    std::vector<std::pair<int,int>> getMovements(const std::shared_ptr<Queen> queen, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);

private:

    std::shared_ptr<MovementsSides> movementsSides;
    std::shared_ptr<MovementsUpDown> movementsUpDown;
    std::shared_ptr<MovementsDiagonal> movementsDiagonal;

};