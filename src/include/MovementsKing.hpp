#include <vector>
#include <utility>
#include <memory>

class King;
class Figure;
class MovementsSides;
class MovementsUpDown;
class MovementsDiagonal;
class MovementsPositionState;

class MovementsKing
{
public:
    MovementsKing();
    std::vector<std::pair<int,int>> getMovements(const std::shared_ptr<King> king, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);

private:

    void pushPosition(std::vector<std::pair<int,int>> & movements, const std::pair<int,int> & newPosition, const std::shared_ptr<King> figure, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);

    std::shared_ptr<MovementsSides> movementsSides;
    std::shared_ptr<MovementsUpDown> movementsUpDown;
    std::shared_ptr<MovementsDiagonal> movementsDiagonal;
    std::shared_ptr<MovementsPositionState> movementsPositionState;


};