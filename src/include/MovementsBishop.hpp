#include <vector>
#include <utility>
#include <memory>

class Bishop;
class Figure;
class MovementsDiagonal;

class MovementsBishop
{
public:
    MovementsBishop();
    std::vector<std::pair<int,int>> getMovements(const std::shared_ptr<Bishop> bishop, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);

private:

    std::shared_ptr<MovementsDiagonal> movementsDiagonal;

};