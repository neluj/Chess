add_library(src
Game.cpp
Board.cpp
FigureRenderizerSFML.cpp
PossibleMovementsRenderizerSFML.cpp
Figure.cpp
Rook.cpp
Pawn.cpp
King.cpp
Knight.cpp
Queen.cpp
Bishop.cpp
MovementsSides.cpp
MovementsUpDown.cpp
MovementsPositionState.cpp
MovementsDiagonal.cpp
MovementsKnight.cpp
MovementsPawn.cpp
MovementsQueen.cpp
MovementsRook.cpp
MovementsBishop.cpp
MovementsKing.cpp
State.cpp
StateNothingSelected.cpp
StateFigureSelected.cpp)

target_link_libraries( src PUBLIC ${CONAN_LIBS})

file(COPY
images
DESTINATION ${CMAKE_BINARY_DIR})

target_include_directories(src PUBLIC include ) 
