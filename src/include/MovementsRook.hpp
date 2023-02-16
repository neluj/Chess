#include <vector>
#include <utility>
#include <memory>

class Rook;
class Figure;
class MovementsSides;
class MovementsUpDown;

class MovementsRook
{
public:
    MovementsRook();
    std::vector<std::pair<int,int>> getMovements(const std::shared_ptr<Rook> rook, const std::vector<std::shared_ptr<Figure>> & figuresOnBoard);

private:

    std::shared_ptr<MovementsSides> movementsSides;
    std::shared_ptr<MovementsUpDown> movementsUpDown;
};