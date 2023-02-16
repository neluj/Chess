#include <vector>
#include <utility>
#include <memory>

class King;
class Figure;
class MovementsSides;
class MovementsUpDown;
class MovementsDiagonal;

class MovementsKing
{
public:
    MovementsKing();
    std::vector<std::pair<int,int>> getMovements(const std::shared_ptr<King> king, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);

private:

    pushPosition();

    std::shared_ptr<MovementsSides> movementsSides;
    std::shared_ptr<MovementsUpDown> movementsUpDown;
    std::shared_ptr<MovementsDiagonal> movementsDiagonal;

};